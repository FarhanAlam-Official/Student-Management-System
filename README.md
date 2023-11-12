# Student Management System
---

## Table of Contents

1. [Introduction](#introduction)
2. [Objectives](#objectives)
3. [Features](#features)
    - [Administrator Module](#administrator-module)
    - [Student Module](#student-module)
4. [Technologies Used](#technologies-used)
5. [Installation Guide](#installation-guide)
6. [Usage](#usage)
7. [License](#license)
8. [Contributing](#contributing)

---

## Introduction

The **Student Management System** is a C++ based application designed as a part of the Bachelor of Computer Application (BCA) 3rd semester project. This system aims to streamline the management of student records, courses, and financial data. The application provides two modules: the Administrator Module, which allows administrators to manage student data, and the Student Module, which gives students access to their academic details and personal information.

The system facilitates efficient record-keeping and is ideal for educational institutions, making administrative tasks easier and improving overall productivity.

---

## Objectives

- Facilitate **student record management** for administrators.
- Enable **course and fee tracking** for both students and administrators.
- Provide students with access to their **academic details**.
- Streamline administrative processes like student enrollment, course management, and fee status checks.

---

## Features

### Administrator Module
The Administrator Module allows the management of student data, courses, and finances. The features include:

- **Manage student accounts**: Add, edit, and delete student records.
- **Reset passwords**: Administrators can reset student passwords if needed.
- **Course management**: Add, edit, and remove courses offered to students.
- **Enroll/disenroll students**: Enroll or remove students from specific courses.
- **Generate student reports**: Create detailed reports of student performance and progress.
- **View student performance**: Access grades, course enrollments, and fee statuses of students.

### Student Module
The Student Module provides students with access to their academic records, course details, and personal information. Features include:

- **View grades and academic progress**: Access grades and monitor academic performance over time.
- **Enroll in or drop courses**: Students can enroll in or remove courses as per their academic plan.
- **Check fee status and history**: View current fee statuses and historical records.
- **Update personal details**: Students can update their personal information like contact details and addresses.

---

## Technologies Used

- **Programming Language**: C++
- **IDE**: Visual Studio Code / Code::Blocks / DevC++
- **Compiler**: GCC (GNU Compiler Collection)
- **Version Control**: Git (for tracking changes and collaboration)

---

## Installation Guide

Follow the steps below to set up the Student Management System on your local machine:

### Prerequisites:
- **C++ Compiler**: Ensure you have a C++ compiler installed on your machine (e.g., GCC).
- **IDE (Optional)**: Any text editor or IDE such as Visual Studio Code, Code::Blocks, or DevC++.

### Steps to Set Up:

1. **Clone the repository**: Clone the repository to your local machine using Git.
    ```bash
    git clone https://github.com/FarhanAlam-Official/Student-Management-System.git
    ```

2. **Navigate to the project directory**:
    ```bash
    cd Student-Management-System
    ```

3. **Compile the C++ files**: Use your C++ compiler to compile the source code.
    For example, using GCC:
    ```bash
    g++ main.cpp -o student_management_system
    ```

4. **Run the program**:
    After compilation, run the generated executable:
    ```bash
    ./student_management_system
    ```

---

## Usage

### For Administrator:
1. **Login**: Enter the administrator username and password.
2. **Manage Students**: Add new students, reset passwords, or generate reports.
3. **Manage Courses**: Add or remove courses, enroll or disenroll students.
4. **View Reports**: Generate performance reports for students.

### For Student:
1. **Login**: Enter your student credentials.
2. **View Grades**: Check your grades and academic performance.
3. **Manage Courses**: Enroll in or drop courses as needed.
4. **Check Fee Status**: View your fee payment status and history.
5. **Update Personal Details**: Modify personal information like phone number and address.

---

## License

This project is licensed under the MIT License. See the LICENSE file for more details.

---

## Contributing

Contributions to this project are welcome. To contribute:

1. Fork the repository on GitHub.
2. Create a new branch for your feature or bug fix.
    ```bash
    git checkout -b feature-branch
    ```
3. Make your changes and commit them.
    ```bash
    git commit -m "Your commit message"
    ```
4. Push to your branch.
    ```bash
    git push origin feature-branch
    ```
5. Open a pull request and describe your changes.
