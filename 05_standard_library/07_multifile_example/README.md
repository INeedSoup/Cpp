# Multi-file example

Large programs should not place every declaration and implementation in one source file.

- `ledger.h` is the header: it declares the public data type and function.
- `ledger.cpp` implements the declared function.
- `main.cpp` uses the public interface without knowing the implementation details.

Compile the files together:

```powershell
g++ -std=c++20 -Wall -Wextra -Wpedantic main.cpp ledger.cpp -o ledger_example.exe
```

The root CMake configuration also provides this as the `multi_file_example` target.
