#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <Windows.h>

constexpr int kLineWidth = 100;
const std::string kLineSeparator(kLineWidth, '-');

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
    Record r1 = { "Тр", "26у", min_length, min_time, {"28", "02", "2023"} };
    transport[n] = r1;
}

class Node {
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


class clDate
{
private:
    std::string year;
    std::string month;
    std::string day;
public:
    clDate()
    {
        std::cout << "\nВызов конструктора класса clDate со значениями по умолчанию\n";
        setDate("05", "04", "2023");
    }

    clDate(std::string _day, std::string _month, std::string _year)
    {
        std::cout << "\nВызов конструктора класса clDate с тремя параметрами\n";
        setDate(_day, _month, _year);
    }

    clDate(Date* pD)
    {
        std::cout << "\nВызов конструктора класса clDate с параметром Date* pD\n";
        setDate(pD);
    }

    clDate(Date mD) {
        std::cout << "\nВызов конструктора класса clDate с параметром Date mD\n";
        setDate(mD);
    }

    ~clDate() {
        ;
    }

    void setDate(Date* _mD)
    {
        setDate(_mD->day, _mD->month, _mD->year);
    }

    void setDate(Date _mD)
    {
        setDate(_mD.day, _mD.month, _mD.year);
    }

    void setDate(std::string _day, std::string _month, std::string _year)
    {
        this->day = _day;
        this->month = _month;
        this->year = _year;
    }

    Date getDate()
    {
        Date MD;
        MD.day = day;
        MD.month = month;
        MD.year = year;
        return MD;
    }

    void setDay(std::string _day) { day = _day; }
    void setMonth(std::string _month) { month = _month; }
    void setYear(std::string _year) { year = _year; }

    std::string getDay() { return day; }
    std::string getMonth() { return month; }
    std::string getYear() { return year; }

    void printDate() {
        std::cout << this->getDay() << "." << this->getMonth() << "." << this->getYear() << std::endl;
    }
};

class сlRecord {
    std::string type;
public:
    std::string route;
private:
    float length;
protected:
    unsigned int time;
    Date date;
public:

    сlRecord() {
        std::cout << "\nВызов конструктора класса сlRecord со значениями по умолчанию\n";
        setRecord("Тр", "12", 27.550, 75, Date{ "03", "04", "2022" });
    }

    сlRecord(std::string _type, std::string _route, float _length, unsigned _time, Date _date) {
        std::cout << "\nВызов конструктора класса сlRecord с пятью параметрами\n";
        setRecord(_type, _route, _length, _time, _date);
    }

    сlRecord(Record* record) {
        std::cout << "\nВызов конструктора класса сlRecord с параметром Record* record\n";
        setRecord(record->type, record->route, record->length, record->time, record->date);
    }

    сlRecord(Record record) {
        std::cout << "\nВызов конструктора класса сlRecord с параметром Record record\n";
        setRecord(record.type, record.route, record.length, record.time, record.date);
    }

    ~сlRecord() {
        ;
    }

    void setRecord(std::string _type, std::string _route, float _length, unsigned _time, Date _date) {
        this->type = _type;
        this->route = _route;
        this->length = _length;
        this->time = _time;
        this->date = _date;
    }

    void setType(std::string _type) { type = _type; }
    void setRoute(std::string _route) { route = _route; }
    void setLength(float _length) { length = _length; }
    void setTime(unsigned _time) { time = _time; }
    void setDate(Date _date) { date = _date; }

    std::string getType() { return type; }
    std::string getRoute() { return route; }
    float getLength() { return length; }
    unsigned getTime() { return time; }
    Date getDate() { return date; }

    void printRecord() {
        Record record{ getType(), getRoute(), getLength(), getTime(), getDate() };
        Draw(&record, 1);
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

void Prak_2(Record* transport, unsigned int n) {
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

void Prak_4(Record* transport) {
    // 1. Текстовый формат

    // записать 3 записи (три строки (records) из таблицы в файл в текстовом формате
    std::ofstream file_ofstream;
    file_ofstream.open("Korolev.txt");
    if (!file_ofstream.is_open()) {
        std::cout << "Ошибка открытия файла." << std::endl;
    }
    else {
        for (int i = 0; i < 3; i++) {
            file_ofstream << transport[i].type << " " << transport[i].route << " " << transport[i].length << " " << transport[i].time << " " << transport[i].date.day << " " << transport[i].date.month << " " << transport[i].date.year;
            file_ofstream << "\n";
        }
    }
    file_ofstream.close();

    // считать 3 записи из файла в текстовом формате и отобразить.
    std::ifstream file_ifstream;
    Record readRecords[3];
    file_ifstream.open("Korolev.txt");
    if (!file_ifstream.is_open()) {
        std::cout << "Ошибка открытия файла." << std::endl;
    }
    else {
        for (int i = 0; i < 3; i++) {
            file_ifstream >> readRecords[i].type >> readRecords[i].route >> readRecords[i].length >> readRecords[i].time >> readRecords[i].date.day >> readRecords[i].date.month >> readRecords[i].date.year;
        }
    }
    file_ifstream.close();
    std::cout << "\n\nТаблица из текстового файла:\n\n";
    Draw(readRecords, 3);

    // 2. Бинарный формат

    // записать 3 записи (три строки (records) из таблицы в файл в бинарном формате.
    std::ofstream file_ofstream_binary;
    file_ofstream_binary.open("Korolev.bin", std::ios::binary);
    if (!file_ofstream_binary.is_open()) {
        std::cout << "Ошибка открытия файла." << std::endl;
    }
    else {
        for (int i = 0; i < 3; i++) {
            // Записываем transport[i].type
            size_t len = transport[i].type.length();
            file_ofstream_binary.write(reinterpret_cast<char*>(&len), sizeof(len));
            file_ofstream_binary.write(transport[i].type.data(), len);


            // Записываем transport[i].route
            len = transport[i].route.length();
            file_ofstream_binary.write(reinterpret_cast<char*>(&len), sizeof(len));
            file_ofstream_binary.write(transport[i].route.data(), len);


            // Записываем transport[i].length
            file_ofstream_binary.write(reinterpret_cast<char*>(&transport[i].length), sizeof(transport[i].length));

            // Записываем transport[i].time
            file_ofstream_binary.write(reinterpret_cast<char*>(&transport[i].time), sizeof(transport[i].time));


            // Записываем transport[i].date.day
            len = transport[i].date.day.length();
            file_ofstream_binary.write(reinterpret_cast<char*>(&len), sizeof(len));
            file_ofstream_binary.write(transport[i].date.day.data(), len);


            // Записываем transport[i].date.month
            len = transport[i].date.month.length();
            file_ofstream_binary.write(reinterpret_cast<char*>(&len), sizeof(len));
            file_ofstream_binary.write(transport[i].date.month.data(), len);


            // Записываем transport[i].date.year
            len = transport[i].date.year.length();
            file_ofstream_binary.write(reinterpret_cast<char*>(&len), sizeof(len));
            file_ofstream_binary.write(transport[i].date.year.data(), len);

        }
    }
    file_ofstream_binary.close();

    // считать 3 записи из файла в бинарном формате и отобразить.
    std::ifstream file_ifstream_binary;
    Record readRecords_binary[3];
    file_ifstream_binary.open("Korolev.bin", std::ios::binary);
    if (!file_ifstream_binary.is_open()) {
        std::cout << "Ошибка открытия файла." << std::endl;
    }
    else {
        for (int i = 0; i < 3; i++) {
            size_t len = 0;
            // Считываем type и сохраняем в структуру readRecords_binary
            file_ifstream_binary.read(reinterpret_cast<char*>(&len), sizeof(len));
            readRecords_binary[i].type.resize(len);
            file_ifstream_binary.read(&readRecords_binary[i].type[0], len);

            // Считываем route и сохраняем в структуру readRecords_binary
            file_ifstream_binary.read(reinterpret_cast<char*>(&len), sizeof(len));
            readRecords_binary[i].route.resize(len);
            file_ifstream_binary.read(&readRecords_binary[i].route[0], len);

            // Считываем length и сохраняем в структуру readRecords_binary
            file_ifstream_binary.read(reinterpret_cast<char*>(&readRecords_binary[i].length), sizeof(readRecords_binary[i].length));

            // Считываем time и сохраняем в структуру readRecords_binary
            file_ifstream_binary.read(reinterpret_cast<char*>(&readRecords_binary[i].time), sizeof(readRecords_binary[i].time));


            // Считываем date.day и сохраняем в структуру readRecords_binary
            file_ifstream_binary.read(reinterpret_cast<char*>(&len), sizeof(len));
            readRecords_binary[i].date.day.resize(len);
            file_ifstream_binary.read(&readRecords_binary[i].date.day[0], len);

            // Считываем date.month и сохраняем в структуру readRecords_binary
            file_ifstream_binary.read(reinterpret_cast<char*>(&len), sizeof(len));
            readRecords_binary[i].date.month.resize(len);
            file_ifstream_binary.read(&readRecords_binary[i].date.month[0], len);

            // Считываем date.year и сохраняем в структуру readRecords_binary
            file_ifstream_binary.read(reinterpret_cast<char*>(&len), sizeof(len));
            readRecords_binary[i].date.year.resize(len);
            file_ifstream_binary.read(&readRecords_binary[i].date.year[0], len);
        }
    }
    file_ifstream_binary.close();
    std::cout << "\n\nТаблица из бинарного файла:\n\n";
    Draw(readRecords_binary, 3);


    // добавить новую запись (четвертую) в указанный существующий файл, вводя данные с клавиатуры.
    const unsigned int number_records = 1; // Количество новых записей для добавления в файл
    Record new_data[number_records];
    std::cout << "\n";
    InputData(new_data, number_records);

    file_ofstream.open("Korolev.txt", std::fstream::app);
    if (!file_ofstream.is_open()) {
        std::cout << "Ошибка открытия файла." << std::endl;
    }
    else {
        for (int i = 0; i < number_records; i++) {
            file_ofstream << new_data[i].type << " " << new_data[i].route << " " << new_data[i].length << " " << new_data[i].time << " " << new_data[i].date.day << " " << new_data[i].date.month << " " << new_data[i].date.year;
            file_ofstream << "\n";
        }
    }
    file_ofstream.close();


    Record fileRecords[4];
    file_ifstream.open("Korolev.txt");
    if (!file_ifstream.is_open()) {
        std::cout << "Ошибка открытия файла." << std::endl;
    }
    else {
        for (int i = 0; i < 4; i++) {
            file_ifstream >> fileRecords[i].type >> fileRecords[i].route >> fileRecords[i].length >> fileRecords[i].time >> fileRecords[i].date.day >> fileRecords[i].date.month >> fileRecords[i].date.year;
        }
    }
    file_ifstream.close();
    std::cout << "\n\nНовая таблица с четвертой записью:\n\n";
    Draw(fileRecords, 4);

    // поменять местами строковые значения в 3 и 4 записях файла. Данные считываются из файла.
    std::swap(fileRecords[2].type, fileRecords[3].type);
    std::swap(fileRecords[2].route, fileRecords[3].route);
    std::swap(fileRecords[2].date.day, fileRecords[3].date.day);
    std::swap(fileRecords[2].date.month, fileRecords[3].date.month);
    std::swap(fileRecords[2].date.year, fileRecords[3].date.year);

    std::cout << "\n\nНовая измененная таблица с четвертой записью:\n\n";
    Draw(fileRecords, 4);
}

void Prak_5() {
    clDate date_1{};
    date_1.printDate();

    clDate date_2{ "01", "12", "2003" };
    date_2.printDate();

    clDate date_3{ Date{"08", "03", "2000"} };
    date_3.printDate();

    clDate date_4{ new Date{"01", "01", "1970"} };
    date_4.printDate();


    сlRecord record_1{};
    сlRecord record_2{ "Тр", "12", 27.550, 75, {"05", "08", "2020"} };
    сlRecord record_3{ Record{"А", "17ф", 432, 33, {"12", "05", "1970"}} };
    сlRecord record_4{ new Record{"Т-с", "12г", 58, 93, {"01", "01", "1999"}} };
    
    сlRecord array[3];
    array[0] = { "Тр", "12", 27.550, 75, { "03", "04", "2022" } };
    array[1] = { "Т-с", "17", 13.600, 57, { "03", "04", "2020" } };
    array[2] = { "А", "12а", 57.300, 117, { "04", "03", "2022" } };
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
    Prak_4(Table);
    Prak_5();

    delete[] Table;
    return 0;
}
