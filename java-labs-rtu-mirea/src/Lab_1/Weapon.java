package JavaLabs.Lab_1;

public class Weapon {
    private String name;
    private int atack, coast, need_level;

    public Weapon(String name, int atack, int coast, int need_level) {
        this.name = name;
        this.atack = atack;
        this.coast = coast;
        this.need_level = need_level;
    }

    public String toString(){
        return "Название: " + name + "; Сила атаки: " + atack + "; Цена: " + coast + "; Необходимый уровень: " + need_level + ";";
    }

}
