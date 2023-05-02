#include <iostream>
#include <string>
#include <limits>
#include <Windows.h>

using namespace std;

class clDate {
    int day;
    int month;
    int year;
public:
    clDate() {}
    clDate(int day, int month, int year) : day(day), month(month), year(year) {}

    friend istream& operator>>(istream& in, clDate& date);
    friend ostream& operator<<(ostream& out, const clDate& date);

    bool operator<(const clDate& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }
};

istream& operator>>(istream& in, clDate& date) {
    in >> date.day >> date.month >> date.year;
    return in;
}

ostream& operator<<(ostream& out, const clDate& date) {
    out << date.day << '.' << date.month << '.' << date.year;
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
    clStudent(){}

    clStudent(string surname, string name, string patronymic, clDate birthdate, string gender, clDate enrollment_date, int scholarship) {
        this->surname = surname;
        this->name = name;
        this->patronymic = patronymic;
        this->birthdate = birthdate;
        this->gender = gender;
        this->enrollment_date = enrollment_date;
        this->scholarship = scholarship;
    }

    string get_surname() const {
        return surname;
    }

    void set_surname(const string& surname) {
        this->surname = surname;
    }

    string get_name() const {
        return name;
    }

    void set_name(const string& name) {
        this->name = name;
    }

    string get_patronymic() const {
        return patronymic;
    }

    void set_patronymic(const string& patronymic) {
        this->patronymic = patronymic;
    }

    clDate get_birthdate() const {
        return birthdate;
    }

    void set_birthdate(const clDate& birthdate) {
        this->birthdate = birthdate;
    }

    string get_gender() const {
        return gender;
    }

    void set_gender(const string& gender) {
        this->gender = gender;
    }

    clDate get_enrollment_date() const {
        return enrollment_date;
    }

    void set_enrollment_date(const clDate& enrollment_date) {
        this->enrollment_date = enrollment_date;
    }

    int get_scholarship() const {
        return scholarship;
    }

    void set_scholarship(const int& scholarship) {
        this->scholarship = scholarship;
    }

    clStudent& operator=(const clStudent& other) {
        surname = other.surname;
        name = other.name;
        patronymic = other.patronymic;
        birthdate = other.birthdate;
        gender = other.gender;
        enrollment_date = other.enrollment_date;
        scholarship = other.scholarship;
        return *this;
    }

    bool operator<(const clStudent& other) const {
        if (scholarship != other.scholarship) return scholarship < other.scholarship;
        return gender < other.gender;
    }

    friend istream& operator>>(istream& in, clStudent& student);
    friend ostream& operator<<(ostream& out, const clStudent& student);
};

istream& operator>>(istream& in, clStudent& student) {
    in >> student.surname >> student.name >> student.patronymic >> student.birthdate >> student.gender >> student.enrollment_date >> student.scholarship;
    return in;
}

ostream& operator<<(ostream& out, const clStudent& student) {
    out << student.surname << ' ' << student.name << ' ' << student.patronymic << ' ' << student.birthdate << ' ' << student.gender << ' ' << student.enrollment_date << ' ' << student.scholarship;
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
    clGroup(string name, string institute, string department, string curator, int size) : name(name), institute(institute), department(department), curator(curator), size(size) {
        students = new clStudent[size];
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
            string student_surname;
            cin >> student_surname;
            students[i].set_surname(student_surname);
            cin.ignore(32767, '\n');

            cout << "Введите имя студента #" << i + 1 << ": ";
            string student_name;
            cin >> student_name;
            students[i].set_name(student_name);
            cin.ignore(32767, '\n');

            cout << "Введите отчество студента #" << i + 1 << ": ";
            string student_patronymic;
            cin >> student_patronymic;
            students[i].set_patronymic(student_patronymic);
            cin.ignore(32767, '\n');

            cout << "Введите дату рождения студента #" << i + 1 << ": ";
            clDate student_birthdate;
            cin >> student_birthdate;
            students[i].set_birthdate(student_birthdate);
            cin.ignore(32767, '\n');

            cout << "Введите пол студента #" << i + 1 << ": ";
            string student_gender;
            cin >> student_gender;
            students[i].set_gender(student_gender);
            cin.ignore(32767, '\n');

            cout << "Введите дату зачисления студента #" << i + 1 << ": ";
            clDate student_enrollment_date;
            cin >> student_enrollment_date;
            students[i].set_enrollment_date(student_enrollment_date);
            cin.ignore(32767, '\n');

            cout << "Введите стипендию студента #" << i + 1 << ": ";
            int student_scholarship;
            cin >> student_scholarship;
            students[i].set_scholarship(student_scholarship);
            cin.ignore(32767, '\n');

            cout << endl;
        }


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
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    clGroup group("", "", "", "", 0);

    group.input_group_data();

    cout << endl;

    group.output_group_data();

    group.sort_students();

    cout << endl;

    group.output_group_data();

    return 0;
}
