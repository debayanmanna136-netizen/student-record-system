#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addRecord();
void displayRecords();
void searchRecord();
void deleteAllRecords();
void deleteRecordByRoll();

int main() {
    int choice;

    while (1) {
        printf("\n===== Student Record System =====\n");
        printf("1. Add New Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Record by Roll No\n");
        printf("4. Delete Record by Roll No\n");
        printf("5. Delete All Records\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                deleteRecordByRoll();
                break;
            case 5:
                deleteAllRecords();
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// ✅ Add new record
void addRecord() {
    FILE *fp = fopen("students.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char name[50];
    int roll;
    float marks;

    printf("\nEnter Student Name: ");
    scanf("%s", name);
    printf("Enter Roll Number: ");
    scanf("%d", &roll);
    printf("Enter Marks: ");
    scanf("%f", &marks);

    fprintf(fp, "%s %d %.2f\n", name, roll, marks);
    printf("✅ Record saved successfully!\n");

    fclose(fp);
}

// ✅ Display all records
void displayRecords() {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("No records found! File might be empty.\n");
        return;
    }

    char name[50];
    int roll;
    float marks;

    printf("\n--- Student Records ---\n");
    printf("%-20s %-10s %-10s\n", "Name", "Roll No", "Marks");
    printf("------------------------------------------\n");

    while (fscanf(fp, "%s %d %f", name, &roll, &marks) != EOF) {
        printf("%-20s %-10d %-10.2f\n", name, roll, marks);
    }

    fclose(fp);
}

// ✅ Search record by roll number
void searchRecord() {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    int searchRoll, found = 0;
    char name[50];
    int roll;
    float marks;

    printf("Enter Roll Number to Search: ");
    scanf("%d", &searchRoll);

    while (fscanf(fp, "%s %d %f", name, &roll, &marks) != EOF) {
        if (roll == searchRoll) {
            printf("\nRecord Found:\n");
            printf("Name: %s\nRoll No: %d\nMarks: %.2f\n", name, roll, marks);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("❌ No record found for Roll No %d\n", searchRoll);

    fclose(fp);
}

// ✅ Delete all records
void deleteAllRecords() {
    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error deleting records!\n");
        return;
    }

    fclose(fp);
    printf("🗑️ All records deleted successfully!\n");
}

// ✅ Delete specific record by roll number
void deleteRecordByRoll() {
    FILE *fp = fopen("students.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (fp == NULL || temp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int rollToDelete, roll, found = 0;
    char name[50];
    float marks;

    printf("Enter Roll Number to Delete: ");
    scanf("%d", &rollToDelete);

    while (fscanf(fp, "%s %d %f", name, &roll, &marks) != EOF) {
        if (roll != rollToDelete) {
            fprintf(temp, "%s %d %.2f\n", name, roll, marks);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        printf("🗑️ Record with Roll No %d deleted successfully!\n", rollToDelete);
    else
        printf("❌ No record found with Roll No %d.\n", rollToDelete);
}

