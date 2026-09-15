# C++ from Fundamentals to Intermediate

This repository is a practical, modern C++20 tutorial. Each `.cpp` file is a small, independent program: read its comments, predict the result, compile it, then change it. The numbered folders are the intended study order; within a folder, follow the filenames in numeric order.

## Start here

Install a compiler with C++20 support (GCC, Clang, or MSVC). From the repository root, compile one lesson at a time:

```powershell
g++ -std=c++20 -Wall -Wextra -Wpedantic .\\01_foundations\\01_hello_and_variables.cpp -o lesson.exe
.\\lesson.exe
```

`CMakeLists.txt` is included for editors and CMake users. It builds every standalone lesson as a separate executable. The multi-file example has its own target, `multi_file_example`.

```powershell
cmake -S . -B build
cmake --build build
```

## Learning path

| Stage | What you will learn | Recommended outcome |
| --- | --- | --- |
| `01_foundations` | syntax, values, input, expressions, decisions, strings | write small interactive programs safely |
| `02_control_flow_and_functions` | loops, randomness, functions, scope, recursion | split a problem into reusable steps |
| `03_data_and_memory` | arrays, references, pointers, lifetime, dynamic storage | understand ownership and avoid common memory mistakes |
| `04_user_defined_types` | enums, structs, classes, templates, polymorphism | model data and behaviour clearly |
| `05_standard_library` | containers, algorithms, RAII, files, errors, utility types | prefer the standard library over manual low-level code |
| `06_projects` | complete console programs | apply several concepts in one program |

## How to use the examples well

1. Do not run all source files as one program: every lesson has its own `main` function.
2. Compile with warnings enabled. Warnings are part of the lesson, not noise.
3. Prefer `std::vector`, `std::string`, and smart pointers in new programs; raw arrays and `new`/`delete` are included so you can read older C++ and understand the trade-offs.
4. Keep generated binaries outside version control. The included `.gitignore` already excludes common build output.
5. Read each stage's README before its source files; it explains what a concept is, why it matters, where to use it, and its main pitfall.

The [learning method](docs/LEARNING_METHOD.md) explains how to turn the examples into practice rather than passive reading.

## Conventions used here

- C++20 is the baseline.
- Focused lessons avoid `using namespace std;` so the origin of names is visible. The two retained long-form STL references still use it and are best read as reference notes, not style templates.
- `const` means a value is not modified through that name.
- Comments explain *why* a choice matters; the program shows *how* it works.

## Next steps

The curriculum deliberately stops at a confident intermediate level. See [Future topics](FUTURE_TOPICS/README.md) for advanced subjects to add later.
