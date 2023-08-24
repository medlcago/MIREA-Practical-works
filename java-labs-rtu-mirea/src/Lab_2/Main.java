package JavaLabs.Lab_2;

import JavaLabs.Lab_2.Logic.GameLogic;
import JavaLabs.Lab_2.Logic.MagicSlots;
import JavaLabs.Lab_2.Logic.Spell;
import JavaLabs.Lab_2.MagicElements.Air;
import JavaLabs.Lab_2.MagicElements.Cold;
import JavaLabs.Lab_2.MagicElements.Fire;

import java.util.ArrayList;
import java.util.Random;

public class Main {

    static ArrayList<Enemy> masEnemy = new ArrayList<>();
    static ArrayList<Weapon> masWeapon = new ArrayList<>();
    static ArrayList<Hero> masHero = new ArrayList<>();

    public static void main(String[] args) {

        makePlayers();
        System.out.println(" ");
        System.out.println("--------------------------------");
        System.out.println(" ");

        for(int i = 0; i < 20; i++){
            GameLogic gm = new GameLogic();
            System.out.println(gm.get_DPS());
        }

        System.out.println(" ");
        System.out.println("--------------------------------");
        System.out.println(" ");

        MagicSlots mg = new MagicSlots();

        Spell<Fire> fireGun = new Spell(new Fire());
        mg.addSpell(fireGun);
        Spell<Air> airGun = new Spell(new Air());
        mg.addSpell(airGun);
        Spell<Cold> coldGun = new Spell(new Cold());
        mg.addSpell(coldGun);

        for (int i = 0; i <= 2; i++){
//            System.out.println(mg.spellsList.get(i));
        }
    }

    public static void makePlayers() {
        Random rnd = new Random();
        for (int i = 0; i < 10; i++) {
            String name = "Hero №" + rnd.nextInt((100) + 1);
            int id = rnd.nextInt((10000) + 1);
            int level = rnd.nextInt((100) + 1);
            int damage = rnd.nextInt((100) + 1);
            int hp = rnd.nextInt((100) + 1);
            int defence = rnd.nextInt((100) + 1);
            Hero new_hero = new Hero(name, id, level, damage, hp, defence);
            masHero.add(new_hero);
        }

        for (Hero h: masHero){
            System.out.println(h.toString());
        }

        System.out.println(" ");
        System.out.println("--------------------------------");
        System.out.println(" ");

        for (int i = 0; i < 10; i++) {
            String name = "Enemy №" + rnd.nextInt((100) + 1);
            int id = rnd.nextInt((10000) + 1);
            int level = rnd.nextInt((100) + 1);
            int damage = rnd.nextInt((100) + 1);
            int hp = rnd.nextInt((100) + 1);
            int defence = rnd.nextInt((100) + 1);
            Enemy new_enemy = new Enemy(name, id, level, damage, hp, defence);
            masEnemy.add(new_enemy);
        }

        for (Enemy e: masEnemy){
            System.out.println(e.toString());
        }

        System.out.println(" ");
        System.out.println("--------------------------------");
        System.out.println(" ");

        for (int i = 0; i < 20; i++) {
            String name = "Weapon №" + rnd.nextInt((100) + 1);
            int id = rnd.nextInt((10000) + 1);
            int level = rnd.nextInt((100) + 1);
            int damage = rnd.nextInt((100) + 1);
            Weapon new_weapon = new Weapon(name, id, level, damage);
            masWeapon.add(new_weapon);
        }

        for (Weapon w: masWeapon){
            System.out.println(w.toString());
        }
    }
}
