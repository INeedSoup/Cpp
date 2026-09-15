# 04 — User-defined types

## Goal

Model data in a way that makes invalid states harder to create. Use simple types for simple data and classes when a type must protect rules about its own state.

| Lesson | What and why | Use it when | Watch out for |
| --- | --- | --- | --- |
| 01 Function templates | One generic definition can work with multiple compatible types. | The algorithm is identical for several types. | A template still needs the required operations, such as `<`. |
| 02 Structs | A `struct` groups related public data. | Plain records such as a coordinate or result. | Use a `class` when values need validation or protected invariants. |
| 03 Enums | `enum class` gives named, type-safe choices. | A value must be one of a fixed set. | Prefer `enum class` over unscoped `enum`. |
| 04 Classes and inheritance | Classes hide implementation and expose valid operations; inheritance models an “is-a” relationship. | A type owns behaviour and must enforce rules. | Do not use inheritance merely to reuse a few lines of code. |
| 05 Runtime polymorphism | A base interface lets one function work with different derived objects. | The exact behaviour is selected at runtime. | A polymorphic base class needs a virtual destructor. |

## Practice checkpoint

Create a `Rectangle` class that rejects negative dimensions, exposes `area()`, and cannot be put into an invalid state through public data.
