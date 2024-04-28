// CS 210
// John Bryson 
// Project One

#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <sstream>

class Clock {
private:
    int hours;
    int minutes;
    int seconds;

    // Function to format numbers as two digits
    std::string formatTwoDigits(int number) {
        std::ostringstream oss;
        oss << std::setw(2) << std::setfill('0') << number;
        return oss.str();
    }

public:
    Clock() {
        time_t currentTime;
        struct tm* localTime;
        time(&currentTime);
        localTime = localtime(&currentTime);
        hours = localTime->tm_hour;
        minutes = localTime->tm_min;
        seconds = localTime->tm_sec;
    }

    // Function to output time in 24-hour format
    std::string getTime24Hour() {
        return formatTwoDigits(hours) + ":" + formatTwoDigits(minutes) +
            ":" + formatTwoDigits(seconds);
    }

    // Function to output time in 12-hour format
    std::string getTime12Hour() {
        std::string period = (hours < 12) ? "AM" : "PM";
        int displayHours = (hours > 12) ? hours - 12 : hours;
        return formatTwoDigits(displayHours) + ":" + formatTwoDigits(minutes) +
            " " + period;
    }

    // Function to add a second to the clock's time
    void addSecond() {
        seconds++;
        if (seconds == 60) {
            seconds = 0;
            addMinute();
        }
    }

    // Function to add a minute to the clock's time
    void addMinute() {
        minutes++;
        if (minutes == 60) {
            minutes = 0;
            addHour();
        }
    }

    // Function to add an hour to the clock's time
    void addHour() {
        hours++;
        if (hours == 24) {
            hours = 0; // Reset it back to midnight
        }
    }
};

// Function to print out the menu
void printMenu() {
    std::cout << "MENU:" << std::endl;
    std::cout << "1. Add one second" << std::endl;
    std::cout << "2. Add one minute" << std::endl;
    std::cout << "3. Add one hour" << std::endl;
    std::cout << "4. Display time in both 12-hour and 24-hour formats" <<
        std::endl;
    std::cout << "5. Quit" << std::endl;
}

// Function to process user input
void processInput(Clock& clock) {
    int choice;
    do {
        printMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                clock.addSecond();
                break;
            case 2:
                clock.addMinute();
                break;
            case 3:
                clock.addHour();
                break;
            case 4:
                std::cout << "Time (24-Hour): " << clock.getTime24Hour() <<
                    std::endl;
                std::cout << "Time (12-Hour): " << clock.getTime12Hour() <<
                    std::endl;
                break;
            case 5:
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);
}

int main() {
    Clock clock;
    // Process user input for the clock
    processInput(clock);
    return 0;
}
