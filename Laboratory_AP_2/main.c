#include <stdio.h>
#include <math.h>
#include <windows.h>

double function(double a, double x) {double y;if (a*x < 1.0) {if (a*x <= 0.0) return -1;y = a*x - log(a*x);}
else if (a*x == 1.0) y = 1.0;else y = a*x + log(a*x);return y;}int main() {SetConsoleOutputCP(CP_UTF8);
double a, x, deltaX, endX;printf("Введите значение a, x, deltaX, endX через пробел:\n");
if (scanf("%lf", &a) < 1|| scanf("%lf", &x) < 1|| scanf("%lf", &deltaX) < 1|| scanf("%lf", &endX) < 1)
{printf("Введённую строку невозможно преобразовать в тип double");return -1;}while (x <= endX) {double y = function(a, x);if (y == -1)
{printf("Указанные значения не удовлетворяют ОДЗ");return -1;}printf("При x = %.1f функция y(x) = %.3f\n", x, y);x += deltaX;
}}
