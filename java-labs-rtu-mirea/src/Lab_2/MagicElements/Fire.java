package JavaLabs.Lab_2.MagicElements;

import JavaLabs.Lab_2.Logic.Element;

public class Fire implements Element {
    @Override
    public int getDamage() {
        return 8;
    }

    @Override
    public String getElementName() {
        return "Огонь";
    }
}