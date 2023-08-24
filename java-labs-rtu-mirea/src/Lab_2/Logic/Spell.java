package JavaLabs.Lab_2.Logic;

public class Spell <T extends Element>{
    T element;

    public Spell(T element){
        this.element = element;
    }

    public int cast(){
        return element.getDamage();
    }

}
