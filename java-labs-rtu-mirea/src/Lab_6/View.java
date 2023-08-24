package JavaLabs.Lab_6;

import java.util.Comparator;
import java.util.Scanner;

import static JavaLabs.Lab_6.Main.masEmployer;
import static JavaLabs.Lab_6.Main.masTask;

public class View {

    public static final String RESET = "\033[0m";
    public static final String RED_BOLD = "\033[1;31m";
    public static final String BLACK_BOLD = "\033[1;30m";
    public static final String GREEN_BOLD = "\033[1;32m";

    static Scanner sc = new Scanner(System.in);

    public static void menu() {
        System.out.println("--------------------------");
        System.out.println(" ");
        System.out.println(BLACK_BOLD + "Возможные действия: " + RESET);
        System.out.println(BLACK_BOLD + "0." + RESET + " Остановить программу.");
        System.out.println(BLACK_BOLD + "1." + RESET + " Добавить сотрудника рандомно.");
        System.out.println(BLACK_BOLD + "2." + RESET + " Добавить сотрудника самостоятельно.");
        System.out.println(BLACK_BOLD + "3." + RESET + " Вывести всех работников.");
        System.out.println(BLACK_BOLD + "4." + RESET + " Добавить задачу самостоятельно.");
        System.out.println(BLACK_BOLD + "5." + RESET + " Вывести все задачи.");
        System.out.println(BLACK_BOLD + "6." + RESET + " Вывести задачу с максимальным гонораром.");
        System.out.println(BLACK_BOLD + "7." + RESET + " Сохранить список сотрудников в файл.");
        System.out.println(BLACK_BOLD + "8." + RESET + " Сохранить отчет о выполненных заданиях в файл.");
        System.out.print(BLACK_BOLD + "Выберите цифру: " + RESET);
        int number = sc.nextInt();
        switch (number) {
            case 0 -> System.exit(0);
            case 1 -> {
                masEmployer.add(AddRandom.setRandomEmployer(masEmployer.size()));
                System.out.println(GREEN_BOLD + "Сотрудник добавлен!" + RESET);
                Log.AddLog("[AddRandom][setRandomEmployer]: Был добавлен сотрудник (рандомно).");
                menu();
            }
            case 2 -> {
                masEmployer.add(AddMyself.setMyselfEmployer(masEmployer.size()));
                System.out.println(GREEN_BOLD + "Сотрудник добавлен!" + RESET);
                Log.AddLog("[AddMyself][setMyselfEmployer]: Был добавлен сотрудник (самостятельно).");
                menu();
            }
            case 3 -> {
                showEmployer();
                Log.AddLog("[View][showEmployer]: Был создан и выведен на экран список всех сотрудников.");
                menu();
            }
            case 4 -> {
                masTask.add(AddMyself.setMySelfTask(masTask.size()));
                System.out.println(GREEN_BOLD + "Задача добавлена!" + RESET);
                Log.AddLog("[AddMyself][setMyselfTask]: Была добавлена задача (самостоятельно).");
                menu();
            }
            case 5 -> {
                showTask();
                Log.AddLog("[View][showTask]: Был создан список всех задач.");
                menu();
            }
            case 6 -> {
                showTaskWithMaxFee();
                Log.AddLog("[View][showTaskWithMaxFee]: Была найдена и выведена задача с максимальным гонораром.");
                menu();
            }
            case 7 -> {
                System.out.println(GREEN_BOLD + "Список сотрудников создан!" + RESET);
                SaveEmployer.createFileWithEmployers();
                Log.AddLog("[SaveEmployer][createFileWithEmployers]: Был создан и записан в файл список сотрудников.");
                menu();
            }
            case 8 -> {
                System.out.println(GREEN_BOLD + "Список задач создан!" + RESET);
                SaveTasks.createFileWithTasks();
                Log.AddLog("[SaveTasks][createFileWithTasks]: Был создан и записан в файл список задач.");
                menu();
            }
            default -> {
                System.out.println(RED_BOLD + "Ошибка!" + RESET);
                Log.AddLog("[View][Menu]: Ошибка. Введено неизвестное число.");
                menu();
            }
        }
    }

    public static void showEmployer() {
        System.out.println(" ");
        System.out.println(GREEN_BOLD + "Все сотрудники: " + RESET);
        for (Employer employer : masEmployer) {
            System.out.println(employer.toString());
        }
    }

    public static void showTask() {
        System.out.println(" ");
        System.out.println(GREEN_BOLD + "Все задачи: " + RESET);
        for (Task task : masTask) {
            System.out.println(task.toString());
        }
    }

    public static void showTaskWithMaxFee() {
        System.out.println(" ");
        System.out.println(GREEN_BOLD + "Задача с максимальным гонораром: " + RESET);
        Object taskWithMaxFee = masTask.stream().max(Comparator.comparing(Task::getFee)).orElse(null);
        System.out.println(taskWithMaxFee);
    }
}
