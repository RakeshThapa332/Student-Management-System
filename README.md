Student Management System
A simple student management system written in C that allows you to add, update, delete, and view student details. The system keeps track of student records, including first name, last name, roll number, GPA, courses, address, and phone number. It also supports saving and loading student data from a file.

Features
Add New Student: Allows adding a new student's details.
View Student by Roll Number: Retrieves and displays the details of a student using their roll number.
Total Students Enrolled: Displays the total number of students currently enrolled.
Delete Student: Deletes a student's record by their roll number.
Update Student Information: Allows updating specific details of a student (e.g., GPA, address, phone number).
File Operations
The system uses a text file (student.txt) to store student data. The file is updated every time a new student is added, or an existing record is updated or deleted.

Structure
The system uses a structure student to hold information about each student, which includes:

First name
Last name
Roll number
GPA
Course IDs (up to 6 courses)
Address
Phone number
Usage
Clone the Repository:
bash
Copy
Edit
git clone https://github.com/RakeshThapa332/Student-Management-System.git
Compile the Code:
Use the following command to compile the C program:

bash
Copy
Edit
gcc -o student_management student_management.c
Run the Program:
After compiling, run the program:

bash
Copy
Edit
./student_management
Available Options:
Add a new student detail
Find student detail by roll number
Find the total number of students enrolled
Delete the data of a student
Update the data of a student
Exit
Example
Here is an example of the user interaction:

markdown
Copy
Edit
STUDENT MANAGEMENT SYSTEM
Enter the task that you want to perform:

1. Add a new student detail
2. Find student detail by roll number
3. Find the total number of students enrolled
4. Delete the data of a student
5. Update the data of a student
6. Exit
To add a new student, choose option 1 and enter the student details (First Name, Last Name, Roll Number, GPA, Course IDs, Address, Phone Number).
To find a student by roll number, choose option 2 and enter the roll number. It will display the student's details.
To view the total number of students enrolled, choose option 3.
To delete a student's data, choose option 4 and enter the roll number of the student you want to delete.
To update a student's details, choose option 5 and select the field you want to update (e.g., First Name, GPA, etc.).
To exit the system, choose option 6.









