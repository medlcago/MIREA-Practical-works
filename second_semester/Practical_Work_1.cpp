#include <iostream>
#include <Windows.h>
#include <string>


struct Student {
	std::string fullname;
	int mathematics;
	int physics;
	int drawing;
	int chemistry;
	int sopromat;
};

struct Average_scores {
	double mathematics = 0;
	double physics = 0;
	double drawing = 0;
	double chemistry = 0;
	double sopromat = 0;
};


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	double top_score = 0;
	std::string title;
	std::cout << "Введите количество студентов: ";
	std::cin >> n;

	Student *student = new Student[n];
	Average_scores average_scores;


	for (int i = 0; i < n; i++) {
		std::cin.ignore(32767, '\n');
		
		std::cout << "[" << i + 1 << "] " << "Введите Ф.И.О: ";
		getline(std::cin, student[i].fullname);

		std::cout << "[" << i + 1 << "] " << "Оценка за математику: ";
		std::cin >> student[i].mathematics;
		average_scores.mathematics += ((double)student[i].mathematics / n);

		std::cout << "[" << i + 1 << "] " << "Оценка за физику: ";
		std::cin >> student[i].physics;
		average_scores.physics += ((double)student[i].physics / n);

		std::cout << "[" << i + 1 << "] " << "Оценка за черчение: ";
		std::cin >> student[i].drawing;
		average_scores.drawing += ((double)student[i].drawing / n);

		std::cout << "[" << i + 1 << "] " << "Оценка за химию: ";
		std::cin >> student[i].chemistry;
		average_scores.chemistry += ((double)student[i].chemistry / n);

		std::cout << "[" << i + 1 << "] " << "Оценка за сопромат: ";
		std::cin >> student[i].sopromat;
		average_scores.sopromat += ((double)student[i].sopromat / n);

		std::cout << '\n';
	}
	
	std::cout << "Средняя оценка за математику: " << average_scores.mathematics << std::endl;
	std::cout << "Средняя оценка за физику: " << average_scores.physics << std::endl;
	std::cout << "Средняя оценка за черчение: " << average_scores.drawing << std::endl;
	std::cout << "Средняя оценка за химию: " << average_scores.chemistry << std::endl;
	std::cout << "Средняя оценка за сопромат: " << average_scores.sopromat << std::endl;

	if (average_scores.mathematics > top_score) {
		top_score = average_scores.mathematics;
		title = "Математика";
	}

	if (average_scores.physics > top_score) {
		top_score = average_scores.physics;
		title = "Физика";
	}

	if (average_scores.drawing > top_score) {
		top_score = average_scores.drawing;
		title = "Черчение";
	}

	if (average_scores.chemistry > top_score) {
		top_score = average_scores.chemistry;
		title = "Химия";
	}

	if (average_scores.sopromat > top_score) {
		top_score = average_scores.sopromat;
		title = "Сопромат";
	}
	
	delete[] student;
	std::cout << "\nПредмет, который был сдан группой лучше всего: " << title << "\n";
	return 0;
}
