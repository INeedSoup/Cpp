# 03 — Data and memory

## Goal

Understand where values live, how functions share them, and why modern C++ avoids manual memory management when possible. Learn the terminology so that low-level C++ is readable without making it your default style.

| Lesson | What and why | Use it when | Watch out for |
| --- | --- | --- | --- |
| 01 Arrays | `std::array` stores a fixed number of same-type values with a safer interface than a built-in array. | The size is known at compile time. | Use `std::vector` when the size changes at runtime. |
| 02 Bubble sort | Sorting places values in an order; bubble sort demonstrates nested loops. | Learning algorithm mechanics only. | It is O(n²); use `std::sort` in real programs. |
| 03 Multidimensional arrays | A 2D array models rows and columns. | Grids, tables, and simple boards. | A built-in 2D array needs a compile-time column count. |
| 04 References and addresses | A reference aliases an object; an address identifies where an object lives. | Comparing pass-by-value with pass-by-reference. | Printed addresses are implementation details, not stable data. |
| 05 Const references | A `const &` avoids copying while preventing modification. | Passing strings, containers, and larger objects read-only. | Do not return a reference to a local variable. |
| 06 Pointers | A pointer stores an address and may be null. | Optional non-owning access and interoperating with lower-level APIs. | Never dereference null, dangling, or uninitialised pointers. |
| 07 Dynamic memory | RAII and smart pointers release owned resources automatically. | Ownership must outlive the creating scope. | Prefer automatic objects and `std::vector`; raw `new`/`delete` is rarely needed. |

## Practice checkpoint

Store five marks in `std::array`, calculate their average with a `const` reference parameter, and find the largest mark. Then rewrite it later with `std::vector`.
