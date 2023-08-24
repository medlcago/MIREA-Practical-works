package JavaLabs.Lab_7.Task_2;

public class Cat {

    static final String RESET = "\033[0m";
    static final String BLACK_BOLD = "\033[1;30m";

    int id;
    String name;
    int age;
    int height;
    int weight;

    public Cat(int id, String name, int age, int height, int weight) {
        this.id = id;
        this.name = name;
        this.age = age;
        this.height = height;
        this.weight = weight;
    }

    public String toString() {
        return BLACK_BOLD + "ID: " + RESET + id +
                BLACK_BOLD + "; Имя: " + RESET + name +
                BLACK_BOLD + "; Возраст: " + RESET + age +
                BLACK_BOLD + "; Рост: " + RESET + height +
                BLACK_BOLD + "; Вес: " + RESET + weight +
                BLACK_BOLD + ";" + RESET;
    }
}
