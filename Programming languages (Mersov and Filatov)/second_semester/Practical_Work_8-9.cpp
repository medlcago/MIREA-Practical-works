#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <Windows.h>

using namespace std;

const unsigned kLineWidth = 100;
const string kLineSeparator(kLineWidth, '-');

class clDate {
private:
    int day;
    int month;
    int year;
public:
    clDate(int day = 1, int month = 1, int year = 1970) : day(day), month(month), year(year) {}

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
    in.ignore(32768, '\n');

    cout << "Введите имя студента: ";
    in >> student.name;
    in.ignore(32768, '\n');

    cout << "Введите отчество студента: ";
    in >> student.patronymic;
    in.ignore(32768, '\n');

    cout << "Введите дату рождения студента: ";
    in >> student.birthdate;
    in.ignore(32768, '\n');

    cout << "Введите пол студента: ";
    in >> student.gender;
    in.ignore(32768, '\n');

    cout << "Введите дату зачисления студента: ";
    in >> student.enrollment_date;
    in.ignore(32768, '\n');

    cout << "Введите стипендию студента: ";
    in >> student.scholarship;
    in.ignore(32768, '\n');

    cout << endl;
    return in;
}

ostream& operator<<(ostream& out, const clStudent& student) {
    out << "Фамилия: " << student.surname << '\n';
    out << "Имя: " << student.name << '\n';
    out << "Отчество: " << student.patronymic << '\n';
    out << "Дата рождения: " << student.birthdate << '\n';
    out << "Пол: " << student.gender << '\n';
    out << "Дата зачисления: " << student.enrollment_date << '\n';
    out << "Размер стипендии: " << student.scholarship << '\n';
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
        delete[] students;
    }

    void readFromStream(istream& in) {
        cout << "Введите название группы: ";
        getline(in, name);
        cout << "Введите институт: ";
        getline(in, institute);
        cout << "Введите кафедру: ";
        getline(in, department);
        cout << "Введите куратора: ";
        getline(in, curator);
        cout << "Введите численность группы: ";
        in >> size;

        in.ignore(32767, '\n');

        cout << endl;

        if (students != nullptr) {
            delete[] students;
        }
        students = new clStudent[size];

        for (int i = 0; i < size; i++) {
            cout << "Студент #" << i + 1 << ": " << endl;
            in >> students[i];
            cout << endl;
        }
    }

    void printGroupInformation(ostream& out) const {
        out << left << setw(20) << "Название группы"
            << setw(20) << "Институт"
            << setw(20) << "Кафедра"
            << setw(20) << "Куратор"
            << setw(20) << "Численность группы" << '\n';
        out << left << setw(20) << name
            << setw(20) << institute
            << setw(20) << department
            << setw(20) << curator
            << setw(20) << size << '\n';
        out << kLineSeparator;
        out << endl;
    }

    void writeToStream(ostream& out) const {
        for (int i = 0; i < size; i++) {
            out << "Студент #" << i + 1 << ":\n";
            out << students[i];
        }
        cout << kLineSeparator;
        out << endl;
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

    clStudent& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return students[index];
    }

    friend istream& operator>>(istream& in, clGroup& group);
    friend ostream& operator<<(ostream& out, const clGroup& group);

};

istream& operator>>(istream& in, clGroup& group) {
    group.readFromStream(in);
    return in;
}

ostream& operator<<(ostream& out, const clGroup& group) {
    group.writeToStream(out);
    return out;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    clGroup group;
    cin >> group;
    system("cls");
    group.printGroupInformation(cout);
    cout << group;
    group.sort_students();
    cout << group;
    return 0;
}
