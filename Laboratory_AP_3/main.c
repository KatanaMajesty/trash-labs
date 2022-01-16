#include <stdio.h>
#include <windows.h>
#include <math.h>

// задание 2а
// Функция получения суммы элементов массива
/**
 *
 * @param arr массив длинны _len
 * @param _len длинна массива
 * @return сумма элементов массива
 */
int getSum(const int *arr, int _len) {
    int sum = 0;
    for (int i = 0; i < _len; i++)
        sum += arr[i];
    return sum;
}

// задание 2б
double getProduct(const int *arr, int _len) {
    double p = 1;
    for (int i = 0; i < _len; i++) {
        if (arr[i] == 1) {
            printf("x[%d] = 1, не удовлетворяет ОДЗ", i);
            return 0.0;
        }
        int x = arr[i];
        p *= x*x / (1.0 - x); // -4 * 1/2 * -4.5
    }
    return p;
}

// задание 2в
/**
 * @return число комбинаций из m по n
 */
int getCombinations(int m, int n) {
    int fact = 1, a = m - 1;
    while (a >= n + 1) m *= a--;
    for (int i = 2; i <= n; i++) fact *= i;
    return m / fact;
}

// задание 3
// функция получения минимального значения массива
/**
 *
 * @param arr массив длинны _len
 * @param _len длинна массива
 * @return минимальное значение массива
 */
int getMin(const int *arr, int _len) {
    int min = arr[0];
    for (int i = 1; i < _len; i++)
        if (arr[i] < min) min = arr[i];
    return min;
}

// TODO не вторая часть
// задание 5
void seriesSum(double eps, double x) {
    // часть 1
    if (fabs(x) >= 1) {
        printf("|x| > 1. Завершение 5 задания невозможно");
        return;
    }
    double s = pow(1 - x, -1.0/3.0);

    // часть 2
    double s_eps = 1, l_num_u = 1.0, l_num_b = 3.0;
    int n = 1;
    while (fabs((s_eps += s_eps * x * l_num_u / l_num_b) + eps) < fabs(s)) {
        l_num_u += 3.0;
        l_num_b += 3.0;
        n++;
    }
    printf("S = %f\nS_eps = %f\nn = %d\neps = %f\n======\n", s, s_eps, n, eps);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    const double eps1 = 0.01, eps2 = 0.0001;

    int n;
    printf("Введите количество итераций n (int):\n");
    if (scanf("%d", &n) < 1) {
        printf("Введённые данные невозможно преобразовать в int\n");
        return -1;
    }
    int arr[n];
    int counter = 0;
    printf("Введите %d элементов массива через пробел:\n", n);
    while (counter < n)
        if (scanf("%d", &arr[counter++]) < 1) {
            printf("Элемент по номеру %d не соответствует типу массива (int)", counter);
            return -1;
        }
    printf("Сумма элементов массива: %d\n", getSum(arr, n)); // получаю сумму значения массива
    printf("Результат умножения: %.2f\n", getProduct(arr, n)); // получаю произведение
    printf("Число комбинаций: %d\n", getCombinations(6, 3)); // получаю число комбинаций
    printf("Минимальное значение массива: %d\n", getMin(arr, n)); // получаю минимальное значение массива

    seriesSum(eps1, 0.2);
    seriesSum(eps2, 0.2);
}

