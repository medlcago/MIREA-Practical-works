#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <Windows.h>

struct Date {
    std::string day;
    std::string month;
    std::string year;
};

struct Record
{
    std::string type;
    std::string route;
    float length;
    unsigned int time;
    Date date;
};

void Draw(const Record* transport, const unsigned int n) {
    constexpr int kLineWidth = 100;
    const std::string kLineSeparator(kLineWidth, '-');

    std::cout << "|" << kLineSeparator << "|" << std::endl;
    std::cout << "| " << std::left << std::setw(kLineWidth - 2) << "Ведомость общественного транспорта" << " |" << std::endl;
    std::cout << "|" << kLineSeparator << "|" << std::endl;
    std::cout << std::setiosflags(std::ios::left) << "| " << std::setw(17) << "Вид транспорта" << " | " << std::setw(12) << "Маршрут" << " | " << std::setw(27) << "Протяженность маршрута (км)" << " | " << std::setw(12) << "Время в дороге (мин)" << " | " << std::setw(11) << "Дата" << "|\n" << std::resetiosflags(std::ios::left);
    std::cout << "|" << kLineSeparator << "|" << std::endl;

    for (int i = 0; i < n; i++) {
        std::cout << std::setiosflags(std::ios::left) << "| " << std::setw(17) << transport[i].type << " | " << std::setw(12) << transport[i].route << " | " << std::setw(27) << std::setprecision(3) << std::fixed << transport[i].length << " | " << std::setw(21) << transport[i].time << "|" << std::setw(12) << transport[i].date.day + "." + transport[i].date.month + "." + transport[i].date.year << "|\n" << std::resetiosflags(std::ios::left);
        std::cout << "|" << kLineSeparator << "|" << std::endl;
    }

    std::cout << "| " << std::left << std::setw(kLineWidth - 2) << "Примечание: Тр - трамвай, Тс - троллейбус, А - автобус" << " |" << std::endl;
    std::cout << "|" << kLineSeparator << "|" << std::endl;
}

void InputData(Record* transport, const unsigned n) {
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
        std::getline(std::cin, transport[i].date.day, '.');
        std::getline(std::cin, transport[i].date.month, '.');
        std::getline(std::cin, transport[i].date.year);
    }
}

void AddData(Record* transport, const unsigned int n) {
    float min_length = transport[0].length;
    unsigned int min_time = transport[0].time;
    for (int i = 1; i < n; i++) {
        if (transport[i].length < min_length) {
            min_length = transport[i].length;
        }
        if (transport[i].time < min_time) {
            min_time = transport[i].time;
        }
    }

    transport[n].type = "Тр";
    transport[n].route = "26y";
    transport[n].length = min_length;
    transport[n].time = min_time;
    transport[n].date.day = "28";
    transport[n].date.month = "02";
    transport[n].date.year = "2023";
}

class Node{
public:
    Record* data;
    Node* next;
public:
    Node(Record* data) {
        this->data = data;
        this->next = NULL;
    }
};

class OneLinkedList {
public:
    Node* head, * tail;
public:
    OneLinkedList() {
        this->head = this->tail = NULL;
    }

    ~OneLinkedList() {
        while (head != NULL)
            pop_front();
    }

    void push_front(Record* data) { // Добавляем элемент в начало списка
        Node* node = new Node(data);
        node->next = head;
        head = node;
        if (tail == NULL) tail = node;
    }

    void push_back(Record* data) { // Добавляем элемент в конец списка
        Node* node = new Node(data);
        if (head == NULL) head = node;
        if (tail != NULL) tail->next = node;
        tail = node;
    }

    void pop_front() { // Удаляем первый элемент в списке
        if (head == NULL) return;
        if (head == tail) {
            delete tail;
            head = tail = NULL;
            return;
        }

        Node* node = head;
        head = node->next;
        delete node;
    }

    void pop_back() { // Удаляем последний элемент в списке
        if (tail == NULL) return;
        if (head == tail) {
            delete tail;
            head = tail = NULL;
            return;
        }

        Node* node = head;
        for (; node->next != tail; node = node->next);
        node->next = NULL;
        delete tail;
        tail = node;
    }

    Node* getAt(int k) { // Получаем элемент списка по индексу k
        if (k < 0) return NULL;
        Node* node = head;
        int n = 0;
        while (node && n != k && node->next) {
            node = node->next;
            n++;
        }
        return (n == k) ? node : NULL;
    }

    void insert(int k, Record* data) { // Вставляем элемент в список по индексу k
        if (k > 0)
        {
            Node* left = getAt(k - 1);
            if (left == NULL) return;

            Node* node = new Node(data);
            node->next = left->next;

            if (left->next == NULL) tail = node;
            left->next = node;
        }
        else if (k == 0)
            push_front(data);
    }

    void erase(int k) { // Удаляем элемент в списке по индексу k
        if (k < 0) return;
        if (k == 0) {
            pop_front();
            return;
        }

        Node* left = getAt(k - 1);
        Node* node = left->next;
        if (node == NULL) return;
        Node* right = node->next;
        left->next = right;
        if (node == tail) tail = left;
        delete node;
    }
};

void Zadanie_1(Record* transport, unsigned int n) {
    std::cout << "Программа: Ведомость общественного транспорта\n";
    InputData(transport, n);
    std::cout << std::endl;
}

void Prak_1(Record* transport, unsigned int n) {
    Draw(transport, n);
    AddData(transport, n);
    Draw(transport, n + 1);
}

void Prak_2(Record* transport, unsigned int n){
    Record* A = new Record[n + 1];

    std::copy(transport, transport + n + 1, A);

    Record* B = new Record[n + 1];
    std::copy(A, A + n + 1, B);

    // выводим на экран адреса первого элемента массива Тable, массива А и массива В
    std::cout << "Table: " << transport << std::endl;
    std::cout << "A: " << A << std::endl;
    std::cout << "B: " << B << std::endl << std::endl;

    std::cout << std::setw(20) << "Address A" << std::setw(20) << "Value A" << std::setw(20) << "Address B" << std::setw(20) << "Value B" << std::endl;
    for (int i = 0; i < n; i++)
        std::cout << std::setw(20) << &A[i] << std::setw(20) << A[i].type << std::setw(20) << &B[i] << std::setw(20) << B[i].type << std::endl;
    delete[] A;
    delete[] B;
}

void Prak_3() {
    OneLinkedList list;
    list.push_back(new Record);
    list.push_front(new Record);
    list.push_back(new Record);
    list.insert(1, new Record);
    list.push_back(new Record);
    list.erase(2);

    std::cout << std::endl << "Адреса значений списка в памяти:" << std::endl;

    for (Node* node = list.head; node != NULL; node = node->next)
        std::cout << node->data << "\n";
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    unsigned int n;
    std::cout << "Введите количество строк в таблице: ";
    std::cin >> n;
    Record* Table = new Record[n + 1];

    std::cin.ignore(32767, '\n');

    Zadanie_1(Table, n);
    Prak_1(Table, n);
    Prak_2(Table, n);
    Prak_3();

    // Record* A = (Record*)std::malloc((n + 1) * sizeof(Record));
    delete[] Table;
    return 0;
}
