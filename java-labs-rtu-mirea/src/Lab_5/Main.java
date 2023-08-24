package JavaLabs.Lab_5;

import java.util.ArrayList;

public class Main {

    static ArrayList<Worker> masWorkers = new ArrayList<>(5);
    static WorkWithWorkers workWithWorkers = new WorkWithWorkers(masWorkers);

    public static void main(String[] args) {
        System.out.println("-------------------------");
        System.out.println(" ");
        System.out.println("Введите штат работников компании: ");
        createWorkers();
        System.out.println("-------------------------");
        System.out.println(" ");
        System.out.println("Штат работников компании: ");
        showWorkers();

        WorkWithWorkers.getWorker();
        WorkWithWorkers.getWorkerWithCat();
        WorkWithWorkers.getDivideSalary();

    }

    public static void createWorkers() {
        for (int i = 0; i < 5; i++) {
            String firstName = AddWorker.getFirstName(i);
            String lastName = AddWorker.getLastName(i);
            int age = AddWorker.getAge(i);
            int salary = AddWorker.getSalary(i);
            int yearsOfWork = AddWorker.getYearsOfWork(i);
            String cat = AddWorker.getCat(i);

            Worker new_worker = new Worker(i, firstName, lastName, age, salary, yearsOfWork, cat);
            masWorkers.add(new_worker);
        }
    }

    public static void showWorkers() {
        for (Worker w : masWorkers) {
            System.out.println(w.toString());
        }
    }
}
