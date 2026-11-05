# Weighted Grade Calculator (C++)

A console-based coursework project that calculates a weighted assessment
percentage and maps it to a letter grade. The original assessment weights and
grade bands have been retained, while input validation and file-output checks
have been added for a safer demonstration.

## Features

- Reads four quizzes and four assignments, each out of 10.
- Reads lab marks out of 20, midterm marks out of 25, and final-exam marks
  out of 40.
- Applies the original weights: quizzes 10%, assignments 10%, lab 20%,
  midterm 20%, and final exam 40%.
- Displays the weighted percentage and corresponding letter grade.
- Appends each result to `results.txt` instead of overwriting prior results.
- Rejects non-numeric and out-of-range marks.

## Grade bands

| Weighted percentage | Grade |
| --- | --- |
| 90–100 | A+ |
| 80–89.99 | A |
| 70–79.99 | B |
| 60–69.99 | C |
| 50–59.99 | D |
| Below 50 | F |

## Build and run

Requires a C++17-compatible compiler such as GCC or Clang.

```bash
g++ -std=c++17 -Wall -Wextra -pedantic src/main.cpp -o grade-calculator
./grade-calculator
```

On Windows, run `grade-calculator.exe` after compiling with MinGW or another
C++17 compiler.

## Output file

The program creates/appends to `results.txt` in the current working directory.
That generated file is intentionally excluded from version control.

## Scope and attribution

This program reports a weighted percentage and a letter grade; it does not
convert the result into a university GPA/CGPA scale. The original source
credits Saad, Nafeesa, Yaseen, Burhan, Maham, and Samavia as the coursework
team. See [AUTHORS.md](AUTHORS.md).

## Smoke test

```bash
./tests/smoke_test.sh
```
