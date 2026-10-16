# LED Toggle Simulator — Parikshit Student Satellite Task

A modular C project implementing a simulated LED state controller using custom header files, structures, pointer-based state management, and dynamic memory allocation.

---

## Problem Statement

Write a C program to toggle n LEDs alternatively m number of times according to the following specifications:
- Define an LED structure with an identifier (led_no) and a pointer variable (status).
- Dynamically allocate memory for an array of n LED instances.
- Implement modular functions (init_led, set_led, reset_led, toggle_led, free_led) using custom header files.
- Ensure strict deallocation of all dynamically assigned heap memory at program termination.

---

## Repository Structure

parikshit-led-task/
├── led.h         # Header file with definitions, struct layout, and function prototypes
├── led.c         # Implementation of LED lifecycle and state manipulation routines
├── main.c        # Driver code: user I/O, dynamic allocations, and execution loop
├── .gitignore    # Excludes build artifacts and local IDE configurations
└── README.md     # Project documentation

---

## Architecture and Memory Management

### 1. Pointer-Driven State Struct
Each LED's state is stored in heap-allocated memory via an integer pointer rather than an inline integer. This tests indirect memory addressing and pointer dereferencing common in low-level embedded register mapping.

### 2. Two-Tier Memory Deallocation
To prevent memory leaks:
1. Every individual LED.status pointer is freed inside free_led().
2. The root dynamic array of LEDs is freed subsequently in main.c.

---

## Build and Run

### Compilation
gcc main.c led.c -o led_program

### Execution (Windows PowerShell)
.\led_program.exe

### Execution (Linux / macOS)
./led_program

---

## Sample Output

Enter number of LEDs (n): 4
Enter number of toggle cycles (m): 3

Initial Configuration:
[LED 1: ON] [LED 2: OFF] [LED 3: ON] [LED 4: OFF] 
--------------------------------------------------
After Cycle 1: [LED 1: OFF] [LED 2: ON] [LED 3: OFF] [LED 4: ON] 
After Cycle 2: [LED 1: ON] [LED 2: OFF] [LED 3: ON] [LED 4: OFF] 
After Cycle 3: [LED 1: OFF] [LED 2: ON] [LED 3: OFF] [LED 4: ON] 

Memory deallocated successfully.