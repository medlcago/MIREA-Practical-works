package JavaLabs.Lab_7.Task_2;

import java.io.*;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Scanner;

class SenderWriteMessage extends Thread {

    static final String RESET = "\033[0m";
    static final String RED_BOLD = "\033[1;31m";
    static final String BLUE_BOLD = "\033[1;34m";
    static final String BLACK_BOLD = "\033[1;30m";
    static final String GREEN_BOLD = "\033[1;32m";

    static Scanner sc = new Scanner(System.in);
    static PrintWriter out;
    static String name;

    static ArrayList<Cat> cats = new ArrayList<>();

    public SenderWriteMessage(PrintWriter out, Scanner sc, String name) {
        SenderWriteMessage.out = out;
        SenderWriteMessage.sc = sc;
        SenderWriteMessage.name = name;
    }

    @Override
    public void run() {
        while (true) {
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            String message = enterMessage();
            out.println(name);
            out.flush();

            if (message.equals("%stop%")) {
                out.println(message);
                out.flush();
                System.out.println("Клиент " + BLACK_BOLD + name + RESET + RED_BOLD + " покинул сервер!" + RESET);
                out.close();
                break;
            }

            if (message.equals("%create_cat%")) {
                addCat();
                System.out.println(BLACK_BOLD + name + RESET + ": " + GREEN_BOLD + "создал " + RESET + "нового кота!");
            }

            if (message.equals("%show_cats%")) {
                showCats();
                System.out.println(BLACK_BOLD + name + RESET + ": " + GREEN_BOLD + "вывел " + RESET + "всех своих котов!");
            }

            if (message.equals("%send_cat%")) {
                System.out.println(BLACK_BOLD + name + RESET + ": " + GREEN_BOLD + "отправил " + RESET + "информацию об одном коте!");
            }

            out.println(message);
            out.flush();
        }
    }

    public static String enterMessage() {
        System.out.print(BLUE_BOLD + name + RESET + ": ");
        return sc.nextLine();
    }

    public static void addCat() {
        Server.showSpace();
        int id = cats.size() + 1;
        System.out.print(BLACK_BOLD + "Введите имя кота: " + RESET);
        String name = sc.nextLine();
        System.out.print(BLACK_BOLD + "Введите возраст кота: " + RESET);
        int age = sc.nextInt();
        System.out.print(BLACK_BOLD + "Введите рост кота: " + RESET);
        int height = sc.nextInt();
        System.out.print(BLACK_BOLD + "Введите вес кота: " + RESET);
        int weight = sc.nextInt();
        Server.showSpace();

        cats.add(new Cat(id, name, age, height, weight));
    }

    public static void showCats() {
        Server.showSpace();
        for (Cat cat : cats) {
            System.out.println(cat.toString());
        }
        Server.showSpace();
    }
}

class SenderGetMessage extends Thread {

    static final String RESET = "\033[0m";
    static final String BLACK_BOLD = "\033[1;30m";
    static final String BLUE_BOLD = "\033[1;34m";

    static BufferedReader in;
    static String myName;

    public SenderGetMessage(BufferedReader in, String name) {
        SenderGetMessage.in = in;
        SenderGetMessage.myName = name;
    }

    @Override
    public void run() {
        while (true) {
            String name = null;
            String word = null;
            try {
                name = in.readLine();
                word = in.readLine();
            } catch (IOException ignored) {
            }
            if (name != null && word != null) {
                if (name.equals(myName) && word.equals("%stop%")) {
                    interrupt();
                    break;
                } else {
                    if (name.equals(myName)) {
                        System.out.println(BLACK_BOLD + "%" + name + "%: " + RESET + word);
                    } else {
                        System.out.println("\n" + BLACK_BOLD + "%" + name + "%: " + RESET + word);
                        System.out.print(BLUE_BOLD + myName + RESET + ": ");
                    }
                }
            } else {
                interrupt();
                break;
            }
        }
    }
}

public class Sender {

    static final String RESET = "\033[0m";
    static final String RED_BOLD = "\033[1;31m";
    static final String BLACK_BOLD = "\033[1;30m";
    static final String GREEN_BOLD = "\033[1;32m";

    static Scanner sc = new Scanner(System.in);
    static PrintWriter out;
    static BufferedReader in;
    static String name;

    public static void main(String[] args) throws IOException {

        System.out.print(BLACK_BOLD + "Для подключения к серверу введите свое имя: " + RESET);
        name = sc.nextLine();

        Socket clientSocket = new Socket("127.0.0.1", 27001);
        System.out.println(GREEN_BOLD + "Вы подключились к серверу!" + RESET);
        out = new PrintWriter(new OutputStreamWriter(clientSocket.getOutputStream()));
        in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
        out.println(name);
        out.flush();

        System.out.println("Для того чтобы " + BLACK_BOLD + "отправить пользователям сообщение " + RESET +
                "- введите текст и нажмите " + BLACK_BOLD + "\"Enter\" ." + RESET);
        System.out.println("Для того чтобы " + BLACK_BOLD + "создать нового кота " + RESET +
                "- введите " + GREEN_BOLD + "\"%create_cat%\"." + RESET);
        System.out.println("Для того чтобы " + BLACK_BOLD + "посмотреть всех котов " + RESET +
                "- введите " + GREEN_BOLD + "\"%show_cats%\"." + RESET);
        System.out.println("Для того чтобы " + BLACK_BOLD + "отправить кота " + RESET +
                "другим пользователям - введите " + GREEN_BOLD + "\"%send_cat%\". " + RESET);
        System.out.println("Для того чтобы " + BLACK_BOLD + "покинуть " + RESET +
                "данный сервер - введите " + RED_BOLD + "\"%stop%\"" + RESET);
        showSpace();

        SenderGetMessage senderGetMessage = new SenderGetMessage(in, name);
        SenderWriteMessage senderWriteMessage = new SenderWriteMessage(out, sc, name);
        senderWriteMessage.start();
        senderGetMessage.start();
    }

    public static void showSpace() {
        System.out.println(BLACK_BOLD + "-------------------------" + RESET);
    }
}

