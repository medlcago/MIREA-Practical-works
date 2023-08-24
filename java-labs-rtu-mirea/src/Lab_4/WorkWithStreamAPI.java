package JavaLabs.Lab_4;

import java.util.Comparator;
import java.util.List;
import java.util.Objects;
import java.util.stream.Collectors;

public class WorkWithStreamAPI {

    //Нахождение Работника с Максимальной зарплатой:
    public static Worker findWithMaxSalary(List<Worker> workers) {
        return workers.stream().max(Comparator.comparing(Worker::getSalary)).orElse(null);
    }

    //Нахождение работника с Минимальной зарплатой:
    public static Worker findWithMinSalary(List<Worker> workers) {
        return workers.stream().min(Comparator.comparing(Worker::getSalary)).orElse(null);
    }

    //Нахождение всех работников, которым меньше 50 лет, и которые владеют кошками:
    public static List<Worker> findWorkersForAgeAndCatsLess50(List<Worker> workers) {
        return workers.stream().filter(worker -> worker.getAge() < 50 && worker.getNameOfCat() != null).toList();
    }

    //Сортировка всех работников, которым меньше 50 лет, и которые владеют кошками:
    public static List<Worker> sortWorkersForAgeAndCatsLess50(List<Worker> workers) {
        return workers.stream().sorted(Comparator.comparing(Worker::getAge)).collect(Collectors.toList());
    }

    //Нахождение всех работников, которым больше 50 лет, и которые владеют кошками:
    public static List<Worker> findWorkersForAgeAndCatsMore50(List<Worker> workers) {
        return workers.stream().filter(worker -> worker.getAge() > 50 && worker.getNameOfCat() != null).toList();
    }

    //Сортировка всех работников, которым больше 50 лет, и которые владеют кошками:
    public static List<Worker> sortWorkersForAgeAndCatsMore50(List<Worker> workers) {
        return workers.stream().sorted(Comparator.comparing(Worker::getAge)).collect(Collectors.toList());
    }

    //Нахождение всех работников, у которых Зарплата + Премия больше 100.000:
    public static List<Worker> findWorkerWithHugePay(List<Worker> workers) {
        return workers.stream().filter(worker -> worker.getPay() >= 100000).toList();
    }

    //Нахождение всех работников, которые работают в Отделе разарботки:
    public static long countDevelopments(List<Worker> workers) {
        return workers.stream().filter(worker -> Objects.equals(worker.getNameOfDepartment(), "Разработка")).count();
    }

    //Нахождение всех работников, которые работают в Финансовом отделе:
    public static long countEconomist(List<Worker> workers) {
        return workers.stream().filter(worker -> Objects.equals(worker.getNameOfDepartment(), "Финансовый отдел")).count();
    }

    //Нахождение всех работников, которые работают в Бухгалтерии:
    public static long countAccountants(List<Worker> workers) {
        return workers.stream().filter(worker -> Objects.equals(worker.getNameOfDepartment(), "Бухгалтерия")).count();
    }

    //Нахождение всех работников, которые работают в Отделе рекламы:
    public static long countAdd(List<Worker> workers) {
        return workers.stream().filter(worker -> Objects.equals(worker.getNameOfDepartment(), "Отдел Рекламы")).count();
    }
}
