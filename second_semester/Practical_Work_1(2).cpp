#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>

struct Transport
{
    std::string type;
    std::string route;
    float length;
    unsigned int time;
    std::string date;
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int n = 3;
    Transport transport[n];

    std::cout << "Программа: Ведомость общественного транспорта\n";

    for (int i = 0; i < n; i++) {
        std::cout << "\n" << i + 1 << " запись в таблице\n";
        std::cout << "Введите вид транспорта: ";
        std::getline(std::cin, transport[i].type);

        std::cout << "Введите маршрут: ";
        std::getline(std::cin, transport[i].route);
    a1:
        std::cout << "Введите протяженность маршрута (км): ";
        while (!(std::cin >> transport[i].length)) {
            std::cout << "Неверные данные! Пожалуйста, введите еще раз!\n";
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            goto a1;
        }
        std::cin.ignore(32767, '\n');

    a2:
        std::cout << "Введите время в дороге (мин): ";
        while (!(std::cin >> transport[i].time)) {
            std::cout << "Неверные данные! Пожалуйста, введите еще раз!\n";
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            goto a2;
        }
        std::cin.ignore(32767, '\n');;

        std::cout << "Введите дату: ";
        std::getline(std::cin, transport[i].date);

    }

    // std::setiosflags(std::ios::left)
    // resetiosflags(std::ios::left)

    std::cout << "|"; std::cout.width(100); std::cout.fill('-'); std::cout << "|"; std::cout << std::endl; std::cout.fill(' ');
    std::cout.width(100); std::cout << std::setiosflags(std::ios::left) << "| Ведомость общественного транспорта" << std::resetiosflags(std::ios::left); std::cout.fill(' '); std::cout << "|"; std::cout << std::endl;
    std::cout << "|"; std::cout.width(100); std::cout.fill('-'); std::cout << "|"; std::cout << std::endl; std::cout.fill(' ');
    std::cout << std::setiosflags(std::ios::left) << "| " << std::setw(17) << "Вид транспорта" << " | " << std::setw(12) << "маршрута" << " | " << std::setw(27) << "Протяженность маршрута (км)" << " | " << std::setw(12) << "Время в дороге (мин)" << " | " << std::setw(10) << "Дата" << "|\n" << std::resetiosflags(std::ios::left);
    std::cout << "|"; std::cout.width(100); std::cout.fill('-'); std::cout << "|"; std::cout << std::endl; std::cout.fill(' ');
    for (auto& x : transport) {
        std::cout << std::setiosflags(std::ios::left) << "| " << std::setw(17) << x.type << " | " << std::setw(12) << x.route << " | " << std::setw(27) << std::setprecision(3) << std::fixed << x.length << " | " << std::setw(21) << x.time << "|" << std::setw(11) <<  x.date << "|\n" << std::resetiosflags(std::ios::left);
        std::cout << "|"; std::cout.width(100); std::cout.fill('-'); std::cout << "|"; std::cout << std::endl; std::cout.fill(' ');
    }
    std::cout.width(100); std::cout << std::setiosflags(std::ios::left) << "| Примечание: Тр - трамвай, Тс - троллейбус, А - автобус" << std::resetiosflags(std::ios::left); std::cout.fill(' '); std::cout << "|"; std::cout << std::endl; std::cout.fill(' ');
    std::cout << "|"; std::cout.width(100); std::cout.fill('-'); std::cout << "|"; std::cout << std::endl; std::cout.fill(' ');
    return 0;
}
