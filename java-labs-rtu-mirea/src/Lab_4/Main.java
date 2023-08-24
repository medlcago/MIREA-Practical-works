package JavaLabs.Lab_4;

import java.util.ArrayList;

public class Main {

    static ArrayList<Worker> masWorkers = new ArrayList<>();
    static WorkWithWorkers workWithWorkers = new WorkWithWorkers(masWorkers);

    public static void main(String[] args) {
        System.out.println("-------------------------");
        System.out.println(" ");
        System.out.println("Штат сотрудников компании: ");
        createWorkers();
        showWorkers();
        WorkWithWorkers.getMaxSalary();
        WorkWithWorkers.getMinSalary();
        WorkWithWorkers.getWorkersForAgeAndCatsLess50();
        WorkWithWorkers.getWorkersForAgeAndCatsMore50();
        WorkWithWorkers.getWorkerWithHugePay();
        WorkWithWorkers.getTableOfDepartment();

    }

    public static void createWorkers() {
        String[] firstNames = {"Александр", "Владимир", "Светлана", "Петр", "Николай", "Екатерина",
                "Артем", "Алексей", "Геннадий", "Андрей", "Анастасия", "Никита", "Варвара", "Илья"};
        String[] lastNames = {"Головко", "Черных", "Витали", "Будяну", "Сокол", "Челибидаху", "Мольтке",
                "Бойко", "Дурново", "Гама", "Леонкавалло", "Пуччини", "Вальх", "Кодай"};
        String[] namesOfCats = {"Барсик", "Цунами", "Клеопатра", "Наоми", "Маркиза", "Пират", "Зорро",
                "Валли", "Каспер", "Том", "Гарфилд"};
        String[] namesOfDepartments = {"Разработка", "Финансовый отдел", "Бухгалтерия", "Отдел Рекламы"};
        String[] positions = {"Junior", "Middle", "Senior"};

        for (int i = 0; i < 20; i++) {
            int numberForId = i + 1;

            int numberForFirstName = (int) (Math.random() * firstNames.length);
            String firstName = firstNames[numberForFirstName];

            int numberForLastName = (int) (Math.random() * lastNames.length);
            String lastName = lastNames[numberForLastName];

            int age = 20 + (int) (Math.random() * 60);

            String sex;
            int isSex = (int) (Math.random() * 10);
            if (isSex % 2 == 0) {
                sex = "Мужчина";
            } else {
                sex = "Женщина";
            }

            String nameOfCat;
            int isCat = (int) (Math.random() * 10);
            if (isCat % 2 == 0) {
                nameOfCat = null;
            } else {
                int numberForNameOfCat = (int) (Math.random() * namesOfCats.length);
                nameOfCat = namesOfCats[numberForNameOfCat];
            }

            int numberForNameOfDepartment = (int) (Math.random() * namesOfDepartments.length);
            String nameOfDepartment = namesOfDepartments[numberForNameOfDepartment];

            int numberForPosition = (int) (Math.random() * positions.length);
            String position = positions[numberForPosition];

            int salary = 10000 + (int) (Math.random() * 90000);

            int prize = (int) (Math.random() * 15000);

            int yearOfWork = 1 + (int) (Math.random() * 5);

            Worker new_worker = new Worker(firstName, lastName, sex, nameOfCat, nameOfDepartment,
                    position, yearOfWork, age, salary, prize, numberForId);
            masWorkers.add(new_worker);
        }
    }

    public static void showWorkers(){
        for (Worker w: masWorkers) {
            System.out.println(w.toString());
        }
    }


}
