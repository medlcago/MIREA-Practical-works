package JavaLabs.Lab_6;

import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.concurrent.TimeUnit;
import java.util.stream.Collectors;

import static JavaLabs.Lab_6.Main.masEmployer;
import static JavaLabs.Lab_6.Main.masTask;


public class Logic implements Runnable {

    public static final String RESET = "\033[0m";
    public static final String BLACK_BOLD = "\033[1;30m";
    public static final String GREEN_BOLD = "\033[1;32m";

    public boolean isFirstStart = true;

    @Override
    public void run() {
        while (!Thread.currentThread().isInterrupted()) {
            mouth();
            if (!isFirstStart){
                showBestEmployer();
            }
            isFirstStart = false;
            try {
                TimeUnit.SECONDS.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public static void mouth() {
        for (Employer employer : masEmployer) {
            int salary = employer.getSalary();
            for (int i = 0; i < employer.masOfGivenTasks.size(); i++) {
                int buff = employer.masOfGivenTasks.get(i);
                int hoursToCompleteTask = masTask.get(buff - 1).getHoursToComplete();
                int fee = masTask.get(buff - 1).getFee();
                salary = salary + (fee * hoursToCompleteTask);
                employer.setSalary(salary);
            }
            employer.masOfGivenTasks.clear();
        }
        for (Task task : masTask) {
            task.setStatus("Закрыта");
        }

    }

    public static void showBestEmployer() {
        System.out.println(" ");
        List<Employer> bestEmployers
                = masEmployer
                .stream()
                .sorted(Comparator.comparing(Employer::getSalary)).collect(Collectors.toList());

        System.out.println(GREEN_BOLD + "ТОП-3 сотрудников по гонорару: " + RESET);
        Collections.reverse(bestEmployers);
        for (int i = 0; i < 3; i++) {
            System.out.println(bestEmployers.get(i).toString());
        }
        System.out.print(BLACK_BOLD + "Выберите цифру: " + RESET);
    }
}
