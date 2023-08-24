package JavaLabs.Lab_3;

public class Equipment {

    public static final String RESET = "\033[0m";
    public static final String BLACK_BOLD = "\033[1;30m";

    int armor;
    int weapon;

    public Equipment(int armor, int weapon) {
        this.armor = armor;
        this.weapon = weapon;
    }

    public String toString() {
        return BLACK_BOLD + "Броня: " + RESET + armor +
                BLACK_BOLD + "; Оружие: " + RESET + weapon +
                BLACK_BOLD + ";" + RESET;
    }

    public int getWeapon(){
        return weapon;
    }
}
