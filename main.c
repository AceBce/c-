#include <stdio.h>
#include <stdlib.h>

int hasDays(int year) {
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return 366;
    return 365;
}
int getWeek1Monthday(int year) {
    int days = 0;
    for (int i = 1900; i < year; i++) {
        days += hasDays(i);
    }
    return days % 7 + 1;
}
int monthDays[13] = {
        0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
int main() {
    int year;
    scanf("%d", &year);
    if (year < 1900) {
        printf("时间过于久远，就请遗忘掉吧～\n");
        return 0;
    }
    if (hasDays(year) == 366) {
        monthDays[2] = 29;
    }
    int firstDay = getWeek1Monthday(year);
    int day;
    for (int i = 1; i <= 12; i++) {
        printf("           %d年%d月\n", year, i);
        day = 1;
        printf("周一 周二 周三 周四 周五 周六 周日\n");
        for (int j = 1; j < firstDay; j++) {
            printf("%*s", 5, " ");
        }
        while (day <= monthDays[i]) {
            printf("%3d  ", day);
            firstDay++;
            if (firstDay == 8) {
                if (day < monthDays[i])
                    printf("\n");
                firstDay = 1;
            }
            day++;
        }
        printf("\n");
    }

    system("pause");
    return 0;
}
