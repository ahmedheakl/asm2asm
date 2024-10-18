#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int func0(const char *date) {
    int mm, dd, yy;

    if (strlen(date) != 10) return 0;
    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) {
            if (date[i] != '-') return 0;
        } else {
            if (date[i] < '0' || date[i] > '9') return 0;
        }
    }

    char str_month[3] = {date[0], date[1], '\0'};
    char str_day[3] = {date[3], date[4], '\0'};
    char str_year[5] = {date[6], date[7], date[8], date[9], '\0'};

    mm = atoi(str_month);
    dd = atoi(str_day);
    yy = atoi(str_year);

    if (mm < 1 || mm > 12) return 0;
    if (dd < 1 || dd > 31) return 0;
    if ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && dd == 31) return 0;
    if (mm == 2 && dd > 29) return 0;

    return 1;
}
