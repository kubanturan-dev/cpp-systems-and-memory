# cpp-systems-and-memory
Custom C++ implementations of core data structures and memory management concepts
# C++ Systems & Memory Management

This repository contains my C++ implementations of core data structures and low-level memory management concepts, written to build a strong foundation for high-performance computing.

## Projects Included

### 1. Custom Vector (`MyVector`)
A template-based custom implementation of a dynamic array (similar to "std::vector").
- **Key Concepts Used:** Templates, dynamic memory allocation ("new"/"delete"), capacity resizing, and deep copying (Rule of Three).
- **Why:** To understand how standard library containers manage memory under the hood.

### 2. Virtual Memory & Process Manager
A simulation of an operating system's memory allocation and process management.
- **Key Concepts Used:** Object-Oriented Programming (inheritance, polymorphism), bitwise enums, and basic memory block allocation strategies (First-Fit).

## How to Run
These files can be compiled using any standard C++ compiler (e.g., `g++`).
```bash
g++ vector.cpp -o vector_test
./vector_test
