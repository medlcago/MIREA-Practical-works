package JavaLabs.Lab_2;

import JavaLabs.Lab_2.Structure.Creatures;

public class Hero extends Creatures {

    public Hero(String get_name, int get_id, int get_level, int get_damage, int get_hp, int get_defence){
        this.name = get_name;
        this.id  = get_id;
        this.level = get_level;
        this.damage_speed = get_damage;
        this.hp = get_hp;
        this.defence = get_defence;
    }

    public String toString(){

        return "Название: " + this.name + "; ID: " + this.id + "; Уровень: " + this.level + "; Ударов в секунду: " + this.damage_speed + "; Здоровье: " + this.hp + "; Защита: " + this.defence + ";";
    }
}
