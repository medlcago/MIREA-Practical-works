package JavaLabs.Lab_6;

import java.util.ArrayList;

public class Employer {

    public static final String RESET = "\033[0m";
    public static final String BLACK_BOLD = "\033[1;30m";

    int id;
    String FIO;
    String birthdayDate;
    String position;
    String nameOfCity;
    ArrayList<Integer> masOfGivenTasks = new ArrayList<>();
    int salary;

    public Employer(int id, String FIO, String birthdayDate, String position, String nameOfCity) {
        this.id = id;
        this.FIO = FIO;
        this.birthdayDate = birthdayDate;
        this.position = position;
        this.nameOfCity = nameOfCity;
    }

    public void setTask(int number){
        masOfGivenTasks.add(number);
    }

    public void setSalary(int salary){
        this.salary = salary;
    }

    public int getSalary(){
        return salary;
    }

    public String toString() {
        return BLACK_BOLD + "ID: " + RESET + id +
                BLACK_BOLD + "; ФИО: " + RESET + FIO +
                BLACK_BOLD + "; " + "Дата рождения: " + RESET + birthdayDate +
                BLACK_BOLD + "; Должность: " + RESET + position +
                BLACK_BOLD + "; Город: " + RESET + nameOfCity +
                BLACK_BOLD + "; Номера задач: " + RESET + masOfGivenTasks +
                BLACK_BOLD + "; Зарплата за прошлый месяц: " + RESET + salary +
                BLACK_BOLD + ";" + RESET;
    }

    public String toTextFile() {
        return "ID: " + id +
                "; ФИО: " + FIO +
                "; Дата рождения: " + birthdayDate +
                "; Должность: " + position +
                "; Город: " + nameOfCity +
                "; Номера задач: " + masOfGivenTasks +
                ";";
    }
}
