#include <stdio.h>
#include <Windows.h>
#include <malloc.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int max_1 = INT_MIN;
	int max_2 = INT_MIN;

	int index = -1;

	int* arr;
	int n;
	printf("Введите n: ");
	scanf_s("%d", &n);

	arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		printf("arr[%d] = ", i + 1);
		scanf_s("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] > max_1) {
			max_1 = arr[i];
			index = i;
		}
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] > max_2 && arr[i] <= max_1 && index != i)
			max_2 = arr[i];
	}

	free(arr);
	arr = 0;

	printf("max_1 = %d\nmax_2 = %d", max_1, max_2);

	return 0;
}
