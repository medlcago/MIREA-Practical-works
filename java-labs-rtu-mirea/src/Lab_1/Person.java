package JavaLabs.Lab_1;

public class Person {
    static String name;
    static int hp, exp, level, atk, deff;

    public static void isNormalWeapon(int level_person, int level_weapon) {

        if (level_person >= level_weapon) {
            System.out.println("Персонаж может взять оружие!");
        } else {
            System.out.println("Персонаж не может поднять оружие!");
        }
    }

    public static String rtName() {
        return name;
    }

}
