
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[100];
    int age;
    float gpa;
} Student;

typedef struct node {
    Student student;
    struct node *next;
} Node;

Node *head = NULL;

void addStudent() {
    Student s;
    printf("Enter student ID: ");
    scanf("%d", &s.id);
    printf("Enter student name: ");
    scanf("%s", s.name);
    printf("Enter student age: ");
    scanf("%d", &s.age);
    printf("Enter student GPA: ");
    scanf("%f", &s.gpa);

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->student = s;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void displayStudents() {
    Node *current = head;
    if (current == NULL) {
        printf("No students are present.\n");
        return;
    }
    while (current != NULL) {
        printf("ID: %d, Name: %s, Age: %d, GPA: %.2f\n",
               current->student.id, current->student.name, current->student.age, current->student.gpa);
        current = current->next;
    }
}

void searchStudentByID(int id) {
    Node *current = head;
    while (current != NULL) {
        if (current->student.id == id) {
            printf("ID: %d,\nName: %s,\nAge: %d,s\nGPA: %.2f\n",
                   current->student.id, current->student.name, current->student.age, current->student.gpa);
            return;
        }
        current = current->next;
    }
    printf("Student not found.\n");
}

void updateStudent(int id) {
    Node *current = head;
    while (current != NULL) {
        if (current->student.id == id) {
            printf("Enter new name: ");
            scanf("%s", current->student.name);
            printf("Enter new age: ");
            scanf("%d", &current->student.age);
            printf("Enter new GPA: ");
            scanf("%f", &current->student.gpa);
            return;
        }
        current = current->next;
    }
    printf("Student not found.\n");
}

void deleteStudent(int id) {
    Node *current = head;
    Node *previous = NULL;
    while (current != NULL) {
        if (current->student.id == id) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Student deleted successfully.\n");
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Student not found.\n");
}

float calculateAverageGPA() {
    Node *current = head;
    if (current == NULL) return 0.0;

    int count = 0;
    float sum = 0.0;
    while (current != NULL) {
        sum += current->student.gpa;
        count++;
        current = current->next;
    }
    return sum / count;
}

void searchHighestGPA() {
    Node *current = head;
    if (current == NULL) {
        printf("No students are present.\n");
        return;
    }

    Node *highest = current;
    current = current->next;
    while (current != NULL) {
        if (current->student.gpa > highest->student.gpa) {
            highest = current;
        }
        current = current->next;
    }
    printf("Highest GPA: ID: %d, Name: %s, Age: %d, GPA: %.2f\n",
           highest->student.id, highest->student.name, highest->student.age, highest->student.gpa);
}

int main() {
    int choice, id;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add a Student\n");
        printf("2. Display All Students\n");
        printf("3. Search for a Student by ID\n");
        printf("4. Update Student Information\n");
        printf("5. Delete a Student\n");
        printf("6. Calculate Average GPA\n");
        printf("7. Find Student with Highest GPA\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);




switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                printf("Enter student ID to search: ");
                scanf("%d", &id);
                searchStudentByID(id);
                break;
            case 4:
                printf("Enter student ID to update: ");
                scanf("%d", &id);
                updateStudent(id);
                break;
            case 5:
                printf("Enter student ID to delete: ");
                scanf("%d", &id);
                deleteStudent(id);
                break;
            case 6:
                printf("Average GPA: %.2f\n", calculateAverageGPA());
                break;
            case 7:
                searchHighestGPA();
                break;
            case 0:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("---------------------------------------------");
    }

    return 0;
}
