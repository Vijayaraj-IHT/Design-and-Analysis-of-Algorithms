# Design and Analysis of Algorithms

A comprehensive C++ implementation of classical algorithms and algorithmic techniques, showcasing core computer science concepts through practical laboratory exercises.

## 📚 Overview

This repository contains educational implementations of fundamental algorithms covered in the Design and Analysis of Algorithms course. Each exercise demonstrates key algorithmic paradigms with clean, well-structured C++ code and CMake-based build system.

**Language Composition:**
- C++ (91.7%) - Core algorithm implementations
- CMake (5.5%) - Build configuration
- Batch Files (2.8%) - Windows build scripts

## 📋 Contents

### Exercise Modules

| Exercise | Topic | Algorithms |
|----------|-------|-----------|
| **EX1** | Brute Force Sorting | Bubble Sort, Selection Sort |
| **EX2** | Brute Force Search & Geometry | String Matching, Closest Pair |
| **EX3** | Divide and Conquer | Merge Sort, Quick Sort |
| **EX4** | Decrease and Conquer | Heap Sort, Insertion Sort |
| **EX5** | String Matching | Horspool's Algorithm |
| **EX6** | Dynamic Programming | Floyd's All-Pairs Shortest Path |
| **EX7** | Greedy Technique | Huffman Coding |
| **EX8** | Backtracking | N-Queens Problem |
| **EX9** | Branch and Bound | Assignment Problem, Knapsack |

## 🛠️ Building

### Prerequisites
- C++ compiler (C++11 or higher)
- CMake 3.10+

### Build Instructions

**Cross-platform (Linux/macOS/Windows):**
```bash
cd DAA-Laboratory-Exercises
cmake -B build
cmake --build build
```

**Windows (using batch script):**
```batch
cd DAA-Laboratory-Exercises
build.bat
```

**Run all exercises:**
```batch
run_all.bat
```

## 🎯 Learning Outcomes

This repository helps understand:
- Algorithm design paradigms and their applications
- Time and space complexity analysis
- Trade-offs between different algorithmic approaches
- Practical implementation of theoretical concepts
- Problem-solving strategies for common computational challenges

## 📁 Project Structure

```
Design-and-Analysis-of-Algorithms/
├── README.md
└── DAA-Laboratory-Exercises/
    ├── CMakeLists.txt
    ├── build.bat
    ├── run_all.bat
    ├── README.md
    ├── TODO_CODESTRUCTURE.md
    ├── EX1_Brute_Force_Sorting/
    ├── EX2_Brute_Force_Search_and_Geometry/
    ├── EX3_Divide_and_Conquer/
    ├── EX4_Decrease_and_Conquer/
    ├── EX5_String_Matching/
    ├── EX6_Dynamic_Programming/
    ├── EX7_Greedy_Technique/
    ├── EX8_Backtracking/
    └── EX9_Branch_and_Bound/
```

## 🚀 Getting Started

1. Clone the repository:
   ```bash
   git clone https://github.com/Vijayaraj-IHT/Design-and-Analysis-of-Algorithms.git
   cd Design-and-Analysis-of-Algorithms
   ```

2. Navigate to the exercises directory:
   ```bash
   cd DAA-Laboratory-Exercises
   ```

3. Build the project:
   ```bash
   cmake -B build && cmake --build build
   ```

4. Run exercises from the build directory

## 📖 Algorithm Paradigms Covered

- **Brute Force**: Direct, exhaustive approach to problem solving
- **Divide and Conquer**: Recursively breaking problems into subproblems
- **Decrease and Conquer**: Reducing problem size by a constant or factor
- **Dynamic Programming**: Optimal substructure with memoization
- **Greedy Algorithms**: Making locally optimal choices
- **Backtracking**: Exploring solution space systematically
- **Branch and Bound**: Optimization through bounding and pruning

## 💡 Key Features

✅ Clean, readable C++ implementations  
✅ CMake-based cross-platform build system  
✅ Organized by algorithmic paradigm  
✅ Educational focus with code comments  
✅ Windows batch scripts for convenience  
✅ Modular exercise structure  

## 📝 Notes

- Refer to `TODO_CODESTRUCTURE.md` for project structure details
- Each exercise directory contains implementation of specific algorithms
- See individual exercise README files for detailed documentation

## 🎓 Use Cases

- **Students**: Learn fundamental algorithms through practice
- **Educators**: Reference implementations for teaching
- **Developers**: Quick reference for common algorithm implementations
- **Interviewees**: Preparation for coding interviews

## 📄 License

This project is open source and available for educational purposes.

---

**Last Updated:** 2026-05-08  
**Author:** [Vijayaraj-IHT](https://github.com/Vijayaraj-IHT)
