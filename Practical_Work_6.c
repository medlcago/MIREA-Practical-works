#include <stdio.h>
#include <Windows.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int arr[20];
	int n;

a1:
	printf("Введите длину массива (5-20): ");
	scanf_s("%d", &n);
	if (n > 20 || n < 5)
	{
		printf("\nДлина должна быть числом в диапазоне от 5 до 20\n");
		goto a1;
	}

	for (int i = 0; i < n; i++) {
a2:
		printf("\nВведите значение элемента a[%d] = ", i);
		scanf_s("%d", &arr[i]);
		if (arr[i] < -100 || arr[i] > 100)
		{
			printf("\nДиапазон значения должен быть от -100 до 100\n");
			goto a2;
		}
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] < arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	printf("\nОтсортированный массив:\n");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	return 0;
}
