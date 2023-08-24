package JavaLabs.Lab_3;

import java.util.ArrayList;

public class Creature {

    public static final String RESET = "\033[0m";
    public static final String BLACK_BOLD = "\033[1;30m";

    String name;
    int hp;
    int atk;
    ArrayList<Equipment> equipment = new ArrayList<>();

    public Creature(String name, int hp, int atk, Equipment equipment) {
        this.name = name;
        this.hp = hp;
        this.atk = atk;
        this.equipment.add(equipment);
    }

    public void setHp(int hp){
        this.hp = hp;
    }

    public String toString() {
        return BLACK_BOLD + "Название существа: " + RESET + name +
                BLACK_BOLD + "; Здоровье: " + RESET + hp +
                BLACK_BOLD + "; Атака: " + RESET + atk +
                BLACK_BOLD + "; Экипировка: " + RESET + equipment.toString() +
                BLACK_BOLD + ";" + RESET;
    }

    public String getInfoHero(){
        return BLACK_BOLD + "Здоровье: " + RESET + hp +
                BLACK_BOLD + "; Атака: " + RESET + atk +
                BLACK_BOLD + "; Экипировка: " + RESET + equipment.toString() +
                BLACK_BOLD + ";" + RESET;
    }

    public String getName() {
        return name;
    }

    public int getAtk(){
        return atk;
    }

    public int getHp(){
        return hp;
    }

    public ArrayList<Equipment> getEquipment(){
        return equipment;
    }
}
