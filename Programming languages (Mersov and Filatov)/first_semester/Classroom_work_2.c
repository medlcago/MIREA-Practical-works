#include <stdio.h>
#include <Windows.h>
#include <climits>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int arr[10][10]{};
	int new_arr[10]{};
	int n, m;
	int min_v = INT_MAX;
	int index_min_v = -1;

a1:
	printf("Введите n: ");
	scanf_s("%d", &n);
	if (n < 1 || n > 10) {
		printf("n должно быть числом в диапазоне от 1 до 10\n");
		goto a1;
	}

a2:
	printf("Введите m: ");
	scanf_s("%d", &m);
	if (m < 1 || m > 10) {
		printf("m должно быть числом в диапазоне от 1 до 10\n");
		goto a2;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("Введите значение элемента [%d][%d]: ", i, j);
			scanf_s("%d", &arr[i][j]);
		}
	}

	printf("Полученный двумерный массив:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	int prod = 1;
	bool flag = false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] > 0) {
				prod *= arr[i][j];
				flag = true;
			}
		}
		if (flag)
			new_arr[i] = prod;
		else {
			int k;
			printf("Отсутствуют положительные элементы в строке, введите номер строки: ");
			scanf_s("%d", &k);
			for (int j = 0; j < m; j++) {
				if (arr[k][j] > 0) {
					prod *= arr[k][j];
					flag = true;
				}
			}
			if (flag)
				new_arr[i] = prod;
			else {
				printf("Ошибка!\n");
				return 0;
			}
		}
		prod = 1;
		flag = false;
	}

	printf("\n\nПолученный одномерный массив:\n");
	for (int i = 0; i < n; i++)
		printf("%d ", new_arr[i]);

	for (int i = 0; i < n; i++) {
		if (new_arr[i] < min_v) {
			min_v = new_arr[i];
			index_min_v = i;
		}
	}

	printf("\n\nМинимальное значение = %d\nИндекс минимального значения = %d\n\n", min_v, index_min_v);

	if (index_min_v > 0) {
		printf("Элементы одномерного массива, позиции которых меньше позиции минимального элемента:\n");
		for (int i = 0; i < index_min_v; i++) {
			printf("%d ", new_arr[i]);
		}
	}
	else
		printf("Нет элементов, позиция которых меньше позиции минимального элемента.\n");

	return 0;

}
