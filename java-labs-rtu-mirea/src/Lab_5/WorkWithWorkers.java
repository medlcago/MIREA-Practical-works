package JavaLabs.Lab_5;

import java.util.ArrayList;
import java.util.Scanner;

public class WorkWithWorkers {

    static ArrayList<Worker> masWorkers;
    static Scanner sc = new Scanner(System.in);

    public WorkWithWorkers(ArrayList<Worker> masWorkers) {
        WorkWithWorkers.masWorkers = masWorkers;
    }

    public static void getWorker() {
        System.out.println(" ");
        System.out.println("-------------------------");
        System.out.println(" ");
        System.out.print("Введите ID Работника, информацию о котором хотите посмотреть: ");
        int id = sc.nextInt();
        try {
            System.out.println(masWorkers.get(id));
        } catch (IndexOutOfBoundsException exception) {
            System.out.println("ОШИБКА! ТАКОГО РАБОТНИКА НЕТ!");
            getWorker();
        }
    }

    public static void getWorkerWithCat() {
        System.out.println(" ");
        System.out.println("-------------------------");
        System.out.println(" ");
        System.out.print("Введите ID Работника, имя кота которого хотите узнать: ");
        int id = sc.nextInt();
        try {
            System.out.println(masWorkers.get(id).getCat());
        } catch (NullPointerException exception) {
            System.out.println("ОШИБКА! У ДАННОГО РАБОТНИКА НЕТ КОТА! ");
            getWorkerWithCat();
        }
    }

    public static void getDivideSalary() {
        System.out.println(" ");
        System.out.println("-------------------------");
        System.out.println(" ");
        System.out.print("Введите ID Работника, чью зарплату хотите раздедить на какое-то число: ");
        int id = sc.nextInt();
        System.out.print("Введите число, на которое Вы бы хотели разделить зарплату работника № " + id + ": ");
        int numberDivide = sc.nextInt();
        try {
            int newSalary = masWorkers.get(id).getSalary() / numberDivide;
            System.out.println("Новая зарплата работника № " + id + " равна: " + newSalary);
        } catch (ArithmeticException exception) {
            System.out.println("ОШИБКА! ПРОИЗОШЛА АРИФМЕТИЧЕСКАЯ ОШИБКА! ");
            getDivideSalary();
        }
    }

}
