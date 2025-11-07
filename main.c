#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    FILE *fp;
    struct Student s;
    int choice;

    while(1) {
        printf("\n====== Student Record Management System ======\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                fp = fopen("students.txt", "a");
                printf("Enter Roll, Name and Marks: ");
                scanf("%d %s %f", &s.roll, s.name, &s.marks);
                fprintf(fp, "%d %s %.2f\n", s.roll, s.name, s.marks);
                fclose(fp);
                printf("Record added successfully!\n");
                break;

            case 2:
                fp = fopen("students.txt", "r");
                printf("\nRoll\tName\tMarks\n");
                while(fscanf(fp, "%d %s %f", &s.roll, s.name, &s.marks) != EOF)
                    printf("%d\t%s\t%.2f\n", s.roll, s.name, s.marks);
                fclose(fp);
                break;

            case 3:
                fp = fopen("students.txt", "r");
                int r;
                printf("Enter Roll Number to Search: ");
                scanf("%d", &r);
                int found = 0;
                while(fscanf(fp, "%d %s %f", &s.roll, s.name, &s.marks) != EOF) {
                    if(s.roll == r) {
                        printf("Found: %d %s %.2f\n", s.roll, s.name, s.marks);
                        found = 1;
                        break;
                    }
                }
                if(!found) printf("Record not found!\n");
                fclose(fp);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
