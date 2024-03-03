#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_DAYS_IN_WEEK 7
#define MAX_NAME_LENGTH 50
#define MAX_ACTIVITY_LENGTH 100

typedef struct {
    char acDayName[MAX_NAME_LENGTH];
    int iDate;
    char acActivity[MAX_ACTIVITY_LENGTH];
} DAYTYPE;

void fnDispCal(DAYTYPE *);
void fnReadCal(DAYTYPE *);

int main() {
    DAYTYPE weeklyCalendar[NUM_DAYS_IN_WEEK];

    // Read data from the keyboard
    fnReadCal(weeklyCalendar);
    // Display the week activity details
    fnDispCal(weeklyCalendar);

    return 0;
}

void fnReadCal(DAYTYPE *calendar) {
    for (int i = 0; i < NUM_DAYS_IN_WEEK; i++) {
        char cChoice;
        printf("Do you want to enter details for day %d [Y/N]: ", i + 1);
        scanf(" %c", &cChoice);
        //getchar(); // Consume newline
        if (tolower(cChoice) == 'n')
            continue;
        printf("Day Name: ");
        fgets(calendar[i].acDayName, sizeof(calendar[i].acDayName), stdin);
        calendar[i].acDayName[strcspn(calendar[i].acDayName, "\n")] = '\0'; // Remove newline character

        printf("Date: ");
        scanf("%d", &calendar[i].iDate);

        printf("Activity: ");
       // getchar(); // Consume newline
        fgets(calendar[i].acActivity, sizeof(calendar[i].acActivity), stdin);
        calendar[i].acActivity[strcspn(calendar[i].acActivity, "\n")] = '\0'; // Remove newline character

        printf("\n");
    }
}

void fnDispCal(DAYTYPE *calendar) {
    printf("\nWeek's Activity Details:\n");
    for (int i = 0; i < NUM_DAYS_IN_WEEK; i++) {
        printf("Day %d:\n", i + 1);
        if (calendar[i].iDate == 0) {
            printf("No Activity\n\n");
            continue;
        }
        printf(" Day Name: %s\n", calendar[i].acDayName);
        printf(" Date: %d\n", calendar[i].iDate);

        printf(" Activity: %s\n\n", calendar[i].acActivity);
    }
}
