package JavaLabs.Lab_3;

import java.util.ArrayList;
import java.util.concurrent.TimeUnit;

import static JavaLabs.Lab_3.Main.*;

public class GameLogic {

    public static final String RESET = "\033[0m";
    public static final String BLACK_BOLD = "\033[1;30m";
    public static final String GREEN_BOLD = "\033[1;32m";
    public static final String RED_BOLD = "\033[1;31m";

    public static void startBattle(char creature) {
        System.out.println(RED_BOLD + "Идет Битва!" + RESET);
        int idOfCreatures;
        switch (creature) {
            case 'А' -> idOfCreatures = 0;
            case 'Б' -> idOfCreatures = 1;
            case 'В' -> idOfCreatures = 2;
            case 'Г' -> idOfCreatures = 3;
            case 'Д' -> idOfCreatures = 4;
            case 'Е' -> idOfCreatures = 5;
            case 'Ж' -> idOfCreatures = 6;
            case 'З' -> idOfCreatures = 7;
            case 'И' -> idOfCreatures = 8;
            case 'К' -> idOfCreatures = 9;
            default -> idOfCreatures = -1;
        }
        int heroDPS = getHeroDPS();
        int creatureDPS = getCreatureDPS(idOfCreatures);
        int heroHP = getHeroHP();
        try {
            TimeUnit.SECONDS.sleep(5);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        battle(heroDPS, creatureDPS, heroHP, idOfCreatures);
    }

    public static void battle(int heroDPS, int creatureDPS, int heroHP, int idOfCreatures) {
        if (heroDPS > creatureDPS) {
            System.out.println(GREEN_BOLD + "Победа!" + RESET);
            System.out.println(GREEN_BOLD + "Игрок" + RESET + " победил существо " +
                    BLACK_BOLD + "\"" + creatures.get(idOfCreatures).getName() + "\"" + RESET + "!");
            int newHeroHP = heroHP - creatureDPS;
            System.out.println(RED_BOLD + "Потерянно " + (heroHP - newHeroHP) + " HP!" + RESET);
            hero.setHp(newHeroHP);
        } else {
            System.out.println(RED_BOLD + "Проигрыш!" + RESET);
            System.out.println(RED_BOLD + "Игрока убило существо " + RESET + BLACK_BOLD + "\"" +
                    creatures.get(idOfCreatures).getName() + "\"" + RESET + ".");
            System.exit(0);
        }
    }

    public static void gameOver(){
        System.out.println(GREEN_BOLD + "ИГРА ОКОНЧЕННА!" + RESET);
    }

    public static int getHeroHP(){
        return hero.getHp();
    }

    public static int getHeroDPS() {
        int atk = hero.getAtk();
        ArrayList<Equipment> equipment = hero.getEquipment();
        int weapon = equipment.get(0).getWeapon();

        return weapon * atk;
    }

    public static int getCreatureDPS(int i) {
        int atk = creatures.get(i).getAtk();
        ArrayList<Equipment> equipment = creatures.get(i).getEquipment();
        int weapon = equipment.get(0).getWeapon();

        return weapon * atk;
    }
}
