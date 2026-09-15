# How to learn from each C++ lesson

Each focused source file follows this teaching pattern. Read the file in this order:

1. **Learn** — name the new idea in your own words.
2. **Why** — identify the problem it solves.
3. **When** — decide when you would choose it in a real program.
4. **Watch out** — note the mistake most likely to produce a bug.
5. **Try next** — modify one thing before moving on.

Do not try to memorise every library function. A useful tutorial builds a decision-making habit: *what data do I have, what must remain true, and which standard tool expresses that intent safely?*

## Reading code comments

Comments should explain intent, trade-offs, and surprising behaviour. They should not merely translate C++ into English. For example, “`const &` avoids a copy and prevents modification” is useful; “this calls `printInfo`” is not.

## A healthy workflow

- Compile with `-Wall -Wextra -Wpedantic`.
- Change one value, condition, or function at a time.
- Predict the output before running the program.
- Intentionally test invalid input for every interactive example.
- Keep a short list of questions and revisit the relevant lesson after finishing a stage.
