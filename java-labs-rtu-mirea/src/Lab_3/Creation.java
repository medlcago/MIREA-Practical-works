package JavaLabs.Lab_3;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;

public class Creation {

    public static Creature createHero(){
        String buff_name = "@";
        int buff_hp = 1500;
        int buff_atk = 20;
        int buff_armor = 250;
        int buff_weapon = 15;
        Equipment buff_equipment = new Equipment(buff_armor, buff_weapon);

        return new Creature(buff_name, buff_hp, buff_atk, buff_equipment);
    }

    public static Creature createCreatures(int i) {
        Random rnd = new Random();
        String[] names = {"Андрей", "Борис", "Владимир",
                "Георгий", "Дмитрий", "Елена",
                "Жора", "Зинаида", "Ирина", "Кирилл"};
        String buff_name = names[i];
        int buff_hp = 1000;
        int buff_atk = rnd.nextInt((20) + 1);
        int buff_armor = rnd.nextInt((500) + 1);
        int buff_weapon = rnd.nextInt((20) + 1);
        Equipment buff_equipment = new Equipment(buff_armor, buff_weapon);

        return new Creature(buff_name, buff_hp, buff_atk, buff_equipment);
    }

    public static char[][] createFields(ArrayList<Creature> creatures) {
        char[][] gameField = new char[10][10];
        int[] coordinatesPlayersX = new int[10];
        int[] coordinatesPlayersY = new int[10];

        for (char[] chars : gameField) {
            Arrays.fill(chars, '*');
        }

        for (int i = 0; i < coordinatesPlayersX.length; i++) {
            coordinatesPlayersX[i] = (int) (Math.random() * 10);
            coordinatesPlayersY[i] = (int) (Math.random() * 10);
            for (int j = 0; j < i; j++) {
                if (coordinatesPlayersX[i] == coordinatesPlayersX[j] &&
                        coordinatesPlayersY[i] == coordinatesPlayersY[j] &&
                        coordinatesPlayersX[i] == 0 && coordinatesPlayersY[i] == 0) {
                    i--;
                    break;
                }
            }
        }

        for (int i = 0; i < 10; i++) {
            int X = coordinatesPlayersX[i];
            int Y = coordinatesPlayersY[i];
            char head = creatures.get(i).getName().charAt(0);
            gameField[X][Y] = head;
        }

        return gameField;
    }
}
