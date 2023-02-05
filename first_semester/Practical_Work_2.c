#include <stdio.h>
#include <math.h>
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double x, y, z;

    printf("Введите x: ");
    scanf_s("%lf", &x);

    printf("Введите y: ");
    scanf_s("%lf", &y);

    printf("Введите z: ");
    scanf_s("%lf", &z);

    double f = ((exp(fabs(x - y)) * pow(fabs(x - y), x + y)) / (atan(x) + atan(z))) + pow(pow(x, 6) + pow(log(y), 2), 1. / 3.);

    printf("%.3lf", f);

    return 0;
}
