package JavaLabs.Lab_2.MagicElements;

import JavaLabs.Lab_2.Logic.Element;

public class Water implements Element {
    @Override
    public int getDamage() {
        return 2;
    }

    @Override
    public String getElementName() {
        return "Вода";
    }
}
