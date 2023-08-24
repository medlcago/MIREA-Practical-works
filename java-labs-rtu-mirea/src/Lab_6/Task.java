package JavaLabs.Lab_6;

public class Task {

    public static final String RESET = "\033[0m";
    public static final String BLACK_BOLD = "\033[1;30m";

    int id;
    String name;
    int hoursToComplete;
    String info;
    int fee;
    int numberEmployer;
    String status;

    public Task(int id, String name, int hoursToComplete, String info, int fee, int numberEmployer, String status) {
        this.id = id;
        this.name = name;
        this.hoursToComplete = hoursToComplete;
        this.info = info;
        this.fee = fee;
        this.numberEmployer = numberEmployer;
        this.status = status;
    }

    public String toString() {
        return BLACK_BOLD + "ID: " + RESET + id +
                BLACK_BOLD + "; Название задачи: " + RESET + name +
                BLACK_BOLD + "; Часов на выполнение: " + RESET + hoursToComplete +
                BLACK_BOLD + "; Информация: " + RESET + info +
                BLACK_BOLD + "; Гонорар: " + RESET + fee +
                BLACK_BOLD + "; Номер работника: " + RESET + numberEmployer +
                BLACK_BOLD + "; Статус: " + RESET + status +
                BLACK_BOLD + ";" + RESET;
    }

    public String toTextFile() {
        return "ID: " + id +
                "; Название задачи: " + name +
                "; Часов на выполнение: " + hoursToComplete +
                "; Информация: " + info +
                "; Гонорар: " + fee +
                "; Номер работника: " + numberEmployer +
                "; Статус: " + status +
                ";";
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public int getHoursToComplete() {
        return hoursToComplete;
    }

    public int getFee() {
        return fee;
    }
}
