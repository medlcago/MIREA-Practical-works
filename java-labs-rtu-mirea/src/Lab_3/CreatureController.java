package JavaLabs.Lab_3;

import java.util.concurrent.TimeUnit;

import static JavaLabs.Lab_3.Main.*;

public class CreatureController implements Runnable {

    public static final String RESET = "\033[0m";
    public static final String BLACK_BOLD = "\033[1;30m";
    public static final String GREEN_BOLD = "\033[1;32m";

    @Override
    public void run() {
        System.out.println(GREEN_BOLD + "Начало игры через 10 секунд!" + RESET);
        try {
            TimeUnit.SECONDS.sleep(10);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        for (int i = 0; i < 10; i++) {
            coordinatesOfHeroX = i;
            coordinatesOfHeroY = 0;
            for (int j = 0; j < 10; j++) {
                coordinatesOfHeroY = j;
                showSpace();
                showField();
                System.out.println(GREEN_BOLD + "Состояние игрока: " + RESET + hero.getInfoHero());
                System.out.println(GREEN_BOLD + "Координаты игрока: " + RESET +
                        BLACK_BOLD + coordinatesOfHeroX + ":" + coordinatesOfHeroY + RESET);

                if (gameField[coordinatesOfHeroX][coordinatesOfHeroY] != '*'){
                    GameLogic.startBattle(gameField[coordinatesOfHeroX][coordinatesOfHeroY]);
                }
                    try {
                    TimeUnit.SECONDS.sleep(2);
                    } catch (InterruptedException e) {
                    e.printStackTrace();
                    }
            }
        }
        GameLogic.gameOver();
    }
}
