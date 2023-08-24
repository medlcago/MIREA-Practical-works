package JavaLabs.Lab_5;

import java.util.InputMismatchException;
import java.util.Scanner;

public class AddWorker {

    static Scanner sc = new Scanner(System.in);

    //Ввод и проверка на правильность Имени Работника:
    public static String getFirstName(int id) {
        String firstName = "";
        System.out.print("Введите имя работника № " + id + ": ");

        try {
            firstName = sc.next();
        } catch (InputMismatchException exception) {
            System.out.println("ОШИБКА!");
            sc.next();
            getFirstName(id);
        }

        return firstName;
    }

    //Ввод и проверка на правильность Фамилии Работника:
    public static String getLastName(int id) {
        String lastName = "";
        System.out.print("Введите фамилию работника № " + id + ": ");

        try {
            lastName = sc.next();
        } catch (InputMismatchException exception) {
            System.out.println("ОШИБКА!");
            sc.next();
            getLastName(id);
        }

        return lastName;
    }

    //Ввод и проверка на правильность Возраста Работника:
    public static Integer getAge(int id) {
        int age = 0;
        System.out.print("Введите возраст работника № " + id + ": ");

        try {
            age = sc.nextInt();
        } catch (InputMismatchException exception) {
            System.out.println("ОШИБКА!");
            sc.next();
            getAge(id);
        }

        return age;
    }

    //Ввод и проверка на правильность Зарплаты Работника:
    public static Integer getSalary(int id) {
        int salary = 0;
        System.out.print("Введите зарплату работника №" + id + ": ");

        try {
            salary = sc.nextInt();
        } catch (InputMismatchException exception) {
            System.out.println("ОШИБКА!");
            sc.next();
            getSalary(id);
        }

        return salary;
    }

    //Ввод и проверка на правильность количетсва лет работы в компании Работника:
    public static Integer getYearsOfWork(int id) {
        int yearsOfWork = 0;
        System.out.print("Введите годы работы в компании работника №" + id + ": ");

        try {
            yearsOfWork = sc.nextInt();
        } catch (InputMismatchException exception) {
            System.out.println("ОШИБКА!");
            sc.next();
            getYearsOfWork(id);
        }

        return yearsOfWork;
    }

    public static String getCat(int id) {
        String cat = "";
        int isCat;
        System.out.print("Если у работника № " + id + " есть кот - введите 1, нет - введите 2: ");
        isCat = sc.nextInt();
        if (isCat == 2) {
            return null;
        } else {
            System.out.print("Введите имя кота: ");
            return sc.next();
        }
    }
}
