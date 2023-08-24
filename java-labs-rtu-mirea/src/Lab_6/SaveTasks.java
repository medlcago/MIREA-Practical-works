package JavaLabs.Lab_6;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import static JavaLabs.Lab_6.Main.masTask;

public class SaveTasks {

    public static void createFileWithTasks() {
        try (FileWriter taskWriter = new FileWriter("tasks.txt");
             BufferedWriter bufferedWriter = new BufferedWriter(taskWriter)) {
            for (Task t : masTask) {
                String s = t.toTextFile() + "\n";
                bufferedWriter.write(s);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
