package JavaLabs.Lab_4;

import java.util.ArrayList;
import java.util.List;

public class WorkWithWorkers {

    private static List<Worker> masWorkers;

    public WorkWithWorkers(ArrayList<Worker> masWorkers) {
        WorkWithWorkers.masWorkers = masWorkers;
    }

    public static void getMaxSalary() {
        Object workerWithMaxSalary = WorkWithStreamAPI.findWithMaxSalary(masWorkers);
        System.out.println(" ");
        System.out.println("-------------------------");
        System.out.println(" ");
        System.out.println("Работник с максимальной зарплатой: ");
        System.out.println(workerWithMaxSalary);
    }

    public static void getMinSalary() {
        Object workerWithMinSalary = WorkWithStreamAPI.findWithMinSalary(masWorkers);
        System.out.println(" ");
        System.out.println("-------------------------");
        System.out.println(" ");
        System.out.println("Работник с минимальной зарплатой: ");
        System.out.println(workerWithMinSalary);
    }

    public static void getWorkersForAgeAndCatsLess50() {
        List<Worker> getWorkersForAgeAndCats = WorkWithStreamAPI.findWorkersForAgeAndCatsLess50(masWorkers);
        List<Worker> workersForAgeAndCats = WorkWithStreamAPI.sortWorkersForAgeAndCatsLess50(getWorkersForAgeAndCats);
        System.out.println(" ");
        System.out.println("-------------------------");
        System.out.println(" ");
        System.out.println("Осторированные работники по возрасту, которым меньше 50 лет, и которых есть кошка: ");
        if (workersForAgeAndCats.isEmpty()) {
            System.out.println("Таких работников нет!");
        } else {
            for (Worker worker : workersForAgeAndCats) {
                System.out.println(worker);
            }
        }
    }

    public static void getWorkersForAgeAndCatsMore50(){
        List<Worker> getWorkersForAgeAndCats = WorkWithStreamAPI.findWorkersForAgeAndCatsMore50(masWorkers);
        List<Worker> workersForAgeAndCats = WorkWithStreamAPI.sortWorkersForAgeAndCatsMore50(getWorkersForAgeAndCats);
        System.out.println(" ");
        System.out.println("-------------------------");
        System.out.println(" ");
        System.out.println("Осторированные работники по возрасту, которым больше 50 лет, и которых есть кошка: ");
        if (workersForAgeAndCats.isEmpty()) {
            System.out.println("Таких работников нет!");
        } else {
            for (Worker worker : workersForAgeAndCats) {
                System.out.println(worker);
            }
        }
    }

    public static void getWorkerWithHugePay() {
        List<Worker> workerWithHugePay = WorkWithStreamAPI.findWorkerWithHugePay(masWorkers);
        System.out.println(" ");
        System.out.println("-------------------------");
        System.out.println(" ");
        System.out.println("Работники, у которых Зарплата + Премия >= 100000: ");
        if (workerWithHugePay.isEmpty()) {
            System.out.println("Компания нищебродов!");
        } else {
            for (Worker worker : workerWithHugePay) {
                System.out.println(worker);
            }
        }
    }

    public static void getTableOfDepartment() {
        Object workersInDevelopmentDepartment = WorkWithStreamAPI.countDevelopments(masWorkers);
        Object workersInFinancialDepartment = WorkWithStreamAPI.countEconomist(masWorkers);
        Object workersInAccountantsDepartment = WorkWithStreamAPI.countAccountants(masWorkers);
        Object workersInAddDepartment = WorkWithStreamAPI.countAdd(masWorkers);
        System.out.println(" ");
        System.out.println("-------------------------");
        System.out.println(" ");
        System.out.println("Таблица количетсва работников в отделах: ");
        System.out.println("Отдел Разработки: " + workersInDevelopmentDepartment);
        System.out.println("Финансовый отдел: " + workersInFinancialDepartment);
        System.out.println("Бухгатерия: " + workersInAccountantsDepartment);
        System.out.println("Отдел Рекламы: " + workersInAddDepartment);
    }
}
