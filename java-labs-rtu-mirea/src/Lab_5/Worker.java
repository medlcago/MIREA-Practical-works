package JavaLabs.Lab_5;

public class Worker {

    int id;
    String firstName;
    String lastName;
    int age;
    int salary;
    int yearsOfWork;
    String cat;

    public Worker(int id, String firstName, String lastName, int age, int salary, int yearsOfWork, String cat) {
        this.id = id;
        this.firstName = firstName;
        this.lastName = lastName;
        this.age = age;
        this.salary = salary;
        this.yearsOfWork = yearsOfWork;
        this.cat = cat;
    }

    public String toString() {
        return "ID: " + id + "; ФИО: " + firstName + " " + lastName + "; Возраст: " + age + "; Зарплата: " + salary
                + "; Годы работы: " + yearsOfWork + ";" + " Кот: " + cat + ";";
    }

    public String getCat() {
        return cat;
    }

    public int getSalary() {
        return salary;
    }
}
