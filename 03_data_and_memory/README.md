# 03 — Data and memory

This section introduces the low-level vocabulary that helps you understand C++ code, but it also teaches the modern default: use `std::vector` and RAII rather than manually owning dynamic memory.

Raw pointers express an address or an optional non-owning view. They do **not** automatically manage the lifetime of an object. A reference is an alias and must always refer to an existing object.
