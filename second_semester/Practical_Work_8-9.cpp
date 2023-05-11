#include <iostream>
#include <string>
#include <limits>
#include <Windows.h>

using namespace std;

class clDate {
private:
    int day;
    int month;
    int year;
public:
    clDate(int day=1, int month=1, int year=1970) : day(day), month(month), year(year) {}

    int get_day() { return this->day; }

    void set_day(int day) { this->day = day; }

    int get_month() { return this->month; }

    void set_month(int month) { this->month = month; }

    int get_year() { return this->year; }

    void set_year(int year) { this->year = year; }


    bool operator<(const clDate& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }

    friend istream& operator>>(istream& in, clDate& date);
    friend ostream& operator<<(ostream& out, const clDate& date);
};

istream& operator>>(istream& in, clDate& date) {
    cout << "(день месяц год): ";
    in >> date.day >> date.month >> date.year;
    return in;
}

ostream& operator<<(ostream& out, const clDate& date) {
    if (date.day < 10) out << '0';
    out << date.day << '.';
    if (date.month < 10) out << '0';
    out << date.month << '.' << date.year;
    return out;
}

class clStudent {
protected:
    string surname;
    string name;
    string patronymic;
    clDate birthdate;
    string gender;
    clDate enrollment_date;
    int scholarship;
public:
    clStudent() {}

    clStudent(string surname, string name, string patronymic, clDate birthdate, string gender, clDate enrollment_date, int scholarship) {
        this->surname = surname;
        this->name = name;
        this->patronymic = patronymic;
        this->birthdate = birthdate;
        this->gender = gender;
        this->enrollment_date = enrollment_date;
        this->scholarship = scholarship;
    }

    string get_surname() const { return surname; }

    void set_surname(const string& surname) { this->surname = surname; }

    string get_name() const { return name; }

    void set_name(const string& name) { this->name = name; }

    string get_patronymic() const { return patronymic; }

    void set_patronymic(const string& patronymic) { this->patronymic = patronymic; }

    clDate get_birthdate() const { return birthdate; }

    void set_birthdate(const clDate& birthdate) { this->birthdate = birthdate; }

    string get_gender() const { return gender; }

    void set_gender(const string& gender) { this->gender = gender; }

    clDate get_enrollment_date() const { return enrollment_date; }

    void set_enrollment_date(const clDate& enrollment_date) { this->enrollment_date = enrollment_date; }

    int get_scholarship() const { return scholarship; }

    void set_scholarship(const int& scholarship) { this->scholarship = scholarship; }

    clStudent& operator=(const clStudent& other) {
        this->surname = other.surname;
        this->name = other.name;
        this->patronymic = other.patronymic;
        this->birthdate = other.birthdate;
        this->gender = other.gender;
        this->enrollment_date = other.enrollment_date;
        this->scholarship = other.scholarship;
        return *this;
    }

    bool operator<(const clStudent& other) const {
        if (scholarship != other.scholarship) return scholarship < other.scholarship;
        return gender < other.gender;
    }
    
    friend class clGroup;
    friend istream& operator>>(istream& in, clStudent& student);
    friend ostream& operator<<(ostream& out, const clStudent& student);
};

istream& operator>>(istream& in, clStudent& student) {
    cout << "Введите фамилию студента: ";
    in >> student.surname;
    in.ignore(32767, '\n');

    cout << "Введите имя студента: ";
    in >> student.name;
    in.ignore(32767, '\n');

    cout << "Введите отчество студента: ";
    in >> student.patronymic;
    in.ignore(32767, '\n');

    cout << "Введите дату рождения студента (день месяц год): ";
    in >> student.birthdate;
    in.ignore(32767, '\n');

    cout << "Введите пол студента: ";
    in >> student.gender;
    in.ignore(32767, '\n');

    cout << "Введите дату зачисления студента (день месяц год): ";
    in >> student.enrollment_date;
    in.ignore(32767, '\n');

    cout << "Введите стипендию студента: ";
    in >> student.scholarship;
    in.ignore(32767, '\n');

    cout << endl;
    return in;
}

ostream& operator<<(ostream& out, const clStudent& student) {
    system("cls");
    out << "Фамилия: " << student.get_surname() << '\n';
    out << "Имя: " << student.get_name() << '\n';
    out << "Отчество: " << student.get_patronymic() << '\n';
    out << "Дата рождения: " << student.get_birthdate() << '\n';
    out << "Пол: " << student.get_gender() << '\n';
    out << "Дата зачисления: " << student.get_enrollment_date() << '\n';
    out << "Размер стипендии: " << student.get_scholarship() << '\n';
    out << endl;
    return out;
}

class clGroup {
protected:
    string name;
    string institute;
    string department;
    string curator;
    int size;
    clStudent* students;

public:
    clGroup() {}

    clGroup(string name, string institute, string department, string curator, int size) : name(name), institute(institute), department(department), curator(curator), size(size) {
        this->students = new clStudent[size];
    }

    ~clGroup() {
        if (students != nullptr)
            delete[] students;
    }

    void input_group_data() {
        cout << "Введите название группы: ";
        getline(cin, name);
        cout << "Введите институт: ";
        getline(cin, institute);
        cout << "Введите кафедру: ";
        getline(cin, department);
        cout << "Введите куратора: ";
        getline(cin, curator);
        cout << "Введите численность группы: ";
        cin >> size;

        cin.ignore(32767, '\n');

        cout << endl;

        students = new clStudent[size];

        for (int i = 0; i < size; i++) {
            cout << "Введите фамилию студента #" << i + 1 << ": ";
            cin >> students[i].surname;
            cin.ignore(32767, '\n');

            cout << "Введите имя студента #" << i + 1 << ": ";
            cin >> students[i].name;
            cin.ignore(32767, '\n');

            cout << "Введите отчество студента #" << i + 1 << ": ";
            cin >> students[i].patronymic;
            cin.ignore(32767, '\n');

            cout << "Введите дату рождения студента #" << i + 1 << ": ";
            cin >> students[i].birthdate;
            cin.ignore(32767, '\n');

            cout << "Введите пол студента #" << i + 1 << ": ";
            cin >> students[i].gender;
            cin.ignore(32767, '\n');

            cout << "Введите дату зачисления студента #" << i + 1 << ": ";
            cin >> students[i].enrollment_date;
            cin.ignore(32767, '\n');

            cout << "Введите стипендию студента #" << i + 1 << ": ";
            cin >> students[i].scholarship;
            cin.ignore(32767, '\n');

            cout << endl;
        }
        system("cls");
    }

    void output_group_data() const {
        cout << "Название группы: " << name << endl;
        cout << "Институт: " << institute << endl;
        cout << "Кафедра: " << department << endl;
        cout << "Куратор: " << curator << endl;
        cout << "Численность группы: " << size << endl;

        cout << endl << endl;

        for (int i = 0; i < size; i++) {
            cout << "Студент #" << i + 1 << ":\n";
            cout << "Фамилия: " << students[i].get_surname() << '\n';
            cout << "Имя: " << students[i].get_name() << '\n';
            cout << "Отчество: " << students[i].get_patronymic() << '\n';
            cout << "Дата рождения: " << students[i].get_birthdate() << '\n';
            cout << "Пол: " << students[i].get_gender() << '\n';
            cout << "Дата зачисления: " << students[i].get_enrollment_date() << '\n';
            cout << "Размер стипендии: " << students[i].get_scholarship() << '\n';

            cout << endl;
        }
    }

    void sort_students() {
        for (int i = 1; i < size; i++) {
            clStudent key = students[i];
            int j = i - 1;

            while (j >= 0 && students[j] < key) {
                students[j + 1] = students[j];
                j--;
            }

            students[j + 1] = key;
        }
    }
    
    friend istream& operator>>(istream& in, clGroup& group);
    friend ostream& operator<<(ostream& out, const clGroup& group);

};

istream& operator>>(istream& in, clGroup& group) {
    group.input_group_data();
    return in;
}

ostream& operator<<(ostream& out, const clGroup& group) {
    group.output_group_data();
    return out;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    constexpr int kLineWidth = 100;
    const std::string kLineSeparator(kLineWidth, '-');

    clGroup group;
    cin >> group;
    cout << group;
    group.sort_students();
    cout << kLineSeparator << endl;
    cout << group;
    return 0;
}
