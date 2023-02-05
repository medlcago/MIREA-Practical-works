#include <stdio.h>
#include <string.h>
#include <Windows.h>

const char TEXT = 0, STRING_LETTERS = 'a', BINARY_NUMBER = 2, DECIMAL_NUMBER = 10, OCTAL_NUMBER = 8, HEXADIMAL_NUMBER = 16;

char stringType(char text[])
{
    bool flag = true;

    for (int i = 0; i < strlen(text) && flag; i++)
        if (!(text[i] >= 'a' && text[i] <= 'z' || text[i] >= 'A' && text[i] <= 'Z' || text[i] >= 'а' && text[i] <= 'я' || text[i] >= 'А' && text[i] <= 'Я'))
            flag = false;

    if (flag)
        return STRING_LETTERS;

    flag = true;

    for (int i = 0; i < strlen(text) && flag; i++)
        if (!(text[i] >= '0' && text[i] <= '1'))
            flag = false;

    if (flag)
        return BINARY_NUMBER;

    flag = true;

    for (int i = 0; i < strlen(text) && flag; i++)
        if (!(text[i] >= '0' && text[i] <= '7'))
            flag = false;

    if (flag)
        return OCTAL_NUMBER;

    flag = true;

    for (int i = 0; i < strlen(text) && flag; i++)
        if (!(text[i] >= '0' && text[i] <= '9'))
            flag = false;

    if (flag)
        return DECIMAL_NUMBER;

    flag = true;

    for (int i = 0; i < strlen(text) && flag; i++)
        if (!(text[i] >= '0' && text[i] <= '9' || text[i] >= 'A' && text[i] <= 'F' || text[i] >= 'a' && text[i] <= 'f'))
            flag = false;

    if (flag)
        return HEXADIMAL_NUMBER;

    return TEXT;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char text[30];
    printf("Введите строку: ");
    gets_s(text, 30);

    switch (stringType(text))
    {
        case STRING_LETTERS:
            printf("%s - это строка букв!\n", text);
            break;

        case BINARY_NUMBER:
            printf("%s - это двоичное число!\n", text);
            break;

        case OCTAL_NUMBER:
            printf("%s - это восьмеричное число!\n", text);
            break;

        case DECIMAL_NUMBER:
            printf("%s - это десятичное число!\n", text);
            break;

        case HEXADIMAL_NUMBER:
            printf("%s - это шестнадцатеричное число!\n", text);
            break;

        default:
            printf("%s - это обычный текст!\n", text);
            break;
    }

    return 0;
}
