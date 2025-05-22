#include <stdio.h>

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDayOfWeek(int year, int month, int day) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int h = (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
    return h;
}

void displayCalendar(int year, int month) {
    int daysInMonth[] = {0, 31, isLeapYear(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayOfWeek = getDayOfWeek(year, month, 1);

    printf("\n============================= Calendar =============================\n");
    printf("       %s %d\n", (month == 1) ? "January" : (month == 2) ? "February" : (month == 3) ? "March" : (month == 4) ? "April" : (month == 5) ? "May" : (month == 6) ? "June" : (month == 7) ? "July" : (month == 8) ? "August" : (month == 9) ? "September" : (month == 10) ? "October" : (month == 11) ? "November" : "December", year);
    printf("---------------------------------------------------------------------\n");
    printf(" Sun Mon Tue Wed Thu Fri Sat\n");

    for (int i = 0; i < dayOfWeek; i++)
        printf("    ");

    for (int day = 1; day <= daysInMonth[month]; day++) {
        printf("%4d", day);
        if (++dayOfWeek > 6) {
            printf("\n");
            dayOfWeek = 0;
        }
    }

    printf("\n\n");
}

int main() {
    int year, month;

    printf("Enter year: ");
    scanf("%d", &year);

    printf("Enter month (1-12): ");
    scanf("%d", &month);

    if (year < 1 || month < 1 || month > 12) {
        printf("Invalid input. Please enter a valid year and month.\n");
        return 1;
    }

    displayCalendar(year, month);

    return 0;
}
