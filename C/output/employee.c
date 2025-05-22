#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// Define the struct Employee
struct Employee {
    char name[50];
    int id;
    float salary;
};

// Declare the array of struct Employee after the struct definition
struct Employee employees[MAX_EMPLOYEES];
int numEmployees = 0;

// Function prototypes
void addEmployee();
void deleteEmployee();
void displayEmployees();
void sortEmployeesById();
void searchEmployeeById();
void updateEmployee();

int main() {
    int choice;

    do {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Delete Employee\n");
        printf("3. Display Employees\n");
        printf("4. Search Employee by ID\n");
        printf("5. Update Employee Details\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            scanf("%*s"); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                deleteEmployee();
                break;
            case 3:
                displayEmployees();
                break;
            case 4:
                searchEmployeeById();
                break;
            case 5:
                updateEmployee();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

void addEmployee() {
    if (numEmployees >= MAX_EMPLOYEES) {
        printf("Maximum number of employees reached.\n");
        return;
    }

    struct Employee newEmployee;

    printf("Enter employee name: ");
    scanf("%s", newEmployee.name);
    printf("Enter employee ID: ");
    scanf("%d", &newEmployee.id);
    printf("Enter employee salary: ");
    scanf("%f", &newEmployee.salary);

    employees[numEmployees++] = newEmployee;
    printf("Employee added successfully.\n");
}

void deleteEmployee() {
    if (numEmployees == 0) {
        printf("No employees to delete.\n");
        return;
    }

    int id;
    printf("Enter ID of employee to delete: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].id == id) {
            found = 1;
            for (int j = i; j < numEmployees - 1; j++) {
                employees[j] = employees[j + 1];
            }
            numEmployees--;
            printf("Employee with ID %d deleted successfully.\n", id);
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}

void displayEmployees() {
    if (numEmployees == 0) {
        printf("No employees to display.\n");
        return;
    }

    sortEmployeesById();

    printf("List of Employees:\n");
    printf("ID\tName\tSalary\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("%d\t%s\t%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
}

void sortEmployeesById() {
    for (int i = 0; i < numEmployees - 1; i++) {
        for (int j = 0; j < numEmployees - i - 1; j++) {
            if (employees[j].id > employees[j + 1].id) {
                struct Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
}

void searchEmployeeById() {
    if (numEmployees == 0) {
        printf("No employees to search.\n");
        return;
    }

    int id;
    printf("Enter ID of employee to search: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].id == id) {
            found = 1;
            printf("Employee found:\n");
            printf("ID\tName\tSalary\n");
            printf("%d\t%s\t%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}

void updateEmployee() {
    if (numEmployees == 0) {
        printf("No employees to update.\n");
        return;
    }

    int id;
    printf("Enter ID of employee to update: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].id == id) {
            found = 1;
            printf("Enter new name for employee: ");
            scanf("%s", employees[i].name);
            printf("Enter new salary for employee: ");
            scanf("%f", &employees[i].salary);
            printf("Employee details updated successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}
