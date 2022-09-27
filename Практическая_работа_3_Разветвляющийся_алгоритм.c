#include <stdio.h>
#include <math.h>
#include <windows.h>

double f(double x, double y, double z) {
    return 5 * atan(x) - 1. / 4. * acos(x) * ((x + 3 * fabs(x - y) + pow(x, 2)) / (fabs(x - y) * z + pow(x, 2)));
}

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

    if ((fabs(x - y) * z + pow(x, 2) != 0) && (x >= -1 && x <= 1))
        printf("%.3lf", f(x, y, z));
    else
        printf("ERROR!\n");

    return 0;
}
