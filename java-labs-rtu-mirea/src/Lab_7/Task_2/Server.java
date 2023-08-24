package JavaLabs.Lab_7.Task_2;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.LinkedList;

class ServerMultithreading extends Thread {

    static final String RESET = "\033[0m";
    static final String RED_BOLD = "\033[1;31m";
    static final String BLUE_BOLD = "\033[1;34m";
    static final String GREEN_BOLD = "\033[1;32m";

    private final BufferedReader in;
    private final PrintWriter out;

    public ServerMultithreading(Socket socket) throws IOException {
        in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        out = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()));
        start();
    }

    @Override
    public void run() {
        try {
            while (true) {
                String name = in.readLine();
                String word = in.readLine();
                if (!word.equals(" ")) {
                    if (word.equals("%stop%")) {
                        System.out.println(BLUE_BOLD + "%" + name + "%: " + RESET + RED_BOLD + "покинул сервер.");
                        for (ServerMultithreading vr : Server.serverList) {
                            vr.sendStopMessage(name);
                        }
                        break;
                    }
                    switch (word) {
                        case "%create_cat%" -> System.out.println(BLUE_BOLD + "%" + name + "%: " + RESET + GREEN_BOLD + "создал" + RESET + " нового кота.");
                        case "%show_cats%" -> System.out.println(BLUE_BOLD + "%" + name + "%: " + RESET + GREEN_BOLD + "вывел" + RESET + " всех своих котов.");
                        case "%send_cat%" -> System.out.println(BLUE_BOLD + "%" + name + "%: " + RESET + GREEN_BOLD + "отправил" + RESET + " другому пользователю кота.");
                        default -> {
                            System.out.println(BLUE_BOLD + "%" + name + "%: " + RESET + word);
                            for (ServerMultithreading vr : Server.serverList) {
                                vr.sendMessage(word, name);
                            }
                        }
                    }
                }

            }
        } catch (IOException ignored) {
            System.out.println(RED_BOLD + "Ошибка!" + RESET);
        }
    }

    private void sendStopMessage(String name) {
        out.println(name);
        out.flush();
        out.println("%stop%");
        out.flush();
    }

    private void sendMessage(String msg, String name) {
        out.println(name);
        out.flush();
        out.println(msg);
        out.flush();
    }
}

public class Server {

    static final String RESET = "\033[0m";
    static final String BLUE_BOLD = "\033[1;34m";
    static final String BLACK_BOLD = "\033[1;30m";
    static final String GREEN_BOLD = "\033[1;32m";

    public static LinkedList<ServerMultithreading> serverList = new LinkedList<>();
    public static ArrayList<String> nameList = new ArrayList<>();
    static ServerSocket serverSocket;
    static Socket clientSocket;
    static BufferedReader in;

    public static void main(String[] args) throws IOException {

        serverSocket = new ServerSocket(27001);
        System.out.println(GREEN_BOLD + "Сервер был запущен!" + RESET);
        showSpace();
        System.out.println(BLUE_BOLD + "Ожидание подключений..." + RESET);
        showSpace();

        while (true) {
            clientSocket = serverSocket.accept();
            in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            String name = in.readLine();
            System.out.println(GREEN_BOLD + "Соединение установленно " + RESET + "c клиентом " + BLACK_BOLD + name + RESET + ".");

            nameList.add(name);
            serverList.add(new ServerMultithreading(clientSocket));
        }
    }

    public static void showSpace() {
        System.out.println(BLACK_BOLD + "---------------" + RESET);
    }
}
