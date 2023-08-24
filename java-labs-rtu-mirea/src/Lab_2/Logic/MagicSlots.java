package JavaLabs.Lab_2.Logic;

import java.util.ArrayList;

public class MagicSlots<A extends Spell<?>> {

    ArrayList<Spell<?>> spellsList = new ArrayList(3);

    public void addSpell(A spell){
        if(spellsList.size() <= 3){
            spellsList.add(spell);
        }else{
            System.out.println("");
            spellsList.add(spell);
        }
    }
}