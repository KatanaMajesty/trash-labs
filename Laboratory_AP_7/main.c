#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int n;
    printf("Введите количество элементов последовательности.\n");
    if (scanf("%d", &n) != 1) {
        printf("Значение было указано неверно (тип не равен int)\n");
        return -1;
    }
    double *arr = malloc(n * sizeof(double));
    printf("Введите %d элементов последовательности через пробел:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%lf", &arr[i]) != 1) {
            printf("%d значение было указанно неверно (тип не равен double).\n", i + 1);
            return -1;
        }
    }
    double max = 0;
    for (int i = 0; i < n; i++) {
        double a = fabs(arr[i]) <= 2 ? fabs(arr[i]) : 0.5;
        if (max < a)
            max = a;
    }
    printf("Максимальное значение: %.3f\n", max);
    return 0;
}
