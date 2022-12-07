#include <stdio.h>
#include <Windows.h>

void print_strrev(char* buf) {
	if (*buf) {
		print_strrev(buf + 1);
		printf("%c", *buf);
	}
}


void string_backwards(char s[]) {
	int str_len = 0;
	while (s[str_len] != '\0')
		str_len++;

	for (int i = 0, j = str_len - 1; i < j; i++, j--) {
		int temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char s[30];
	int k;
	
	printf("Введите строку: ");
	gets_s(s);
	printf("\nВы ввели: %s\n\n", s);
a1:
	printf("Выберите способ решения:\n1. Используя традиционную обработку массивов\n2. Используя адресную арифметику.\n\n");
	scanf_s("%d", &k);
	
	switch (k) {
		case 1:
			string_backwards(s);
			printf("\nСтрока наоборот: %s\n", s);
			break;
		case 2:
			printf("\nСтрока наоборот: ");
			print_strrev(s);
			break;
		default:
			printf("\nВведенного способа решения не существует.\n\n");
			goto a1;
	}

	return 0;
}
