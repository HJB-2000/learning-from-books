#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get the day of the week for a given date
int getDayOfWeek(int year, int month, int day) {
    struct tm timeinfo = {
        .tm_year = year - 1900,
        .tm_mon = month - 1,
        .tm_mday = day
    };
    mktime(&timeinfo);
    return timeinfo.tm_wday;
}

// Function to print a monthly calendar
void printCalendar(int year, int month) {
    // Define the names of the months
    const char* months[] = {"January", "February", "March", "April", "May", "June", "July",
                            "August", "September", "October", "November", "December"};

    // Define the names of the days of the week
    const char* daysOfWeek[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    
    // Determine the number of days in the month
    int daysInMonth;
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            daysInMonth = 29; // February has 29 days in a leap year
        } else {
            daysInMonth = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    } else {
        daysInMonth = 31;
    }

    // Print the header
    printf("       %s %d\n", months[month - 1], year);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    // Determine the day of the week for the first day of the month
    int startingDay = getDayOfWeek(year, month, 1);

    // Print leading spaces for the first row
    for (int i = 0; i < startingDay; i++) {
        printf("    ");
    }

    // Print the days of the month
    for (int day = 1; day <= daysInMonth; day++) {
        printf("%3d ", day);
        
        // If the day is a Saturday, start a new line
        if ((startingDay + day) % 7 == 0) {
            printf("\n");
        }
    }

    printf("\n");
}

int main() {
    int year, month;
    
    // Input the year and month for the calendar
    printf("Enter year (e.g., 2023): ");
    scanf("%d", &year);
    
    printf("Enter month (1-12): ");
    scanf("%d", &month);
    
    // Check if the input is valid
    if (month < 1 || month > 12) {
        printf("Invalid month input.\n");
        return 1;
    }
    
    // Call the function to print the calendar
    printCalendar(year, month);

    return 0;
}

