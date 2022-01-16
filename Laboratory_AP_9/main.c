#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define STUDS 5;
#define AVG_SCHOLAR 2200

struct Student
{
    char surname[32];
    int scholarship;
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    srand(time(NULL));
    int n = STUDS;
    struct Student empty = {"null", -1};
    struct Student *students = malloc(n * sizeof(struct Student));
    for (int i = 0; i < n; i++) {
        char surname[32];
        int scholar;
        printf("Введите фамилию и стипендию для %d студента через пробел:\n", i + 1);
        if (scanf("%s %d", surname, &scholar) != 2) {
            printf("Ошибка\n");
            return -0xFFF;
        }
        strcpy(students[i].surname, surname);
        students[i].scholarship = scholar;
    }

    for (int i = 0; i < n; i++) {
        if (students[i].scholarship < AVG_SCHOLAR)
            students[i] = empty;
        else printf("Студент %d: %s, Стипендия: %d\n", i + 1, students[i].surname, students[i].scholarship);
    }
    free(students);
    return 0;
}
