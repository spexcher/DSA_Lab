#include <stdio.h>
#include <string.h>

struct Student
{
    char name[50];
    float marks;
};

void appendRecord(FILE *file)
{
    struct Student student;

    printf("Enter student name: ");
    scanf(" %[^\n]", student.name);
    printf("Enter marks: ");
    scanf("%f", &student.marks);

    fprintf(file, "%s %.2f\n", student.name, student.marks);

    printf("Record added successfully!\n");
}

void deleteRecord(FILE *file, const char *nameToDelete)
{
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL)
    {
        perror("Error creating temporary file");
        return;
    }

    struct Student student;
    int found = 0;

    while (fscanf(file, "%s %f", student.name, &student.marks) != EOF)
    {
        if (strcmp(student.name, nameToDelete) != 0)
        {
            // fprintf(tempFile, "%s %.2f\n", student.name, student.marks);
            fputs(student.name, tempFile);
            fputs(" \n", tempFile);
            // fputs(student.marks, tempFile);
        }
        else
        {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found)
    {
        remove("data.txt");
        rename("temp.txt", "data.txt");
        printf("Record deleted successfully!\n");
    }
    else
    {
        printf("Record not found!\n");
        remove("temp.txt");
    }
}

void updateRecord(FILE *file, const char *nameToUpdate)
{
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL)
    {
        perror("Error creating temporary file");
        return;
    }

    struct Student student;
    int found = 0;

    while (fscanf(file, "%s %f", student.name, &student.marks) != EOF)
    {
        if (strcmp(student.name, nameToUpdate) == 0)
        {
            printf("Enter new marks for %s: ", student.name);
            scanf("%f", &student.marks);
            found = 1;
        }
        fprintf(tempFile, "%s %.2f\n", student.name, student.marks);
    }

    fclose(file);
    fclose(tempFile);

    if (found)
    {
        remove("data.txt");
        rename("temp.txt", "data.txt");
        printf("Record updated successfully!\n");
    }
    else
    {
        printf("Record not found!\n");
        remove("temp.txt");
    }
}

void displayRecords(FILE *file)
{
    struct Student student;

    printf("Name\t\tMarks\n");
    printf("-----------------------\n");

    while (fscanf(file, "%s %f", student.name, &student.marks) != EOF)
    {
        printf("%-20s %.2f\n", student.name, student.marks);
    }
}

int main()
{
    FILE *file = fopen("data.txt", "a+");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    int choice;
    char name[50];

    do
    {
        printf("\nMenu:\n");
        printf("1. Append record\n");
        printf("2. Delete record\n");
        printf("3. Update record\n");
        printf("4. Display records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            appendRecord(file);
            break;
        case 2:
            printf("Enter student name to delete: ");
            scanf(" %[^\n]", name);
            deleteRecord(file, name);
            break;
        case 3:
            printf("Enter student name to update: ");
            scanf(" %[^\n]", name);
            updateRecord(file, name);
            break;
        case 4:
            displayRecords(file);
            break;
        case 5:
            break;
        default:
            printf("Invalid choice, please try again!\n");
        }
    } while (choice != 5);

    fclose(file);

    return 0;
}