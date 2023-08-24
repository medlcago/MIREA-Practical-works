package JavaLabs.Lab_4;

public class Worker {
    int id;
    String firstName;
    String lastName;
    int age;
    String sex;
    String nameOfCat;
    String nameOfDepartment;
    String position;
    int salary;
    int prize;
    int yearsOfWork;

    public Worker(String firstName, String lastName, String sex, String nameOfCat, String nameOfDepartment,
                  String position, int yearsOfWork, int age, int salary, int prize, int id) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.age = age;
        this.sex = sex;
        this.nameOfCat = nameOfCat;
        this.nameOfDepartment = nameOfDepartment;
        this.position = position;
        this.salary = salary;
        this.prize = prize;
        this.yearsOfWork = yearsOfWork;
        this.id = id;
    }

    public String toString() {
        return "ID: " + id + "; ФИО: " + firstName + " " + lastName + "; Возраст: " + age + "; Пол: " + sex
                + "; Имя кота: " + nameOfCat + "; Название отдела: " + nameOfDepartment + "; Должность: "
                + position + "; Зарплата: " + salary + "; Премия: " + prize + "; Годы работы: " + yearsOfWork + ";";
    }

    public int getSalary() {
        return salary;
    }

    public int getAge(){
        return age;
    }

    public String getNameOfCat(){
        return nameOfCat;
    }

    public int getPay(){
        return salary + prize;
    }

    public String getNameOfDepartment(){
        return nameOfDepartment;
    }

}
