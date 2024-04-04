#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

// Header File for Working with Dates
#include <stdbool.h>

// Enumerated Types

enum kMonth {January = 1, February, March, April, May, June, July, August, September, October, November, December};

enum kDay {Sunday = 1, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};

struct date {
    enum kMonth month;
    enum kDay day;
    int year;
};

// Date Type
typedef struct date Date;

// Functions that Work with dates
Date dateUpdate(Date today);
int numberOfDays(Date d);
bool isLeapYear(Date d);

// Macro to set a date in a structure

#define setDate(s, mm, dd, yy) s = (Date) {mm, dd, yy}

// External variable reference
extern Date todaysDate;

#endif // MAIN_H_INCLUDED
