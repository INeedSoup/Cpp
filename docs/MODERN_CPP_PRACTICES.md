# Modern C++ practices used in this tutorial

Older C++ code is not automatically wrong. Many older forms still compile and are needed when reading existing projects. The practices below are the safer or clearer defaults used in the newer lessons, generally with C++17/C++20 as the baseline.

## 1. Brace initialization

```cpp
int age{};             // 0
double price{19.99};
std::string name{"Aman"};
```

Braces initialise a variable immediately. Empty braces value-initialise it, so `int age{};` starts as `0` rather than holding an uninitialised value. Braces also reject many narrowing conversions:

```cpp
int oldStyle = 3.8; // Allowed, but silently becomes 3.
int safer{3.8};     // Error: information would be lost.
```

Use braces for normal variable creation. You will see them from [01 hello and variables](../01_foundations/01_hello_and_variables.cpp) onward.

## 2. Initialise every variable and prefer `const`

```cpp
const int questions{10};
constexpr double pi{3.141592653589793};
```

`const` means the value cannot change through that name after creation. It documents intent and prevents accidental reassignment. `constexpr` is even stronger: the value can be computed at compile time when possible.

Use `const` by default, then remove it only if the value genuinely changes. Use `constexpr` for fixed compile-time facts such as constants and array sizes.

## 3. Use `\n` for ordinary new lines

```cpp
std::cout << "Done\n";
```

Older examples often use `std::endl`. Both start a new line, but `std::endl` also flushes the output buffer every time. Flushing is useful when output must appear immediately; otherwise `\n` is clearer and usually faster.

## 4. Keep standard-library names qualified

```cpp
std::cout << "Hello\n";
std::vector<int> values;
```

Avoid this in normal projects:

```cpp
using namespace std;
```

`std::` makes the origin of a name visible and avoids collisions with names in your own code or other libraries. The two large STL reference files keep the older style only because they were retained as reference material.

## 5. Prefer `using` over `typedef`

```cpp
using UserId = int;
using DisplayName = std::string;
```

This is easier to read than `typedef int UserId;` and works naturally with templates. An alias improves a name; it does not create a distinct type, so do not make aliases only for decoration.

## 6. Prefer explicit casts

```cpp
const double percentage = static_cast<double>(correct) / total * 100.0;
```

Prefer `static_cast<T>(value)` to C-style casts such as `(double)value`. It states the intended conversion clearly and is easier to search for in a code review. Most conversions should be avoided unless they are needed and understood.

## 7. Prefer `nullptr` to `NULL` or `0` for pointers

```cpp
int* optionalNumber = nullptr;
```

`nullptr` means “does not point to an object” and has its own type. It avoids overload ambiguities that can arise when old code uses `0` or `NULL` as a null pointer.

## 8. Use `std::string`, `std::array`, and `std::vector`

```cpp
std::string name{"Aman"};
std::array<int, 3> scores{90, 84, 76};
std::vector<int> growingScores{90, 84};
```

These types own their data and know their size. Prefer:

- `std::string` for text;
- `std::array` for a fixed-size collection;
- `std::vector` for a dynamically sized collection.

They are safer and more expressive than raw character arrays, built-in arrays, and manual `new[]`/`delete[]` in most application code.

## 9. Range-based loops and `auto`

```cpp
for (const std::string& student : students)
{
    std::cout << student << '\n';
}

for (const auto& row : cars)
{
    // auto uses the type supplied by cars.
}
```

Use a range-based loop when you need every element in order and do not need an index. `auto` asks the compiler to deduce an obvious type; use it when the type is already clear from the right side or would be noisy to write. Do not use `auto` when it hides an important type from a learner or reader.

`const auto&` is a common read-only loop form: it avoids copying a potentially large element and prevents modification.

## 10. `const` references for read-only parameters

```cpp
void printInfo(const std::string& name);
```

Passing `std::string name` copies the string. Passing `const std::string& name` borrows the caller's string without copying and promises not to change it. Use it for read-only objects that may be expensive to copy. Small values such as `int`, `double`, and `char` are usually passed by value.

## 11. Modern randomness

```cpp
std::mt19937 engine(std::random_device{}());
std::uniform_int_distribution<int> die(1, 6);
const int roll = die(engine);
```

Prefer `<random>` to `rand()` and `srand()`. A random engine produces a sequence; a distribution states the required range and shape. Create and seed the engine once, then reuse it. This is clearer, more flexible, and has better statistical properties.

## 12. `enum class` for named states

```cpp
enum class Day { monday, tuesday, wednesday };
const Day today{Day::monday};
```

`enum class` is scoped and type-safe. `Day::monday` cannot silently mix with an integer or another enum type, unlike an old unscoped `enum`.

## 13. Use standard algorithms and lambdas

```cpp
std::ranges::sort(values);
values.erase(std::remove_if(values.begin(), values.end(),
                            [](int value) { return value % 2 == 0; }),
             values.end());
```

Algorithms express *what* should happen—sort, find, count, remove—rather than making every loop manually. A lambda is a small unnamed function written where it is used. Prefer algorithms when they make the intention clearer than a custom loop.

The erase-remove pattern is important: `remove_if` rearranges values but does not shrink a vector; `erase` actually removes the unwanted tail.

## 14. C++20 conveniences: `contains`, ranges, and digit separators

```cpp
if (seen.contains("blue")) { /* ... */ }
std::ranges::sort(values);
const int population{1'200};
```

`contains` reads more naturally than comparing `find` with `end`. The `std::ranges` versions of algorithms often work cleanly with containers. A quote in a number is only a visual separator, so `1'200` means `1200`.

These require the tutorial's C++20 compiler setting.

## 15. RAII and smart pointers

```cpp
auto number = std::make_unique<int>(42);
```

RAII means resource acquisition is tied to object lifetime. When an automatic object leaves scope, its destructor releases its resource. `std::unique_ptr` owns one heap object and deletes it automatically. Prefer it over raw `new` and `delete` when heap allocation is genuinely needed.

Use `std::shared_ptr` only when several owners are genuinely required. It has extra cost and can leak through ownership cycles; it is not the default replacement for every pointer.

## 16. Classes that protect their own rules

```cpp
class BankAccount
{
public:
    void deposit(double amount);
    [[nodiscard]] double balance() const;

private:
    double balance_{};
};
```

Keep data private when outside code should not freely create invalid state. The public functions form the type's interface. A trailing underscore is a common naming convention for data members; it is a convention, not a language rule.

`[[nodiscard]]` asks the compiler to warn when a meaningful return value is ignored. A member function ending in `const` promises it does not modify the object's observable state.

## 17. Constructor initializer lists and `std::move`

```cpp
BankAccount(std::string owner, double openingBalance)
    : owner_(std::move(owner)), balance_(openingBalance)
{
}
```

An initializer list constructs members directly before the constructor body runs. `std::move` permits the string's resources to be transferred into `owner_` rather than copied. This is useful when the parameter is a value the class is taking ownership of. It does not itself move anything; it enables move-aware operations.

## 18. Safer polymorphism syntax

```cpp
class Animal
{
public:
    virtual ~Animal() = default;
    virtual std::string sound() const = 0;
};

class Dog final : public Animal
{
public:
    std::string sound() const override;
};
```

`virtual` enables runtime dispatch through a base reference or pointer. A virtual destructor is required when derived objects may be destroyed through a base pointer. `override` asks the compiler to confirm that a function really overrides a base function. `final` prevents further inheritance or overriding when that is intentional.

## 19. `optional` and `variant`

```cpp
std::optional<int> findScore();
std::variant<int, std::string> result;
```

Use `optional<T>` when a result may validly be missing. Check it before using `*value`. Use `variant<A, B>` when a value is exactly one of a known set of types. Both make alternatives explicit in the type system instead of using magic values such as `-1` or unclear flags.

## 20. Headers and `#pragma once`

```cpp
#pragma once
```

A header declares types and functions that several source files can use. `#pragma once` prevents the same header from being included more than once in one compilation unit. The multi-file example separates the public declaration in `ledger.h` from the implementation in `ledger.cpp`.

## A practical default checklist

For new tutorial programs, start with this mindset:

1. Initialise every variable, usually with braces.
2. Mark values and member functions `const` when they should not change.
3. Prefer standard-library containers, algorithms, and strings.
4. Validate external input before using it.
5. Avoid raw ownership with `new`/`delete`; use automatic objects, `vector`, or `unique_ptr`.
6. Compile with warnings enabled and understand every warning.
7. Choose the clearest code first; “modern” should improve clarity and safety, not add fashionable syntax unnecessarily.
