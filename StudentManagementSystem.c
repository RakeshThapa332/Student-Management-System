#include <stdio.h>
#include <stdlib.h>


void saveToFile(const char *filename);
void loadFromFile(const char *filename);
void addStudent();
void findbyRoll();
void totalStudent();
void deleteStudent();
void updateStudent();

// Structure to store student details
struct student {
    char firstName[20];
    char lastName[20];
    int roll;
    float gpa;
    int courseID[10];
    char address[20];
    char phoneNumber[15];
};

struct student s[100]; // Assuming a maximum of 100 students

int i = 0; // Global variable to keep track of total students

int main() {
     printf("----------------------------------------\n");
    printf("\tSTUDENT MANAGEMENT SYSTEM");
    printf("\n----------------------------------------\n");
    int taskChoice;
    while (1) {
        printf("\nEnter the task that you want to perform:\n");
        printf("1. Add a new student detail\n");
        printf("2. Find student detail by roll number\n");
        printf("3. Find the total number of student enrolled\n");
        printf("4. Delete the data of student\n");
        printf("5. Update the data of student\n");
        printf("6. Exit\n\n");

        if (scanf("%d", &taskChoice) != 1) {
            printf("Enter a valid input\n");
            continue;
        }

        switch (taskChoice) {
            case 1:
                addStudent();
                break;
            case 2:
                findbyRoll();
                break;
            case 3:
                totalStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                updateStudent();
                break;
            case 6:
                exit(0); // Exit the program
            default:
                printf("Please select a number from 1 to 6\n");
        }
    }

    return 0;
}

// Function to add student details
void addStudent() {
    printf("Add the student details\n\n");
    printf("Enter the first name of student:\n");
    scanf("%s", s[i].firstName);
    printf("Enter the last name of student:\n");
    scanf("%s", s[i].lastName);
    printf("Enter the roll number of student:\n");
    scanf("%d", &s[i].roll);
    printf("Enter the GPA of student:\n");
    scanf("%f", &s[i].gpa);
    printf("Enter the course id of student:\n");
    for (int j = 0; j < 6; j++) {
        scanf("%d", &s[i].courseID[j]);
    }
    printf("Enter the address of student:\n");
    scanf("%s", s[i].address);
    printf("Enter the phone number of student:\n");
    scanf("%s", s[i].phoneNumber);
    i++;
    saveToFile("student.txt");
}

// Function to find student details using roll number
void findbyRoll() {
    loadFromFile("student.txt");
    int temp;
    printf("Enter the roll number of student:\n");
    scanf("%d", &temp);
    int found = 0;
    for (int j = 0; j < i; j++) {
        if (temp == s[j].roll) {
            found = 1;
            printf("First name: %s\n", s[j].firstName);
            printf("Last name: %s\n", s[j].lastName);
            printf("GPA: %.2f\n", s[j].gpa);
            printf("Address: %s\n", s[j].address);
            printf("Phone number: %s\n", s[j].phoneNumber);
            printf("Course IDs: ");
            for (int k = 0; k < 6; k++) {
                printf("%d ", s[j].courseID[k]);
            }
            printf("\n");
            break;
        }
    }
    if (!found)
        printf("Student with roll number %d not found\n", temp);
}

// Function to calculate total number of students enrolled
void totalStudent() {
    loadFromFile("student.txt"); // Load data from file to update the student count
    printf("The total number of students currently enrolled are: %d\n", i);
}

// Function to delete a student's data
void deleteStudent() {
    int temp;
    printf("Enter the roll number of student you want to delete:\n");
    scanf("%d", &temp);
    int found = 0;
    for (int j = 0; j < i; j++) {
        if (temp == s[j].roll) {
            for (int k = j; k < i - 1; k++) {
                s[k] = s[k + 1];
            }
            i--;
            found = 1;
            printf("Record of student with roll number %d deleted successfully\n", temp);
            break;
        }
    }
    if (!found)
        printf("Student with roll number %d not found\n", temp);
    saveToFile("student.txt");
}

// Function to update the data of a student
void updateStudent() {
    int temp;
    printf("\nEnter the roll number of student you want to update:\n");
    scanf("%d", &temp);
    int found = 0;
    for (int j = 0; j < i; j++) {
        if (temp == s[j].roll) {
            found = 1;
            printf("1. First Name\n");
            printf("2. Last Name\n");
            printf("3. Roll number\n");
            printf("4. GPA\n");
            printf("5. Address\n");
            printf("6. Phone Number\n");
            printf("7. Course IDs\n");
            int choice;
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    printf("\nEnter the updated first name:\n");
                    scanf("%s", s[j].firstName);
                    break;
                case 2:
                    printf("Enter the updated last name:\n");
                    scanf("%s", s[j].lastName);
                    break;
                case 3:
                    printf("Enter the updated roll number:\n");
                    scanf("%d", &s[j].roll);
                    break;
                case 4:
                    printf("Enter the updated GPA:\n");
                    scanf("%f", &s[j].gpa);
                    break;
                case 5:
                    printf("Enter the updated address:\n");
                    scanf("%s", s[j].address);
                    break;
                case 6:
                    printf("Enter the updated phone number:\n");
                    scanf("%s", s[j].phoneNumber);
                    break;
                case 7:
                    printf("Enter the updated course IDs:\n");
                    for (int k = 0; k < 6; k++) {
                        scanf("%d", &s[j].courseID[k]);
                    }
                    break;
                default:
                    printf("Invalid option\n");
            }
            printf("Record updated successfully\n");
            break;
        }
    }
    if (!found)
        printf("Student with roll number %d not found\n", temp);
    saveToFile("student.txt");
}

// Function to save student details to a file
void saveToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int j = 0; j < i; j++) {
        fprintf(file, "%s %s %d %.2f %s %s", s[j].firstName, s[j].lastName, s[j].roll, s[j].gpa, s[j].address, s[j].phoneNumber);
        for (int k = 0; k < 6; k++) {
            fprintf(file, " %d", s[j].courseID[k]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    printf("Student data saved to %s\n", filename);
}

// Function to load student details from a file
void loadFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    i = 0;
    while (fscanf(file, "%s %s %d %f %s %s", s[i].firstName, s[i].lastName, &s[i].roll, &s[i].gpa, s[i].address, s[i].phoneNumber) != EOF) {
        for (int k = 0; k < 6; k++) {
            fscanf(file, "%d", &s[i].courseID[k]);
        }
        i++;
    }
    fclose(file);
    printf("Student data loaded from %s\n", filename);
}
