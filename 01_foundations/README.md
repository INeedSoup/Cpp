# 01 — Foundations

## Goal

Learn how a C++ program stores values, receives input, makes decisions, and produces output. Finish this stage able to write a small, safe console program without copying code blindly.

## Before you begin

Read [the learning method](../docs/LEARNING_METHOD.md). Compile one program at a time, predict its output, then make one small change yourself.

| Lesson | What and why | Use it when | Watch out for |
| --- | --- | --- | --- |
| 01 Hello and variables | `main`, output, types, and named values are the building blocks of every program. | You need to store or display data. | Choosing a type that cannot represent the needed value. |
| 02 Namespaces | Namespaces prevent unrelated code from using the same name accidentally. | Writing reusable code or using the standard library. | Avoid `using namespace std;` in headers and large programs. |
| 03 Type aliases | `using` gives a type a clearer domain-specific name. | An alias improves meaning, such as `UserId`. | Do not rename ordinary types merely to make new jargon. |
| 04 Arithmetic and casts | Expressions calculate new values; casts control type conversion. | Scores, measurements, counters, and formulas. | Integer division discards fractions. |
| 05 Input and strings | `cin` reads formatted values; `getline` reads a whole line. | Building interactive programs. | A pending newline can make `getline` appear to skip input. |
| 06 Input validation | Streams remember failure; clear and discard bad input before retrying. | Every program that accepts user input. | Never use an invalid value after a failed read. |
| 07 Hypotenuse calculator | A short program can combine input, arithmetic, and output. | Applying a known formula. | Validate real-world constraints, such as non-negative lengths. |
| 08 Conditionals | A condition selects one path through a program. | Rules, menus, and validation. | Put exceptional/narrow cases before broad cases. |
| 09 Calculator | `switch` is clear when one value selects a fixed set of actions. | Operators, commands, and menus. | Division by zero must be rejected. |
| 10 Temperature converter | The same decision structure can select a conversion formula. | Unit conversion. | Normalise or explicitly accept upper/lowercase input. |
| 11 String operations | `std::string` safely owns text and exposes useful operations. | Names, messages, paths, and text processing. | Check an index before using `at()` or `[]`. |

## Practice checkpoint

Write a BMI calculator that validates height and weight, reports invalid input clearly, and labels the result using `if`/`else if`. Do not use a global variable.
