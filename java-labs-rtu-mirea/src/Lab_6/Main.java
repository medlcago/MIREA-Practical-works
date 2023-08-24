package JavaLabs.Lab_6;

import java.util.ArrayList;

public class Main {

    public static ArrayList<Employer> masEmployer = new ArrayList<>();
    public static ArrayList<Task> masTask = new ArrayList<>();

    public static void main(String[] args) {
        AutoSaveLog autoSaveLog = new AutoSaveLog();
        Thread childTread = new Thread(autoSaveLog);
        childTread.start();
        Log.AddLog("Start Program.");

        Logic logic = new Logic();
        Thread logicThread = new Thread(logic);
        logicThread.start();

        View.menu();
    }
}
