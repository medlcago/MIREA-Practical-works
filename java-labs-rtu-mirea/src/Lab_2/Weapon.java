package JavaLabs.Lab_2;

import JavaLabs.Lab_2.Structure.Things;

public class Weapon extends Things {

    public Weapon(String get_name, int get_id, int get_level, int get_damage){
        this.name = get_name;
        this.id  = get_id;
        this.level = get_level;
        this.damage = get_damage;
    }

    public String toString(){
        return "Название: " + this.name + "; ID: " + this.id + "; Уровень: " + this.level + "; Урон: " + this.damage + ";";
    }
}
