#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    int day;
    int month;
    int year;
    int water_intake; // in ml
    int exercise_minutes;
    int sleep_hours;
    int calories;
} HealthEntry;

void addEntry(HealthEntry entries[], int *entryCount) {
    if (*entryCount >= MAX_ENTRIES) {
        printf("Maximum entries reached.\n");
        return;
    }

    HealthEntry entry;

    printf("Enter date (day month year): ");
    scanf("%d %d %d", &entry.day, &entry.month, &entry.year);
    printf("Enter water intake (in ml): ");
    scanf("%d", &entry.water_intake);
    printf("Enter exercise minutes: ");
    scanf("%d", &entry.exercise_minutes);
    printf("Enter sleep hours: ");
    scanf("%d", &entry.sleep_hours);
    printf("Enter calories consumed: ");
    scanf("%d", &entry.calories);

    entries[*entryCount] = entry;
    (*entryCount)++;
    printf("Entry added successfully.\n");
}

void viewEntries(HealthEntry entries[], int entryCount) {
    if (entryCount == 0) {
        printf("No entries to display.\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        HealthEntry entry = entries[i];
        printf("Date: %02d/%02d/%04d\n", entry.day, entry.month, entry.year);
        printf("Water intake: %d ml\n", entry.water_intake);
        printf("Exercise: %d minutes\n", entry.exercise_minutes);
        printf("Sleep: %d hours\n", entry.sleep_hours);
        printf("Calories: %d\n", entry.calories);
        printf("-----------------------------\n");
    }
}

void analyzeEntries(HealthEntry entries[], int entryCount) {
    if (entryCount == 0) {
        printf("No entries to analyze.\n");
        return;
    }

    int totalWater = 0, totalExercise = 0, totalSleep = 0, totalCalories = 0;

    for (int i = 0; i < entryCount; i++) {
        totalWater += entries[i].water_intake;
        totalExercise += entries[i].exercise_minutes;
        totalSleep += entries[i].sleep_hours;
        totalCalories += entries[i].calories;
    }

    printf("Average daily water intake: %d ml\n", totalWater / entryCount);
    printf("Average daily exercise: %d minutes\n", totalExercise / entryCount);
    printf("Average daily sleep: %d hours\n", totalSleep / entryCount);
    printf("Average daily calories: %d\n", totalCalories / entryCount);
}

int main() {
    HealthEntry entries[MAX_ENTRIES];
    int entryCount = 0;
    int choice;

    while (1) {
        printf("Health Tracking System\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Analyze Entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(entries, &entryCount);
                break;
            case 2:
                viewEntries(entries, entryCount);
                break;
            case 3:
                analyzeEntries(entries, entryCount);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
