# LED Toggle Simulator — Parikshit Student Satellite Task

A modular C project implementing a simulated LED state controller using custom header files, structures, pointer-based state management, and dynamic memory allocation.

---

## 📌 Problem Statement

Write a C program to toggle $n$ LEDs alternatively $m$ number of times according to the following specifications:
- Define an `LED` structure with an identifier (`led_no`) and a pointer variable (`status`).
- Dynamically allocate memory for an array of $n$ `LED` instances.
- Implement modular functions (`init_led`, `set_led`, `reset_led`, `toggle_led`, `free_led`) using custom header files.
- Ensure strict deallocation of all dynamically assigned heap memory at program termination.

---

## 📁 Repository Structure

```text
parikshit-led-task/
├── led.h         # Header file with definitions, struct layout, and function prototypes
├── led.c         # Implementation of LED lifecycle and state manipulation routines
├── main.c        # Driver code: user I/O, dynamic allocations, and execution loop
├── .gitignore    # Excludes build artifacts and local IDE configurations
└── README.md 