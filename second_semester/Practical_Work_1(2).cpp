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

void Draw(const Transport* transport, const unsigned int n) {
    constexpr int kLineWidth = 100;
    const std::string kLineSeparator(kLineWidth, '-');
    
    std::cout << "|" << kLineSeparator << "|" << std::endl;
    std::cout << "| " << std::left << std::setw(kLineWidth - 2) << "Ведомость общественного транспорта" << " |" << std::endl;
    std::cout << "|" << kLineSeparator << "|" << std::endl;
    std::cout << std::setiosflags(std::ios::left) << "| " << std::setw(17) << "Вид транспорта" << " | " << std::setw(12) << "Маршрут" << " | " << std::setw(27) << "Протяженность маршрута (км)" << " | " << std::setw(12) << "Время в дороге (мин)" << " | " << std::setw(11) << "Дата" << "|\n" << std::resetiosflags(std::ios::left);
    std::cout << "|" << kLineSeparator << "|" << std::endl;

    for (int i = 0; i < n; i++) {
        std::cout << std::setiosflags(std::ios::left) << "| " << std::setw(17) << transport[i].type << " | " << std::setw(12) << transport[i].route << " | " << std::setw(27) << std::setprecision(3) << std::fixed << transport[i].length << " | " << std::setw(21) << transport[i].time << "|" << std::setw(12) << transport[i].date << "|\n" << std::resetiosflags(std::ios::left);
        std::cout << "|" << kLineSeparator << "|" << std::endl;
    }

    std::cout << "| " << std::left << std::setw(kLineWidth - 2) << "Примечание: Тр - трамвай, Тс - троллейбус, А - автобус" << " |" << std::endl;
    std::cout << "|" << kLineSeparator << "|" << std::endl;
}

void InputData(Transport* transport, const unsigned n) {
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
        std::cin.ignore(32767, '\n');

        std::cout << "Введите дату: ";
        std::getline(std::cin, transport[i].date);
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    unsigned int n;
    std::cout << "Введите количество столбцов в таблице: ";
    std::cin >> n;
    Transport* transport = new Transport[n];
    
    std::cin.ignore(32767, '\n');
    
    std::cout << "Программа: Ведомость общественного транспорта\n";
    InputData(transport, n);
    Draw(transport, n);
    delete[] transport;
    return 0;
}
