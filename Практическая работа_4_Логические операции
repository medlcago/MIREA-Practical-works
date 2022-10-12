#include <iostream>
#include <stdio.h>
#include <Windows.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

m1:
	printf("Введите 1 для запуска программы, либо 0 для завершения\n");
	int k;
	scanf_s("%d", &k);

	switch (k) {
	case 1: {
		double x, y;
		printf("Input x >> ");
		scanf_s("%lf", &x);

		printf("Input y >> ");
		scanf_s("%lf", &y);

		printf("x = %lf; y = %lf\n", x, y);

		if ((x >= -2) && (x <= -1) && (y <= 0) && (y >= -1.5) || (x <= 2) && (x >= 1) && (y <= 0) && (y >= -1.5) || (x >= -2) && (x <= 2) && (y <= -1) && (y >= -1.5) || (x >= -1) && (x <= 1) && (y >= 0) && (y <= 1))
		{
			printf("Точка попадает в область\n");
		}

		else
		{
			printf("Точка не попадает в область\n");
		}
		goto m1;
	}

	case 0: break;

	}
}
