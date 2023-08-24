package JavaLabs.Lab_2.Logic;

import java.util.Random;

public class GameLogic{

    public String get_DPS(){
        String DPS = "";
        Random rnd = new Random();
        int a = rnd.nextInt((100)+1);
        int b = rnd.nextInt((100) + 1);
        DPS = "DPS = " + (a*b);
        return DPS;
    }
}
