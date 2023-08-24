package JavaLabs.Lab_7.Task_1;

import java.io.*;
import java.net.Socket;
import java.util.Scanner;

public class Client {

    static final String RESET = "\033[0m";
    static final String RED_BOLD = "\033[1;31m";
    static final String BLACK_BOLD = "\033[1;30m";
    static final String GREEN_BOLD = "\033[1;32m";

    static Scanner sc = new Scanner(System.in);
    static BufferedWriter out;
    static BufferedReader in;

    public static void main(String[] args) throws IOException {

        Socket clientSocket = new Socket("127.0.0.1", 27001);
        System.out.println(GREEN_BOLD + "Вы подключились к серверу!" + RESET);

        while (true) {
            out = new BufferedWriter(new OutputStreamWriter(clientSocket.getOutputStream()));
            in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

            System.out.println(BLACK_BOLD + "Возможные действия: " + RESET);
            System.out.println(BLACK_BOLD + "0." + RESET + " Отключится от сервера.");
            System.out.println(BLACK_BOLD + "1." + RESET + " Отправить сообщение на сервер.");
            System.out.println(BLACK_BOLD + "2." + RESET + " Ввести пароль для получения файла.");
            System.out.print(BLACK_BOLD + "Выберите цифру: " + RESET);
            int number = sc.nextInt();
            switch (number) {
                case 0 -> {
                    System.out.println(RED_BOLD + "Отключение!" + RESET);
                    out.close();
                    return;
                }
                case 1 -> {
                    System.out.print(BLACK_BOLD + "Введите сообщение, которое хотели бы отправить на сервер: " + RESET);
                    String message = sc.next();
                    out.write(message + "\n");
                    out.flush();
                    showSpace();
                }
                case 2 -> {
                    System.out.print(BLACK_BOLD + "Введите пароль для получения файла: " + RESET);
                    String password = sc.next();
                    out.write("$" + password + "\n");
                    out.flush();
                    String word = in.readLine();
                    if (word.equals("1")) {
                        System.out.println(GREEN_BOLD + "Пароль верный!" + RESET);

                        String fileTextFromServer = in.readLine();
                        FileWriter writer = new FileWriter("client_file.txt");
                        writer.write(fileTextFromServer);
                        writer.flush();

                        System.out.println("Файл " + GREEN_BOLD + "был получен " + RESET + "с сервера!");

                        System.out.println(RED_BOLD + "Отключение!" + RESET);
                        out.close();
                        return;
                    } else {
                        System.out.println(RED_BOLD + "Пароль не верный!" + RESET);
                        System.out.println("Файл " + RED_BOLD + "не был получен " + RESET + "с сервера!");
                    }
                    showSpace();
                }
                default -> System.out.println(RED_BOLD + "Ошибка!" + RESET);
            }
        }
    }

    public static void showSpace() {
        System.out.println(BLACK_BOLD + "-------------------------" + RESET);
    }
}
