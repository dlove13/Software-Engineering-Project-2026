# Arithmetic Expression Evaluator
**EECS 348 – Software Engineering Spring 2026**
**Winston Industries LLC**
 
---
 
## Table of Contents
- [About](#about)
- [Features](#features)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Error Handling](#error-handling)
- [Running Tests](#running-tests)
- [Documentation](#documentation)
- [Team](#team)
---
 
## About
 
The Arithmetic Expression Evaluator (AEE) is a C++ application that accepts an infix arithmetic expression, parses it using the Shunting-Yard algorithm, and evaluates it using PEMDAS order of operations. The result is returned as a `double`. If the expression is invalid, a descriptive error message is displayed.
 
---
 
## Features
 
- Parses and evaluates infix arithmetic expressions
- Supports the following operators:
| Operator | Description    | Precedence | Associativity |
|----------|----------------|------------|---------------|
| `+`      | Addition        | 1          | Left          |
| `-`      | Subtraction     | 1          | Left          |
| `*`      | Multiplication  | 2          | Left          |
| `/`      | Division        | 2          | Left          |
| `%`      | Modulo          | 2          | Left          |
| `**`     | Exponentiation  | 3          | Right         |
 
- Supports parentheses for grouping: `(`, `)`
- Handles negative numbers (e.g. `-4`)
- Returns results as `double`
- Descriptive error messages for invalid input
---
 
## Project Structure
 
```
Software-Engineering-Project-2026/
│
├── src/
│   ├── main.cpp            # Entry point; menu and program loop
│   ├── function.h          # Shared types: Token, ErrorCode, ParserResult, function declarations
│   ├── tokenizer.cpp       # Lexical analysis (in progress)
│   ├── parser.cpp          # Shunting-Yard infix-to-RPN conversion
│   ├── evaluator.cpp       # RPN stack-based evaluator (in progress)
│   ├── error_handler.cpp   # Maps ErrorCode values to error messages
│   ├── display.cpp         # Menu and display functions
│   ├── unit_tests.cpp      # Unit tests for all components
│   └── makefile            # Build configuration
│
├── Documentation/
│   ├── 01-Project-Plan.pdf
│   ├── 02-Software-Requirements-Spec.pdf
│   └── 03-Software-Architecture-Design.pdf
│
├── AEE_MeetingLogs/
│   ├── AEE_MeetingLog_1.md
│   ├── AEE_MeetingLog_2.md
│   ├── AEE_MeetingLog_3.md
│   ├── AEE_MeetingLog_4.md
│   ├── AEE_MeetingLog_5.md
│   ├── AEE_MeetingLog_6.md
│   ├── AEE_MeetingLog_7.md
│   └── AEE_MeetingLog_8.md
│
└── README.md
```
 
---
 
## Getting Started
 
### Prerequisites
 
- `g++` with C++17 support or later
- `make`
### Build
 
```bash
cd src
make
```
 
This produces the `main` executable (or `main.exe` on Windows) in the `src/` directory.
 
### Clean
 
```bash
make clean
```
 
---
 
## Usage
 
Run the compiled executable:
 
```bash
./main
```
 
You will be presented with a menu:
 
- **Option 1** – Enter and evaluate an arithmetic expression
- **Option 2** – Run unit tests
- **Any non-digit** – Exit the program
### Example Expressions
 
```
(14 + 16 - 12) * 3 / -4 % 6 ** 2
(1 + 2) * 3
2 ** 3 ** 2
```
 
---
 
## Error Handling
 
The evaluator produces clear error messages for the following error conditions:
 
| Error Code                | Description                                          | Example Input      |
|---------------------------|------------------------------------------------------|--------------------|
| `MISMATCHED_PARENTHESIS`  | A parenthesis is opened or closed without a match    | `( 3 - 2` or `4 )` |
| `ADJACENT_OPERATORS`      | Two operators appear next to each other              | `14 + + 3`         |
| `INVALID_SYNTAX`          | An operator is directly adjacent to a parenthesis    | `( / 1`            |
| `INVALID_EXPRESSION`      | An operator appears at the start of an expression    | `+ 5`              |
| `DIVIDE_BY_ZERO`          | Division or modulo by zero                           | `5 / 0`            |
 
---
 
## Running Tests
 
Select **Option 2** from the main menu, or call `Unit_Tests()` directly. The test suite runs three suites in order:
 
1. **Tokenizer Tests** – Verifies Token object construction and the `==` operator
2. **Parser Tests** – Verifies output for valid expressions and correct error detection for invalid ones
3. **Evaluator Tests** – Computes numeirc of the parser token vector output
---
 
## Documentation
 
All project documentation is in the `Documentation/` folder:
 
| Document | Description |
|----------|-------------|
| `01-Project-Plan.pdf` | Project timeline, roles, and deliverables |
| `02-Software-Requirements-Spec.pdf` | Functional and non-functional requirements |
| `03-Software-Architecture-Design.pdf` | System architecture and  design |
 
Meeting logs are in the `AEE_MeetingLogs/` folder, covering all 8 team meetings from February through May 2026.
 
---
 
## Team
 
**Winston Industries LLC**
 
| Name             | Role                          | Email                        |
|------------------|-------------------------------|------------------------------|
| Davina Love      | Project Leader                | dlove13@ku.edu               |
| Landrie Rolla    | Assistant Project Leader      | landrierolla@ku.edu          |
| Liam Gunther     | Technical Leader              | lgunther@ku.edu              |
| Christian Mitchell | Team Administrator          | christian.mitchell@ku.edu    |
| Conner B Magee   | Data Administrator / QA Engineer | connermagee@ku.edu       |
| Caden Gudenkauf  | Assistant Team Administrator  | caden.gudenkauf@ku.edu       |