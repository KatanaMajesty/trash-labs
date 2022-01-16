#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define UNDEF -0xFFF

// null если граница = 0
int* get_rand_arr(int len, int _module_border) {
    int *arr = malloc(len * sizeof(int));
    for (int i = 0; i < len; i++)
        arr[i] = rand() % (_module_border * 2 + 1) - _module_border;
    if (_module_border == 0)
        free(arr);
    return _module_border == 0 ? NULL : arr;
}

int get_max(const int *arr, int len) {
    int max = UNDEF;
    for (int i = 0; i < len; i++) {
        if (max < arr[i]) max = arr[i];
    }
    return max;
}

int get_min(const int *arr, int len) {
    int min = -UNDEF;
    for (int i = 0; i < len; i++) {
        if (min > arr[i]) min = arr[i];
    }
    return min;
}

void print_arr(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%4d ", arr[i]);
    }
    printf("\n");
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    srand(time(NULL));
    int len_a, len_b;
    printf("Введите размеры массивов A и B через пробел соответственно:\n");
    if (scanf("%d %d", &len_a, &len_b) != 2) {
        printf("Не удалось присвоить как минимум одно из указанных значений (тип данных не является int)\n");
        return -0xFFF;
    }
    int _module_borderA, _module_borderB;
    printf("Введите верхнюю границу для массивов A и B через пробел соответственно:\n");
    if (scanf("%d %d", &_module_borderA, &_module_borderB) != 2) {
        printf("Не удалось присвоить как минимум одно из указанных значений (тип данных не является int)\n");
        return -0xFFF;
    }
    int *a = get_rand_arr(len_a, _module_borderA),
    *b = get_rand_arr(len_b, _module_borderB);
    printf("Массив A:\n");
    print_arr(a, len_a);
    printf("Массив B:\n");
    print_arr(b, len_b);
    int maxA = get_max(a, len_a);
    int minB = get_min(b, len_b);
    printf("Значение maxA: %d\nЗначение minB: %d\n", maxA, minB);
    double c = (maxA + minB) / 3.0;
    printf("C = (maxA + minB) / 3.\nОтвет: %.2f\n", c);

    free(a);
    free(b);
    return 0;
}
