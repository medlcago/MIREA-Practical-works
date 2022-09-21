#include <stdio.h>
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char kind_transp1[20], route1[20], route_len1[10]; float travel_time1;
    char kind_transp2[20], route2[20], route_len2[10]; float travel_time2;
    char kind_transp3[20], route3[20], route_len3[10]; float travel_time3;


    scanf_s("%s%s%s%f", kind_transp1, 20, route1, 20, route_len1, 10, &travel_time1);
    while (getchar() != '\n');
    scanf_s("%s%s%s%f", kind_transp2, 20, route2, 20, route_len2, 10, &travel_time2);
    while (getchar() != '\n');
    scanf_s("%s%s%s%f", kind_transp3, 20, route3, 20, route_len3, 10, &travel_time3);

    printf("|------------------------------------------------------------------------------------------------|");
    printf("\n|Ведомость общественного транспорта                                                              |");
    printf("\n|------------------------------------------------------------------------------------------------|");
    printf("\n|Вид транспорта      |Маршрут             |Протяженность маршрута (км)      |Время в дороге (мин)|");
    printf("\n|------------------------------------------------------------------------------------------------|");
    printf_s("\n|%-20s|%-20s|%-10s                       |%-10.2f          |", kind_transp1, route1, route_len1, travel_time1);
    printf("\n|------------------------------------------------------------------------------------------------|");
    printf_s("\n|%-20s|%-20s|%-10s                       |%-10.2f          |", kind_transp2, route2, route_len2, travel_time2);
    printf("\n|------------------------------------------------------------------------------------------------|");
    printf_s("\n|%-20s|%-20s|%-10s                       |%-10.2f          |", kind_transp3, route3, route_len3, travel_time3);
    printf("\n|------------------------------------------------------------------------------------------------|");
    printf("\n|Примечание: Тр - трамвай, Тс - троллейбус, А - автобус                                          |");
    printf("\n|------------------------------------------------------------------------------------------------|");

    return 0;
}