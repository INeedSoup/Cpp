# 02 — Control flow and functions

## Goal

Make programs repeat work deliberately and divide a problem into small, testable functions. A function should communicate its job through its name, parameters, return type, and comments—not through a long body.

| Lesson | What and why | Use it when | Watch out for |
| --- | --- | --- | --- |
| 01 Loops | `while`, `do`/`while`, and `for` repeat a block under different conditions. | Repeating until valid input, counting, or traversing data. | Ensure every loop has a believable stopping condition. |
| 02 Random numbers | `<random>` separates the random engine from the desired range. | Games, simulations, and sampling. | Seed an engine once; do not use old `rand()`. |
| 03 Functions and overloads | Functions isolate repeated work; overloads provide the same operation for different inputs. | A task has a meaningful name or repeats. | Prefer small functions and avoid copying large arguments. |
| 04 Scope | A name is usable only inside its scope; globals are visible everywhere. | Preventing name collisions and accidental changes. | Prefer local variables and parameters over globals. |
| 05 Recursion | A function can solve a smaller version of the same problem. | Trees, divide-and-conquer, or naturally recursive data. | A base case is mandatory; recursion is not automatically cleaner than a loop. |
| 06 Parameters | Pass by value copies, `&` aliases, and `const &` borrows read-only data efficiently. | Designing function interfaces. | Only use a non-const reference when the caller should be changed. |

## Practice checkpoint

Create a number guessing game. Put input validation, random-number generation, and result messages in separate functions. Then add a limit on attempts.
