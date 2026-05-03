#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int validateInput(int day, int month, int year);
int calculateYearCode(int year);
int calculateCenturyCode(int year);
int calculatemonthCode(int month);
int calculateWeekday(int day, int month, int year);
int dayOfWeek(int day, int month, int year);
void runQuiz();
int main() {
    cout << "Select mode:\n";
    cout << "  1. Enter a date\n";
    cout << "  2. Quiz - guess the day of the week\n";
    cout << "Choice: ";
    int choice = 0;
    cin >> choice;
    cin.ignore();

    if (choice == 2) {
        runQuiz();
        return 0;
    }

    int day = 0;
    int month = 0;
    int year = 0;
    char dash1 = '\0';
    char dash2 = '\0';

    cout << "Enter date (DD-MM-YYYY): ";
    if (!(cin >> day >> dash1 >> month >> dash2 >> year) || dash1 != '-' || dash2 != '-') {
        cerr << "Invalid format. Use DD-MM-YYYY.\n";
        return 1;
    }

    validateInput(day, month, year);   
    calculateYearCode(year);
    calculateCenturyCode(year);
    calculatemonthCode(month);
    calculateWeekday(day, month, year);
    cout << "Input received: " << day << "-" << month << "-" << year << "\n";
    cout << "\n\n";
    dayOfWeek(day, month, year);
    return 0;
}

int validateInput(int day, int month, int year) {
    if (month < 1 || month > 12) {
        cerr << "Invalid month. Must be between 1 and 12.\n";
        exit(1);
    }

    int maxDay = 31;
    if (month == 2) {
        maxDay = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        maxDay = 30;
    }

    if (day < 1 || day > maxDay) {
        cerr << "Invalid day for the given month. Must be between 1 and " << maxDay << ".\n";
        exit(1);
    }

    return 0; // Valid input
}
int calculateYearCode(int year) {
    int lastTwoDigits = year % 100;
    int yearCode = (lastTwoDigits + (lastTwoDigits / 4)) % 7;
    return yearCode;
}
int calculateCenturyCode(int year) {
    int century = year / 100;
    int centuryCode = (3 - (century % 4)) * 2; // Example calculation
    return centuryCode;
}
int calculatemonthCode(int month) {
    int monthCode = 0;
    switch (month) {
        case 1: monthCode = 0; break;
        case 2: monthCode = 3; break;
        case 3: monthCode = 3; break;
        case 4: monthCode = 6; break;
        case 5: monthCode = 1; break;
        case 6: monthCode = 4; break;
        case 7: monthCode = 6; break;
        case 8: monthCode = 2; break;
        case 9: monthCode = 5; break;
        case 10: monthCode = 0; break;
        case 11: monthCode = 3; break;
        case 12: monthCode = 5; break;
    }
    return monthCode;
}
int calculateWeekday(int day, int month, int year) {
    int yearCode = calculateYearCode(year);
    int centuryCode = calculateCenturyCode(year);
    int monthCode = calculatemonthCode(month);
    int weekday = (yearCode + centuryCode + monthCode + day) % 7;
    return weekday;
}
int dayOfWeek(int day, int month, int year) {
    int weekday = calculateWeekday(day, month, year);
    const char* daysOfWeek[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    cout << "The day of the week for " << day << "-" << month << "-" << year << " is: " << daysOfWeek[weekday] << "\n";
    return weekday;
}

void runQuiz() {
    srand(static_cast<unsigned int>(time(nullptr)));

    // Generate a random valid date (year 1753-2099)
    int year  = 1753 + rand() % 347;
    int month = 1 + rand() % 12;
    int maxDay = 31;
    if (month == 2) {
        maxDay = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        maxDay = 30;
    }
    int day = 1 + rand() % maxDay;

    const char* dayNames[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

    cout << "\nQuiz date: " << day << "-" << month << "-" << year << "\n";
    cout << "What day of the week is this? (or press Enter to skip): ";

    string input;
    getline(cin, input);

    if (input.empty()) {
        cout << "Skipped. ";
    } else {
        int correct = calculateWeekday(day, month, year);
        // Case-insensitive compare
        string lower = input;
        for (char& c : lower) c = static_cast<char>(tolower(c));
        string correctLower = dayNames[correct];
        for (char& c : correctLower) c = static_cast<char>(tolower(c));

        if (lower == correctLower) {
            cout << "Correct! ";
        } else {
            cout << "Wrong. ";
        }
    }

    cout << "The answer is: " << dayNames[calculateWeekday(day, month, year)] << "\n";
}