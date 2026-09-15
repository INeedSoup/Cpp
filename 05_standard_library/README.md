# 05 — The standard library

## Goal

Prefer standard-library containers and algorithms over handwritten low-level machinery. The library is part of modern C++, not an optional extra.

| Lesson | What and why | Use it when | Watch out for |
| --- | --- | --- | --- |
| 01 Containers | Containers choose how data is stored and accessed. | Starting any collection of values. | Start with `vector`; choose another container for a concrete reason. |
| 02 Associative containers | Sets store unique keys; maps associate keys with values. | Membership tests, lookups, and frequency counts. | `map::at` throws for a missing key; `operator[]` can insert one. |
| 03 Algorithms and lambdas | Algorithms express intent; lambdas provide small local rules. | Sorting, searching, filtering, transforming, or summing. | Know iterator invalidation after changing a container. |
| 04 Files and exceptions | Streams read/write files; exceptions report failures that cannot be handled locally. | Persistent data and operations that can fail. | File paths are relative to the program's working directory. |
| 05 RAII and smart pointers | Ownership is tied to an object's lifetime. | Managing files, locks, and heap-owned objects. | Default to automatic objects and `unique_ptr`; use `shared_ptr` sparingly. |
| 06 Optional and variant | `optional` represents a missing result; `variant` represents one of known alternatives. | A function has a valid “no result” case or several result types. | Do not use exceptions for ordinary expected absence. |
| 07 Multi-file example | Headers declare an interface; `.cpp` files implement it. | A program grows beyond one source file. | Compile and link every implementation file. |
| 08–09 STL references | Extended container and algorithm reference material. | Looking up a tool after learning the focused lessons. | Read selectively; these are reference files, not the first route through STL. |

## Practice checkpoint

Read words from a file, count them with `unordered_map`, and print the five most frequent words. Handle a missing file cleanly.
