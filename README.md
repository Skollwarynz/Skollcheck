# 🐺 Skollcheck: Your Digital Event Tracker 📝

**Skollcheck** is a fast and lightweight application developed in C for the efficient management of commitments, events, and task lists (checklists) directly from the command line.

***

## 🌟 Key Features

* **Dynamic Memory Management:** Uses dynamic allocation (`malloc`, `realloc`) to efficiently adapt to the changing number of commitments.
* **Simple CUI Interface:** A clean and intuitive Command-Line User Interface (CUI) for quick action selection.
* **Core Functionality:** Ability to add, print, and save commitments to a file.
* **Portability:** Pure ANSI C code, making it ideal for use across various platforms (Linux, macOS, Windows/MinGW).

***

## 🚀 Quick Start Guide

### Prerequisites

To compile and run **Skollcheck**, you need a C compiler installed (such as `gcc` or `clang`).

### Compilation

Clone the repository and compile the project:

```bash
# Clone the repository
git clone [https://github.com/Skollwarynz/Skollcheck.git](https://github.com/Skollwarynz/Skollcheck.git)

# Enter the project directory
cd Skollcheck

# Compile (assuming your main file is main.c)
gcc main.c -o skollcheck -lm 
# Note: The '-lm' option is necessary to link the math library (math.h) if used.
## 🚀 Execution

Run the compiled executable:

```bash
./skollcheck

