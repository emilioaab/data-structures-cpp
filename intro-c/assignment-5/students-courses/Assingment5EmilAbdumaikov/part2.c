/* Assignment: 5
Author: Emil Abdumalikov, ID: 
*/

#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Course
{
    char name[30];
    int grade;
};

struct Student
{
    char name[30];
    int num_of_courses;
    struct Course *arr;
};

struct Student *Initialize(int *psize);
void PrintStudent(struct Student *arr, int size, char *name);
void PrintCourse(struct Student *arr, int size, char *name);
void Update(struct Student *arr, int size, char *sname, char *cname, int grade);
void Common(struct Student *arr, int size, char *s1, char *s2);

int main()
{
    struct Student *students;
    int size = 0;

    students = Initialize(&size);

    char sname[30], cname[30];
    int grade;

    printf("Enter student name: ");
    scanf("%s", sname);
    printf("Enter course name: ");
    scanf("%s", cname);
    printf("Enter grade: ");
    scanf("%d", &grade);

    Update(students, size, sname, cname, grade);

    printf("Enter student name to print details: ");
    scanf("%s", sname);
    PrintStudent(students, size, sname);

    printf("Enter course name to print students: ");
    scanf("%s", cname);
    PrintCourse(students, size, cname);

    char s1[30], s2[30];

    printf("Enter first student name: ");
    scanf("%s", s1);
    printf("Enter second student name: ");
    scanf("%s", s2);

    Common(students, size, s1, s2);

    free(students);

    return 0;
}

struct Student *Initialize(int *psize)
{
    printf("Enter the number of students: ");
    scanf("%d", psize);

    struct Student *arr = (struct Student *)malloc(*psize * sizeof(struct Student));

    for (int i = 0; i < *psize; i++)
    {
        printf("Enter student name: ");
        scanf("%s", arr[i].name);

        printf("Enter number of courses: ");
        scanf("%d", &(arr[i].num_of_courses));

        arr[i].arr = (struct Course *)malloc(arr[i].num_of_courses * sizeof(struct Course));

        for (int j = 0; j < arr[i].num_of_courses; j++)
        {
            printf("Enter course name: ");
            scanf("%s", arr[i].arr[j].name);

            printf("Enter grade: ");
            scanf("%d", &(arr[i].arr[j].grade));
        }
    }

    return arr;
}

void PrintStudent(struct Student *arr, int size, char *name)
{
    int found = 0;

    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i].name, name) == 0)
        {
            found = 1;

            printf("Student: %s\n", arr[i].name);
            printf("Courses:\n");

            for (int j = 0; j < arr[i].num_of_courses; j++)
            {
                printf("Course %d: %s\n", j + 1, arr[i].arr[j].name);
                printf("Grade: %d\n", arr[i].arr[j].grade);
            }

            // Calculate the average grade
            float sum = 0;
            for (int j = 0; j < arr[i].num_of_courses; j++)
            {
                sum += arr[i].arr[j].grade;
            }
            float average = sum / arr[i].num_of_courses;

            printf("Average grade: %.2f\n", average);

            break;
        }
    }

    if (!found)
    {
        printf("Error: Student not found.\n");
    }
}

void PrintCourse(struct Student *arr, int size, char *name)
{
    int found = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < arr[i].num_of_courses; j++)
        {
            if (strcmp(arr[i].arr[j].name, name) == 0)
            {
                found = 1;

                printf("Student: %s\n", arr[i].name);
                printf("Course: %s\n", arr[i].arr[j].name);
                printf("Grade: %d\n", arr[i].arr[j].grade);

                break;
            }
        }
    }

    if (!found)
    {
        printf("Error: Course not found.\n");
    }
}

void Update(struct Student *arr, int size, char *sname, char *cname, int grade)
{
    int found = 0;

    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i].name, sname) == 0)
        {
            found = 1;

            for (int j = 0; j < arr[i].num_of_courses; j++)
            {
                if (strcmp(arr[i].arr[j].name, cname) == 0)
                {
                    arr[i].arr[j].grade = grade;
                    printf("Grade updated successfully.\n");
                    break;
                }
            }

            if (!found)
            {
                struct Course *new_arr = (struct Course *)realloc(arr[i].arr, (arr[i].num_of_courses + 1) * sizeof(struct Course));

                if (new_arr != NULL)
                {
                    arr[i].arr = new_arr;
                    strcpy(arr[i].arr[arr[i].num_of_courses].name, cname);
                    arr[i].arr[arr[i].num_of_courses].grade = grade;
                    arr[i].num_of_courses++;

                    printf("Course added successfully.\n");
                }
                else
                {
                    printf("Error: Memory allocation failed.\n");
                }
            }

            break;
        }
    }

    if (!found)
    {
        printf("Error: Student not found.\n");
    }
}

void Common(struct Student *arr, int size, char *s1, char *s2)
{
    int found1 = 0, found2 = 0;
    int common_courses = 0;

    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i].name, s1) == 0)
        {
            found1 = 1;
        }

        if (strcmp(arr[i].name, s2) == 0)
        {
            found2 = 1;
        }

        if (found1 && found2)
        {
            for (int j = 0; j < arr[i].num_of_courses; j++)
            {
                for (int k = i + 1; k < size; k++)
                {
                    for (int l = 0; l < arr[k].num_of_courses; l++)
                    {
                        if (strcmp(arr[i].arr[j].name, arr[k].arr[l].name) == 0)
                        {
                            common_courses++;
                            break;
                        }
                    }
                }
            }
            break;
        }
    }

    if (!found1 || !found2)
    {
        printf("Error: Student not found.\n");
    }
    else if (common_courses > 0)
    {
        printf("Number of common courses: %d\n", common_courses);
    }
    else
    {
        printf("No common courses found.\n");
    }
}



