#include <stdio.h>
#include <math.h>
#include <windows.h>

double fun(double a, double x, double e) {
    double nY = (a + (x / a)) / 2;
    printf("a: %.10f\n", nY);
    if (fabs(nY*nY - a*a) < e) {
        return nY;
    }
    return fun(nY, x, e);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    double a, x, e;
    printf("Введите значения a, x, e через пробел (тип double):\n");
    if (scanf("%lf %lf %lf", &a, &x, &e) != 3) {
        printf("Как минимум одно значение было указано неверно (не удалось преобразовать в double).\n");
        exit(EXIT_FAILURE);
    }
    if (a <= 0 || x <= 0 || e <= 0) {
        printf("Как минимум одно из указанных значений меньше нуля.\n");
        exit(EXIT_FAILURE);
    }
    printf("Ответ: %.8f\n", fun(a, x, e));
    return 0;
}
