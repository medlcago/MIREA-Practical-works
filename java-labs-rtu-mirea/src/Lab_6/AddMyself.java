package JavaLabs.Lab_6;

import java.util.Scanner;
import static JavaLabs.Lab_6.Main.*;

public class AddMyself {

    public static final String RESET = "\033[0m";
    public static final String BLACK_BOLD = "\033[1;30m";

    static Scanner sc = new Scanner(System.in);

    public static Employer setMyselfEmployer(int id) {
        id += 1;
        System.out.print(BLACK_BOLD + "Введите ФИО работника: " + RESET);
        String FIO = sc.nextLine();
        System.out.print(BLACK_BOLD + "Введите дату рождения работника: " + RESET);
        String birthdayDate = sc.nextLine();
        System.out.print(BLACK_BOLD + "Введите должность работника: " + RESET);
        String position = sc.nextLine();
        System.out.print(BLACK_BOLD + "Введите город работника: " + RESET);
        String nameOfCity = sc.nextLine();

        return new Employer(id, FIO, birthdayDate, position, nameOfCity);
    }

    public static Task setMySelfTask(int id){
        id += 1;
        System.out.print(BLACK_BOLD + "Введите название задачи: " + RESET);
        String name = sc.nextLine();
        System.out.print(BLACK_BOLD + "Введите кол-во часов на выполнение: " + RESET);
        String buff_hoursToComplete = sc.nextLine();
        int hoursToComplete = Integer.parseInt(buff_hoursToComplete);
        System.out.print(BLACK_BOLD + "Введите описание задачи: " + RESET);
        String info = sc.nextLine();
        System.out.print(BLACK_BOLD + "Введите гонорар за выполнение данной задачи: " + RESET);
        String buff_fee = sc.nextLine();
        int fee = Integer.parseInt(buff_fee);
        System.out.print(BLACK_BOLD + "Введите номер работника, который должен выполнить данную задачу: " + RESET);
        String buff_numberEmployer = sc.nextLine();
        int numberEmployer = Integer.parseInt(buff_numberEmployer);
        String status = "Открыта";

        masEmployer.get(numberEmployer - 1).setTask(id);
        return new Task(id, name, hoursToComplete, info, fee, numberEmployer, status);
    }
}
