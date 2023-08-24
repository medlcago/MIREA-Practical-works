package JavaLabs.Lab_2.MagicElements;

import JavaLabs.Lab_2.Logic.Element;

public class Air implements Element {
    @Override
    public int getDamage() {
        return 5;
    }

    @Override
    public String getElementName() {
        return "Воздух";
    }
}
