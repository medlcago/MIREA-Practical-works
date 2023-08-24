package JavaLabs.Lab_3;

import java.util.ArrayList;

public class Main {

    public static final String RESET = "\033[0m";
    public static final String GREEN_BOLD = "\033[1;32m";
    public static final String RED_BOLD = "\033[1;31m";

    static ArrayList<Creature> creatures = new ArrayList<>();
    static char[][] gameField = new char[10][10];
    static Creature hero;
    static int coordinatesOfHeroX = 0;
    static int coordinatesOfHeroY = 0;


    public static void main(String[] args) {
        showSpace();
        for (int i = 0; i < 10; i++) {
            creatures.add(Creation.createCreatures(i));
        }
        hero = Creation.createHero();
        showHero();
        showCreatures();
        showSpace();
        gameField = Creation.createFields(creatures);
        showField();

        CreatureController creatureController = new CreatureController();
        Thread childTread = new Thread(creatureController);
        childTread.start();

    }

    public static void showHero() {
        System.out.println(GREEN_BOLD + "Главный герой: " + RESET);
        System.out.println(hero.toString());
    }

    public static void showCreatures() {
        System.out.println(RED_BOLD + "Существа и их свойства: " + RESET);
        for (Creature c : creatures) {
            System.out.println(c.toString());
        }
    }

    public static void showField() {
        char buff =  gameField[coordinatesOfHeroX][coordinatesOfHeroY];
        gameField[coordinatesOfHeroX][coordinatesOfHeroY] = '@';

        for (char[] chars : gameField) {
            for (char aChar : chars) {
                switch (aChar) {
                    case '*' -> System.out.print(aChar + " ");
                    case '@' -> System.out.print(GREEN_BOLD + aChar + RESET + " ");
                    default -> System.out.print(RED_BOLD + aChar + RESET + " ");
                }
            }
            System.out.println(" ");
        }
        gameField[coordinatesOfHeroX][coordinatesOfHeroY] = buff;
    }

    public static void showSpace() {
        System.out.println(" ");
        System.out.println("-------------------------");
        System.out.println(" ");
    }

}
