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
    }
    
    // std::setiosflags(std::ios::left)
    // resetiosflags(std::ios::left)
    
    std::cout << "|"; std::cout.width(80); std::cout.fill('-'); std::cout << "|"; std::cout << std::endl; std::cout.fill(' ');
    std::cout.width(80); std::cout << std::setiosflags(std::ios::left) << "| Ведомость общественного транспорта" << std::resetiosflags(std::ios::left); std::cout.fill(' '); std::cout << "|"; std::cout << std::endl; 
    std::cout << "|"; std::cout.width(80); std::cout.fill('-'); std::cout << "|"; std::cout << std::endl; std::cout.fill(' ');
    std::cout << "| Вид транспорта | Маршрут | Протяженность маршрута (км) | Время в дороге (мин) |\n";
    std::cout << "|"; std::cout.width(80); std::cout.fill('-'); std::cout << "|"; std::cout << std::endl; std::cout.fill(' ');
    for (int i = 0; i < n; i++) {
        std::cout << "| " << std::setiosflags(std::ios::left) << std::setw(14) << transport[i].type << " | " << std::setw(7) << transport[i].route << " | " << std::setw(27) << transport[i].length << " | " << std::setw(20) << transport[i].time << " |\n" << std::resetiosflags(std::ios::left);
    }
    std::cout << "|"; std::cout.width(80); std::cout.fill('-'); std::cout << "|"; std::cout << std::endl; std::cout.fill(' ');
    std::cout.width(80); std::cout << std::setiosflags(std::ios::left) << "| Примечание: Тр - трамвай, Тс - троллейбус, А - автобус" << std::resetiosflags(std::ios::left); std::cout.fill(' '); std::cout << "|"; std::cout << std::endl; std::cout.fill(' ');
    std::cout << "|"; std::cout.width(80); std::cout.fill('-'); std::cout << "|"; std::cout << std::endl; std::cout.fill(' ');
    return 0;
}
