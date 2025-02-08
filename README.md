# Student Management System

A simple student management system written in C that allows you to add, update, delete, and view student details. The system keeps track of student records, including first name, last name, roll number, GPA, courses, address, and phone number. It also supports saving and loading student data from a file.

## Features

- **Add New Student**: Allows adding a new student's details.
- **View Student by Roll Number**: Retrieves and displays the details of a student using their roll number.
- **Total Students Enrolled**: Displays the total number of students currently enrolled.
- **Delete Student**: Deletes a student's record by their roll number.
- **Update Student Information**: Allows updating specific details of a student (e.g., GPA, address, phone number).

## File Operations

The system uses a text file (`student.txt`) to store student data. The file is updated every time a new student is added or an existing record is updated or deleted.

## Structure

The system uses a structure `student` to hold information about each student, which includes:

- First name
- Last name
- Roll number
- GPA
- Course IDs (up to 6 courses)
- Address
- Phone number

## Usage

1. **Clone the Repository**:

    ```bash
    git clone https://github.com/RakeshThapa332/Student-Management-System.git
    ```

2. **Compile the Code**:

    Use the following command to compile the C program:

    ```bash
    gcc -o student_management student_management.c
    ```

3. **Run the Program**:

    After compiling, run the program:

    ```bash
    ./student_management
    ```

4. **Available Options**:
   - Choose the option to add, view, update, delete, or find the total number of students.
   - Follow the prompts to enter student details and interact with the system.



## License

This project is licensed under the [MIT License](LICENSE).












