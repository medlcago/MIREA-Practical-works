#include <stdio.h>
#include <math.h>
#include <windows.h>

double f(double x, double y, double z) {
    return ((exp(fabs(x - y)) * pow(fabs(x - y), x + y)) / (atan(x) + atan(z))) + pow(pow(x, 6) + pow(log(y), 2), 1. / 3.);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double x, y;
    double z = 15.221;


    printf("Введите x: ");
    scanf_s("%lf", &x);

    printf("Введите y: ");
    scanf_s("%lf", &y);


    if (y > 0 && x != -z) // atan(x) + atan(z) = 0  => (x = -z)
        printf("%.3lf\n", f(x, y, z));
    else
        printf("ERROR!\n");

    return 0;
}
