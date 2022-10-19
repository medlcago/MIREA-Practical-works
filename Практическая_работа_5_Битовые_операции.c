#include <stdio.h>
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    unsigned short n;
    unsigned short u, r, w, e, x;
    unsigned int UnitStateWord;

    printf("1 - упаковать структуру\n2 - распаковать структуру\n");
    scanf_s("%hu", &n);

    switch (n) {
        case 1:
            printf("Маски каналов (0 - 7): ");
            scanf_s("%hu", &u);

            printf("Маска внешнего прерывания (0 - 1): ");
            scanf_s("%hu", &r);

            printf("Маска внутреннего прерывания (0 - 1): ");
            scanf_s("%hu", &w);

            printf("Маска программного прерывания (0 - 1): ");
            scanf_s("%hu", &e);

            printf("Ключ защиты памяти (0 - 7): ");
            scanf_s("%hu", &x);

            UnitStateWord = (u & 0xF) << 12;
            UnitStateWord |= (r & 1) << 11;
            UnitStateWord |= (w & 1) << 10;
            UnitStateWord |= (e & 1) << 9;
            UnitStateWord |= (x & 7) << 3;

            printf("\nСлово состояния устройства\nШестнадцатеричное представление: %04x\nДесятичное представление: %d\n", UnitStateWord, UnitStateWord);
            break;
        case 2:
            printf("Введите cлово состояния устройства (16 - ричное число от 0 до 0xFFFF): ");
            scanf_s("%x", &UnitStateWord);

            u = (UnitStateWord >> 12) & 0xF;
            r = (UnitStateWord >> 11) & 1;
            w = (UnitStateWord >> 10) & 1;
            e = (UnitStateWord >> 9) & 1;
            x = (UnitStateWord >> 3) & 7;

            printf("\nмаски каналов = %hu\n", u);
            printf("маска внешнего прерывания = %hu\n", r);
            printf("маска внутреннего прерывания = %d\n", w);
            printf("маска программного прерывания = %hu\n", e);
            printf("ключ защиты памяти = %hu\n", x);
            break;
        default:
            printf("Wrong data!\n");
    }

    return 0;
}
