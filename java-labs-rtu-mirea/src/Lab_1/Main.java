package JavaLabs.Lab_1;

import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class Main {

    static Person person = new Person();
    static ArrayList<Enemy> masEnemy = new ArrayList<>();
    static ArrayList<Weapon> masWeapon = new ArrayList<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Введите уровень игрока: ");
        int level_person = sc.nextInt();
        System.out.println("Введите уровень оружия: ");
        int level_weapon = sc.nextInt();

        Person.isNormalWeapon(level_person, level_weapon);

        System.out.println(" ");
        System.out.println("------------------------------");
        System.out.println(" ");
        makeEnemy();
        showHeroes();
        System.out.println(" ");
        System.out.println("------------------------------");
        System.out.println(" ");
        makeWeapons();
        showWeapons();
    }

    public static void makeEnemy() {
        String name_enemys;
        Random rnd = new Random();

        for (int i = 0; i < 10; i++) {
            name_enemys = "Enemy №" + rnd.nextInt((100) + 1);
            int hp_enemys = rnd.nextInt((100) + 1);
            int atk_enemys = rnd.nextInt((100) + 1);
            int deff_enemys = rnd.nextInt((100) + 1);
            Enemy new_enemy = new Enemy(name_enemys, hp_enemys, atk_enemys, deff_enemys);
            masEnemy.add(new_enemy);
        }
    }

    public static void showHeroes() {
        for (Enemy e : masEnemy) {
            System.out.println(e.toString());
        }
    }

    public static void makeWeapons() {
        String name_weapon;
        Random rnd = new Random();

        for (int i = 0; i < 10; i++) {
            name_weapon = "Weapon №" + rnd.nextInt((100) + 1);
            int atack_weapon = rnd.nextInt((100) + 1);
            int coast_weapon = rnd.nextInt((100) + 1);
            int need_level_weapon = rnd.nextInt((100) + 1);
            Weapon new_weapom = new Weapon(name_weapon, atack_weapon, coast_weapon, need_level_weapon);
            masWeapon.add(new_weapom);
        }
    }

    public static void showWeapons() {
        for (Weapon w : masWeapon) {
            System.out.println(w.toString());
        }
    }
}
