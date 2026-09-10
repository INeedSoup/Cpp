# 04 — User-defined types

Use an `enum class` for a closed set of named choices, a `struct` for simple grouped data, and a `class` when the type should protect an invariant. Classes should expose useful operations instead of making all data public.

The polymorphism lesson uses a virtual destructor: deleting a derived object through a base pointer without one is a serious bug.
