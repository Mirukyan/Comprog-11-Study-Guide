# Comprog-11-Study-Guide
This is a study guide for our block BSIT 1H on UCLM

# Interactive C Study Guide & Evaluator (v1.0.0)

A feature-rich, console-based terminal application written in standard C (C99) designed to teach C programming fundamentals from **Prelims** to **Finals**. Features typewriter text animations, Windows audio feedback, interactive quiz challenges, diagnostic feedback, and a gated **Code Sandbox Evaluator**.

---

## Features

*  **Curriculum Breakdown:**
  * **Prelims:** Problem-Solving Process, Flowcharting, Pseudocode, and C Program Structure (`main`, `stdio.h`, `printf`).
  * **Midterm:** Execution Flow, Selection Structures (`if`, `else`, `switch`), and Loops (`for`, `while`, `do-while`).
  * **Semi-Finals:** Function Declarations, Return Types, and Scope (`int`, `void`, `return`).
  * **Finals:** Array Initialization, Bounds, Memory Layout, and Zero-Based Indexing Rules.
*  **Exam Mode Gate (Option 5):**
  * Evaluates understanding across 6 comprehensive C practice challenges.
  * Tracks accurate scoring; requires **at least 80% (5/6)** to pass and set unlock flags.
* **Finale Code Sandbox (Option 6):**
  * Unlocks only after passing Exam Mode.
  * Features live input code parsing that checks syntax requirements for user-written snippets.

---

##  Quick Start (Executable)

If you just want to run the application immediately without compiling:
1. Download `C_Study_Guide.exe` directly from the repository files (or the [Releases](../../releases) tab).
2. Double-click the `.exe` file on Windows to run it!

---

##  How to Run & Compile from Source

### Option 1: Using Dev-C++ (Recommended)

1. Open **Dev-C++**.
2. Go to **File > New > Source File** (or press `Ctrl + N`).
3. Copy and paste the `main.c` source code into the editor.
4. Save the file as `main.c` (`Ctrl + S`).
5. Press **F11** (Compile & Run).

> **Note:** Ensure your compiler in Dev-C++ supports C99 or later (**Tools > Compiler Options > Settings > Code Generation > Language standard (-std) > ISO C99**).

---

### Option 2: Using Visual Studio Code (VS Code)

1. Install **VS Code** along with the **C/C++** extension by Microsoft.
2. Ensure you have a C compiler installed on Windows (such as **MinGW-w64** or **GCC**).
3. Open the folder containing `main.c` in VS Code.
4. Open a new terminal inside VS Code (**Terminal > New Terminal** or `Ctrl + ~`).
5. Compile the program using GCC:
   ```bash
   gcc -std=c99 main.c -o C_Study_Guide.exe
   ```

### Usage & Progression
Modules 1–4: Study lesson notes and solve fill-in-the-blank / output challenges.
Module 5 (Exam Mode): Answer all questions. Score $\ge 80\%$ to unlock the Finale.
Module 6 (Sandbox): Practice writing freehand C statements and receive syntax evaluation.

### License & Credits
Author: Mirukyan
GitHub: https://github.com/Mirukyan
Version: v1.0.0
License: MIT License
