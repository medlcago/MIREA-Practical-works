package JavaLabs.Lab_1;
public class Enemy {

    private String name;
    private int hp, atk, deff;

    public Enemy(String name, int hp, int atk, int deff) {
        this.name = name;
        this.hp = hp;
        this.atk = atk;
        this.deff = deff;
    }

    public String toString(){
        return "Название: " + name + "; Очки здоровья: " + hp + "; Сила атаки: " + atk + "; Уровень защиты: " + deff + ";";
    }

}
