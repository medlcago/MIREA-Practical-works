#include <iostream>
#include <Windows.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	std::cout << "Введите n: ";
	std::cin >> n;
	int* a = new int[n];
	int* b = new int[n];
	int c_a = 0, c_b = 0;

	for (int i = 0; i < n; i++) {
		std::cout << "Введите элемент массива А[" << i << "]: ";
		std::cin >> a[i];
		if (a[i] < 0)
			c_a++;

		std::cout << "Введите элемент массива B[" << i << "]: ";
		std::cin >> b[i];
		if (b[i] < 0)
			c_b++;

		std::cout << "\n";
	}

	std::cout << "\nКоличество отрицательных элементов в двух массивах: " << c_a + c_b << "\n";

	if (c_a < c_b) {
		for (int i = 0; i < n; i++)
			std::cout << a[i] << " ";
	}
	else {
		for (int i = 0; i < n; i++)
			std::cout << b[i] << " ";
	}
	
	delete[] a;
	delete[] b;

	return 0;
}
