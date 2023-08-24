package JavaLabs.Lab_7.Task_1;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {

    static final String RESET = "\033[0m";
    static final String RED_BOLD = "\033[1;31m";
    static final String BLACK_BOLD = "\033[1;30m";
    static final String GREEN_BOLD = "\033[1;32m";

    static ServerSocket serverSocket;
    static Socket clientSocket;
    static BufferedReader in;
    static PrintWriter out;

    static String mainPassword = "12345";

    public static void main(String[] args) throws IOException {

        serverSocket = new ServerSocket(27001);

        System.out.println(GREEN_BOLD + "Сервер был запущен!" + RESET);
        showSpace();
        System.out.println(GREEN_BOLD + "Ожидание подключений" + RESET);
        showSpace();

        clientSocket = serverSocket.accept();
        System.out.println(GREEN_BOLD + "Соединение установленно." + RESET);
        in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

        while (true) {
            out = new PrintWriter(new OutputStreamWriter(clientSocket.getOutputStream()));
            String word = in.readLine();
            if (word == null) {
                System.out.println(RED_BOLD + "Соединение прерванно." + RESET);
                in.close();
                return;
            } else {
                if (word.charAt(0) == '$') {
                    if (checkPassword(word)) {
                        System.out.println(GREEN_BOLD + "Пользователь ввел верный пароль: " + RESET + word + "$");
                        out.println("1");

                        StringBuilder textFromFileBuilder = new StringBuilder();
                        try (FileReader reader = new FileReader("server_file.txt")) {
                            int c;
                            while ((c = reader.read()) != -1) {
                                textFromFileBuilder.append((char) c);
                            }
                        }
                        String textFromFile = String.valueOf(textFromFileBuilder);
                        System.out.println("Файл " + BLACK_BOLD + "\"server_file.txt\"" + RESET +
                                GREEN_BOLD + " отправлен" + RESET + " клиенту!");
                        out.println(textFromFile);
                        out.flush();
                    } else {
                        System.out.println(RED_BOLD + "Пользователь ввел не верный пароль: " + RESET + word + "$");
                        System.out.println("Файл " + BLACK_BOLD + "\"server_file.txt\"" + RESET +
                                RED_BOLD + " не отправлен" + RESET + " клиенту!");
                        out.write("0" + "\n");
                    }
                    out.flush();
                } else {
                    System.out.println(BLACK_BOLD + "Полученное сообщение: " + RESET + word);
                }
            }
        }
    }

    public static boolean checkPassword(String buff_password) {
        StringBuilder new_password = new StringBuilder();
        for (int i = 1; i < buff_password.length(); i++) {
            new_password.append(buff_password.charAt(i));
        }
        return new_password.toString().equals(mainPassword);
    }

    public static void showSpace() {
        System.out.println(BLACK_BOLD + "-------------------------" + RESET);
    }
}
