# 05 — The standard library

The standard library is the normal starting point for containers, algorithms, ownership, and I/O. The two larger STL reference files are retained as an extended reference; the numbered lessons provide a shorter, ordered route through their most useful ideas.

When choosing a container, start with `std::vector` unless you have a concrete reason for another choice. Prefer algorithms such as `std::sort`, `std::find_if`, and `std::accumulate` to rewriting them by hand.
