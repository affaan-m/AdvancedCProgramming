#include "date.h"

int numberOfDays(Date d) {
    int days;
    bool isLeapYear(Date d);
    const int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(d) && d.month == February)
        days = 29;
    else
        days = daysPerMonth[d.month - 1];
    return days;
}

bool isLeapYear(Date d) {
    bool leapYearFlag;
    if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)
        leapYearFlag = true;
    else
        leapYearFlag = false;
    return leapYearFlag;
}

Date dateUpdate(Date today) {
    Date tommorow;
    if (today.day != numberOfDays(today)) // not end of month
        setDate (tommorow, today.month, today.day + 1, today.year); // next day
    else if (today.month == December) // end of year
        setDate (tommorow, January, 1, today.year + 1); // next year
    else // end of month
        setDate (tommorow, today.month + 1, 1, today.year); // next month
    return tommorow;
}

