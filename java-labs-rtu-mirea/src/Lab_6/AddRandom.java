package JavaLabs.Lab_6;

public class AddRandom {

    static String[] firstNames = {"Александр", "Владимир", "Светлана", "Петр", "Николай", "Екатерина",
            "Артем", "Алексей", "Геннадий", "Андрей", "Анастасия", "Никита", "Варвара", "Илья", "Лев",
            "Доброслав", "Вячеслав", "Евгений", "Зинаида", "Алина", "Алиса", "Людмила"};
    static String[] patronymics = {"Владимирович", "Александрович", "Петрович", "Ильич",
            "Алексеевич", "Геннадиевич", "Андреевич", "Львович", "Никитич", "Антонович",
            "Артемович", "Елисеевич"};
    static String[] lastNames = {"Головко", "Черных", "Витали", "Будяну", "Сокол", "Челибидаху", "Мольтке",
            "Бойко", "Дурново", "Гама", "Леонкавалло", "Пуччини", "Вальх", "Кодай", "Солодовник", "Сталин"};
    static String[] birthdayDates = {"22 февраля 2002", "26 июня 1973", "28 ноября 1968", "14 ноября 2001",
            "20 октября 2001", "14 марта 1999", "17 апреля 1995", "12 июня 1992", "1 сентября 2004", "5 октября 2000",
            "21 ноября 1988", "30 мая 2000", "8 марта 1995", "7 августа 1997", "16 апреля 1992"};
    static String[] positions = {"Junior", "Middle", "Senior"};
    static String[] nameOfCities = {"Москва", "Санкт-Петербург", "Волгоград", "Курск", "Челябинск", "Саранск",
            "Екатеринбург", "Владивосток", "Хабаровск", "Урюпинск", "Норильск", "Тамбов", "Севастополь"};


    public static Employer setRandomEmployer(int id) {
        id += 1;

        int numberForFirstName = (int) (Math.random() * firstNames.length);
        String firstName = firstNames[numberForFirstName];

        int numberForPatronymics = (int) (Math.random() * patronymics.length);
        String patronymic = patronymics[numberForPatronymics];

        int numberForLastName = (int) (Math.random() * lastNames.length);
        String lastName = lastNames[numberForLastName];

        String FIO = lastName + " " + firstName + " " + patronymic;

        int numberForBirthdayDates = (int) (Math.random() * birthdayDates.length);
        String birthdayDate = birthdayDates[numberForBirthdayDates];

        int numberForPosition = (int) (Math.random() * positions.length);
        String position = positions[numberForPosition];

        int numberForNameOfCities = (int) (Math.random() * nameOfCities.length);
        String nameOfCity = nameOfCities[numberForNameOfCities];

        return new Employer(id, FIO, birthdayDate, position, nameOfCity);
    }
}
