#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define UNDEF -0xFFF

// -0xFFF if param = 0
double getRandNum(int _moduleRange) {
    int r = rand(),
    sign = r % 2 == 0 ? -1 : 1;
    double div = _moduleRange * 10;
    return _moduleRange == 0 ?
        -0xFFF : (r % (_moduleRange * 100)) / 100.0 * sign;
}

// возвращает количество успешно записанных элементов
// NULL если указатель не равен NULL
double** matrix(double **_null_matr, unsigned int n, int _moduleRange) {
    if (_null_matr != NULL)
        return NULL;

    int i, j;
    _null_matr = malloc(n * sizeof(double*));
    for (i = 0; i < n; i++)
        _null_matr[i] = malloc(n * sizeof(double));
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            double b = getRandNum(_moduleRange);
            _null_matr[i][j] = b == UNDEF ? 0 : b;
        }
    }
    return _null_matr;
}

double getBottomMax(double **matr, unsigned int n) {
    double max = UNDEF;
    for (int i = 0; i < n; i++) {
        b: for (int j = 0; j < n; j++) {
            if (i == j) {
                if (i++ == n - 1) return max;
                goto b;
            }
            if (matr[i][j] > max)
                max = matr[i][j];
        }
    }
    return max;
}

// вернёт -0xFFF если нет ни одного элемента в верхней части матрицы, которая превысит максимум нижней части
double getSum(double _matr_bottom_max, double **matr, unsigned int n) {
    double s = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (matr[i][j] <= _matr_bottom_max) continue;
            s += matr[i][j];
        }
    }
    return s == 0 ? -0xFFF : s;
}

int clean(double** arr, unsigned int n) {
    int i;
    for (i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    return i + 1;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    srand(time(NULL));
    int n;
    int _moduleRange;
    printf("Введите размерность матрицы и значение её максимального элемента через пробел:\n");
    if (scanf("%d %d", &n, &_moduleRange) != 2) {
        printf("Не удалось присвоить как минимум одну переменную из-за несоответствия типов данных.\n");
        return -0xFFF;
    }
    if (n < 0 || _moduleRange < 0) {
        printf("Введённые значения меньше нуля!\n");
        return -0xFFF;
    }
    double** matr = matrix(NULL, n, _moduleRange);
    printf("Создана новая матрица %dx%d с максимальным значением %d:\n", n, n, _moduleRange);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%6.2f ", matr[i][j]);
        }
        printf("\n");
    }
    double max = getBottomMax(matr, n);
    printf("Найден максимальный элемент ниже главной диагонали: %.2f\n", max);
    double sum = getSum(max, matr, n);
    printf(sum == UNDEF ? "Нет ни одного элемента выше главной диагонали, который больше всех элементов ниже.\n"
                            : "Сумма всех элементов матрицы на главной диагонали и выше, "
                               "которые превышают максимальный элемент: %.2f\n", sum);
    clean(matr, n);
    return -1;
}
