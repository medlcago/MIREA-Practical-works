#include <stdio.h>
#include <math.h>
#include <windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char ch[2];
	double x, y, z;
	double numerator, denominator, element, result;

	printf("Введите x: ");
	scanf_s("%lf", &x);

	printf("Введите y: ");
	scanf_s("%lf", &y);

	printf("Введите z: ");
	scanf_s("%lf", &z);


	while ((getchar()) != '\n');
	printf("Введите символ: ");
	scanf_s("%s", &ch, 2);
	while ((getchar()) != '\n');

	numerator = exp(fabs(x - y)) * pow(fabs(x - y), x + y);
	denominator = atan(x) + atan(z);
	element = pow(pow(x, 6) + pow(log(y), 2), 1. / 3.);

	result = (numerator / denominator) + element;

	switch (ch[0])
	{
	case '+': 
	case '*': 
	case '-':
		if (x == -z || y <= 0)
		{
			printf("\nНе выполняется область допустимых значений!\n");
			break;
		}
		else
		{
			printf("%.3lf", result);
			break;
		}

	case '[': 
	case ']':
		printf("%.3lf", result);
		break;

	case '0':
		printf("\nВыполнено завершение работы программы.\n");
		return 0;

	default:
		printf("\nInvalid data!\n");
		return 700;
	}

	return 0;
}
