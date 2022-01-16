#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void printMatrix(int **arr, int len) {
    int i, j, counter = 1;
    while (counter <= len) {
        i = 0, j = counter - 1;
        if ((i + j) % 2 == 0)
            while (i < counter) printf("%d, ", arr[i++][j--]);
        else
            while (i < counter) printf("%d, ", arr[j--][i++]);
        counter++;
    }
    counter = len;
    while (counter > 0) {
        i = len - counter + 1, j = len - 1;
        if ((i + j) % 2 == 0) {
            while (i < len) printf("%d, ", arr[i++][j--]);
        } else {
            while (i < len) printf("%d, ", arr[j--][i++]);
        }
        counter--;
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int n;
    printf("Введите количество строк и столбцов квадратной матрицы:\n");
    if (scanf("%d", &n) != 1) { // количество успешно присвоенных значений
        printf("Указан неверный тип данных (ожидался int)\n");
        exit(EXIT_FAILURE);
    }
    // динамическое выделение памяти
    int **arr = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        arr[i] = malloc(n * sizeof(int));

    // заполняю массив рандомными числами
    srand(time(NULL));
    printf("Матрица %d на %d, рандомно заполненная числами до 100:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = rand() % 100 + 1;
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }

    // Вызываю функцию
    printf("\nВывод элементов матрицы змейкой параллельно побочной диагонали:\n");
    printMatrix(arr, n);
    for (int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);
}
