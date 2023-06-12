#include <stdio.h>

// Function to check if a year is a leap year or not
int isLeapYear(int year) {
    if(year % 400 == 0)
        return 1;
    else if(year % 100 == 0)
        return 0;
    else if(year % 4 == 0)
        return 1;
    else
        return 0;
}

// Function to get the number of days in a month
int getMonthDays(int month, int year) {
    if(month == 2) {
        if(isLeapYear(year))
            return 29;
        else
            return 28;
    }
    else if(month == 4  month == 6  month == 9 || month == 11)
        return 30;
    else
        return 31;
}

// Function to calculate the day of the week of a given date
int calculateDayOfWeek(int day, int month, int year) {
    int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    if(month < 3)
        year -= 1;
    return ( year + year / 4 - year / 100 + year / 400 + t[month - 1] + day ) % 7;
}

// Function to print the calendar of a month
void printCalendar(int month, int year) {
    printf("\n   Sunday Monday Tuesday Wednesday Thursday Friday Saturday\n");
    int days = getMonthDays(month, year);
    int currentDayOfWeek = calculateDayOfWeek(1, month, year);

    for(int i = 0; i < currentDayOfWeek; i++)
        printf("        ");

    for(int day = 1; day <= days; day++) {
        printf("%8d", day);
        if(++currentDayOfWeek > 6) {
            currentDayOfWeek = 0;
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    int month, year;
    printf("Enter the month and year: ");
    scanf("%d %d", &month, &year);
    printCalendar(month, year);
    return 0;
}
