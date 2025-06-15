#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

std::string getNextDay(int year, int month, int day) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool isLeapyear = (year % 4 == 0 && year % 100 !=0) || (year % 400 == 0);
    if (isLeapyear) {
        daysInMonth[1] = 29;
    }

    day++;
    if (day > daysInMonth[month - 1]) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }

    std::ostringstream oss;
    oss << year << "-"<< month << "-"<< day;
    
    return oss.str();
}

std::string getPrevDay(int year, int month, int day) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool isLeapyear = (year % 4 == 0 && year % 100 !=0) || (year % 400 == 0);
    if (isLeapyear) {
        daysInMonth[1] = 29;
    }

    day--;
    if (day < 1) {
        day = daysInMonth[month - 2] + (month - 1 == 0 ? 31 : 0);
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
    }

    std::ostringstream oss;
    oss << year << "-"<< month << "-"<< day;
    
    return oss.str();
}

int main() {
    int year, month, day;
    std::cin >> year >> month >> day;

    std::string currentDate = std::to_string(year) + "-" +
                              std::to_string(month) + "-" +
                              std::to_string(day);
    
    std::string nextDay = getNextDay(year, month, day);
    std::string prevDay = getPrevDay(year, month, day);

    std::cout << "Date:" << currentDate << ",Next Day:" << nextDay << ",Prev Day:" << prevDay << std::endl;

    return 0;
}