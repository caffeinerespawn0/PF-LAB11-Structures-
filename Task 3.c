#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    char name[50];
    char department[30];
    char designation[30];
    float salary;
};

struct Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

void addEmployee() {
    if(employeeCount >= MAX_EMPLOYEES) {
        printf("Employee limit reached!\n");
        return;
    }

    printf("Enter Employee ID: ");
    scanf("%d", &employees[employeeCount].id);

    printf("Enter Name: ");
    scanf("%s", employees[employeeCount].name);

    printf("Enter Department: ");
    scanf("%s", employees[employeeCount].department);

    printf("Enter Designation: ");
    scanf("%s", employees[employeeCount].designation);

    printf("Enter Salary: ");
    scanf("%f", &employees[employeeCount].salary);

    employeeCount++;
    printf("Employee added successfully!\n");
}

void displayEmployees() {
    if(employeeCount == 0) {
        printf("No employees to display.\n");
        return;
    }

    printf("\n%-5s %-15s %-15s %-15s %-10s\n", "ID", "Name", "Department", "Designation", "Salary");
    for(int i = 0; i < employeeCount; i++) {
        printf("%-5d %-15s %-15s %-15s %.2f\n",
               employees[i].id,
               employees[i].name,
               employees[i].department,
               employees[i].designation,
               employees[i].salary);
    }
}

void searchEmployee() {
    int id;
    printf("Enter Employee ID to search: ");
    scanf("%d", &id);

    for(int i = 0; i < employeeCount; i++) {
        if(employees[i].id == id) {
            printf("Employee Found:\n");
            printf("ID: %d\nName: %s\nDepartment: %s\nDesignation: %s\nSalary: %.2f\n",
                   employees[i].id,
                   employees[i].name,
                   employees[i].department,
                   employees[i].designation,
                   employees[i].salary);
            return;
        }
    }
    printf("Employee not found.\n");
}

void updateEmployee() {
    int id;
    printf("Enter Employee ID to update: ");
    scanf("%d", &id);

    for(int i = 0; i < employeeCount; i++) {
        if(employees[i].id == id) {
            printf("Enter new Name: ");
            scanf("%s", employees[i].name);

            printf("Enter new Department: ");
            scanf("%s", employees[i].department);

            printf("Enter new Designation: ");
            scanf("%s", employees[i].designation);

            printf("Enter new Salary: ");
            scanf("%f", &employees[i].salary);

            printf("Employee updated successfully!\n");
            return;
        }
    }
    printf("Employee not found.\n");
}

void deleteEmployee() {
    int id;
    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);

    for(int i = 0; i < employeeCount; i++) {
        if(employees[i].id == id) {
            for(int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            printf("Employee deleted successfully!\n");
            return;
        }
    }
    printf("Employee not found.\n");
}

int main() {
    int choice;
        while(1){
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
            switch(choice){
            case 1:
            addEmployee();
            break;
            case 2:
            displayEmployees();
            break;
            case 3:
            searchEmployee();
            break;
            case 4:
            updateEmployee();
            break;
            case 5:
            deleteEmployee();
            break;
            case 6:
            printf("Exiting...\n");
            break;
            return 0; 
            default: 
            printf("Invalid choice! Try again.\n");
        }
    } 
    return 0;
}
