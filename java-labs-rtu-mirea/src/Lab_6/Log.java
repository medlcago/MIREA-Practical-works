package JavaLabs.Lab_6;

import java.util.ArrayList;

public class Log {

    static ArrayList<String> logHistory = new ArrayList<>();

    public static void AddLog(String message) {
        logHistory.add(message);
    }

    public static ArrayList<String> getLogHistory() {
        return logHistory;
    }
}
