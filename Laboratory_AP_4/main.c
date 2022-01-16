#include <stdio.h>
#include <malloc.h>
#include <windows.h>

void fun(int *arr, int len) {
    // get max
    int maxIndex = 0;
    for (int i = 1; i < len; i++)
        if (arr[i] > arr[maxIndex]) maxIndex = i;
    // multiply
    for (int i = 1; i < maxIndex; i += 2)
        arr[i] *= arr[maxIndex];
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int *arr, len;
    printf("Введите длину массива:\n");
    if (scanf("%d", &len) < 1) {
        printf("Указан неверный тип данных. Нужно число\n");
        exit(EXIT_FAILURE);
    }
    arr = malloc(len * sizeof(int));
    printf("Введите %d элементов массива через пробел:\n", len);
    for (int i = 0; i < len; i++) {
        if (scanf("%d", &arr[i]) < 1) exit(EXIT_FAILURE);
    }
    fun(arr, len);
    for (int i = 0; i < len; i++) printf("%d ", arr[i]);
    free(arr);
    return 0;
}
