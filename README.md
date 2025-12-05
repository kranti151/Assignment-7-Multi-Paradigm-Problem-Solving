# Assignment-7-Multi-Paradigm-Problem-Solving

A comprehensive statistics calculator implementation demonstrating three different programming paradigms: **Procedural** (C), **Functional** (OCaml), and **Object-Oriented** (Python).

##  Overview

This project implements a statistics calculator that computes **mean**, **median**, and **mode** for a list of integers. Each implementation follows a different programming paradigm, showcasing the unique approaches and philosophies of each language.

## Features

- **Mean Calculation**: Computes the average of all integers in the list
- **Median Calculation**: Finds the middle value when the list is sorted
- **Mode Calculation**: Identifies the most frequently occurring integer(s)
- **Multiple Test Cases**: Includes various examples demonstrating edge cases
- **Clean Output**: Formatted, readable statistics display

## 🛠️ Requirements

### C Implementation
- **Compiler**: GCC or any C99-compatible compiler
- **Dependencies**: Standard C library only

### OCaml Implementation
- **Compiler**: OCaml compiler (`ocamlc` or `ocamlopt`)
- **Dependencies**: Standard OCaml library (no external packages)

### Python Implementation
- **Python Version**: Python 3.6+
- **Dependencies**: Standard library only (uses `collections.Counter`)

## 🚀 Installation & Usage

### C (Procedural Paradigm)

#### Installation
```bash
# Check if GCC is installed
gcc --version

# On macOS (if not installed)
xcode-select --install

# On Ubuntu/Debian (if not installed)
sudo apt-get install build-essential
```

#### Compile & Run
```bash
# Compile the program
gcc -o statistics statistics.c

# Run the program
./statistics
```

#### Code Example
```c
int data[] = {1, 2, 3, 4, 5};
int size = sizeof(data) / sizeof(data[0]);
print_statistics(data, size);
```

**Key Features:**
- Manual memory management with `malloc()` and `free()`
- Uses `qsort()` for efficient sorting
- Procedural functions for each calculation
- Direct array manipulation

---

### OCaml (Functional Paradigm)

#### Installation
```bash
# Check if OCaml is installed
ocaml --version

# On macOS (using Homebrew)
brew install ocaml

# On Ubuntu/Debian
sudo apt-get install ocaml
```

#### Compile & Run
```bash
# Compile the program
ocamlc -o statistics_ml statistics.ml

# Run the compiled program
./statistics_ml

# Or run directly with interpreter
ocaml statistics.ml
```

#### Code Example
```ocaml
let data = [1; 2; 3; 4; 5] in
print_statistics data;
```

**Key Features:**
- Immutable data structures (no mutable state)
- Higher-order functions (`List.fold_left`, `List.map`)
- Pattern matching and recursion
- Pure functional approach

---

### Python (Object-Oriented Paradigm)

#### Installation
```bash
# Check Python version
python3 --version

# Python 3.6+ is required (usually pre-installed on macOS/Linux)
```

#### Run
```bash
# Run directly
python3 statistics.py
```

#### Code Example
```python
from statistics import StatisticsCalculator

# Create an instance
calc = StatisticsCalculator([1, 2, 3, 4, 5])

# Print all statistics
calc.print_statistics()

# Or get individual statistics
mean = calc.calculate_mean()
median = calc.calculate_median()
mode = calc.calculate_mode()

# Or get all as a dictionary
stats = calc.get_all_statistics()
```

**Key Features:**
- `StatisticsCalculator` class with encapsulated methods
- Uses Python's `collections.Counter` for frequency counting
- Object-oriented design principles
- Easy to extend and maintain

## Sample Output

All implementations produce similar formatted output:

```
Statistics Calculator - [Language] Implementation
==================================================

=== Statistics Results ===
Data: [1, 2, 3, 4, 5]

Mean: 3.00
Median: 3.00
Mode: 1, 2, 3, 4, 5
========================
```

## Paradigm Comparison

| Aspect | C (Procedural) | OCaml (Functional) | Python (OOP) |
|--------|----------------|-------------------|--------------|
| **Memory Management** | Manual (`malloc`/`free`) | Automatic GC | Automatic GC |
| **Data Mutability** | Mutable arrays | Immutable lists | Mutable lists |
| **Code Organization** | Functions | Functions & recursion | Classes & methods |
| **Type Safety** | Weak (pointers) | Strong (type inference) | Dynamic typing |
| **Performance** | Very fast | Fast | Moderate |
| **Learning Curve** | Moderate | Steep | Gentle |

### Procedural (C)
**Strengths:**
- ✅ Direct control over memory and resources
- ✅ High performance and efficiency
- ✅ Explicit resource management
- ✅ Close to hardware, predictable behavior

**Challenges:**
- ⚠️ Manual memory management (risk of leaks)
- ⚠️ More verbose code
- ⚠️ No built-in data structures
- ⚠️ Potential for buffer overflows

### Functional (OCaml)
**Strengths:**
- ✅ Immutable data prevents many bugs
- ✅ Elegant mathematical expressions
- ✅ Strong type system with inference
- ✅ No side effects in pure functions

**Challenges:**
- ⚠️ Different mindset required
- ⚠️ Less familiar syntax
- ⚠️ Can be less intuitive for beginners
- ⚠️ Performance overhead in some cases

### Object-Oriented (Python)
**Strengths:**
- ✅ Easy to understand and read
- ✅ Highly reusable and extensible
- ✅ Clear encapsulation of data and methods
- ✅ Rich standard library

**Challenges:**
- ⚠️ Slightly more overhead
- ⚠️ Requires understanding OOP concepts
- ⚠️ Can lead to over-engineering for simple tasks

## Implementation Details

### Algorithm Complexity

| Operation | C | OCaml | Python |
|-----------|---|-------|--------|
| Mean | O(n) | O(n) | O(n) |
| Median | O(n log n) | O(n log n) | O(n log n) |
| Mode | O(n log n) | O(n²) | O(n) |

*Note: OCaml's mode implementation uses a simpler approach that trades some efficiency for clarity and functional style.*


- [C Programming Language](https://en.cppreference.com/w/c)
- [OCaml Documentation](https://ocaml.org/docs/)
- [Python Documentation](https://docs.python.org/3/)

---

