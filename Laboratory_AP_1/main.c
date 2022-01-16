#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "windows.h"
#include "math.h"

typedef int bool;
#define true 1
#define false 0

double solveFirst(double a, double b) {
    // x = |cos|a| + cos(b)|^(1-2sin^2(b))
    return pow(fabs(
                       cos(fabs(a)) + cos(b)),
               (1.0 - 2.0 * sin(b) * sin(b)));
}

double solveSecond(double a, double b) {
    // y = ln(b^(-sqrt(|a|))(a - b/2)
    return log(
            pow(b, -sqrt(
                    fabs(a))
                    )
            ) * (a - b/2.0);
}

bool isFirst(double a, double b) {
    if (fabs(a) > 1 || fabs(b) > 1) return false;
    return true;
}

bool isSecond(double b) {
    if (b == 0) return false;
    return true;
}

int main() {
    SetConsoleOutputCP(CP_UTF8); // ?
    setlocale(LC_ALL, "UTF8"); // ?

    char c1[16], c2[16], *s1, *s2;
    printf("Введите число A: \n");
    scanf("%s", c1);
    double a = strtod(c1, &s1);
    printf("Введите число B: \n");
    scanf("%s", c2);
    double b = strtod(c2, &s2);

    double x, y;
    if (isFirst(a, b)) x = solveFirst(a, b);
    else {
        printf("Значения не удовлетворяют ОДЗ первого выражения\n");
        return 1;
    }
    if (isSecond(b)) y = solveSecond(a, b);
    else {
        printf("Значение B не удовлетворяет ОДЗ второго выражения\n");
        return 2;
    }
    printf("X равен: %f, \nY равен: %f", x, y);
    return 0;
}
