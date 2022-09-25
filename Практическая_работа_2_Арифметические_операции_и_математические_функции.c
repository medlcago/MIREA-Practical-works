#include <stdio.h>
#include <math.h>
#include <windows.h>

double f(double x, double y, double z) {
	return ((exp(fabs(x - y)) * pow(fabs(x - y), x + y)) / (atan(x) + atan(z))) + pow(pow(x, 6) + pow(log(y), 2), 1./3.);
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

	printf("%.3lf", f(x, y, z));

	return 0;
}
