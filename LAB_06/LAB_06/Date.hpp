/* Date.hpp */

#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string.h>

static int monthlyDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
static char weekDayList[7][10] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

using namespace std;

class Date
{
	friend istream &operator>>(istream &, Date &);
	friend ostream &operator<<(ostream &, const Date &);
public:
	Date(); // default constructor
	Date(int y, int m, int d); // constructor
	void setDate(int newYear, int newMonth, int newDay);
	int getYear() const { return year; }
	int getMonth() const { return month; }
	int getDay() const { return day; }
	int getYearDay() const;
	int getWeekDay() const;
	int getElapsedDays() const; // get elapsed days from AD 1. 1. 1.
	const Date operator=(const Date rightSide);
	bool operator>(Date rightSide);
	bool operator<(Date rightSide);
	bool operator==(Date rightSide);
	bool isLeapYear(int y) const; // check whether the given year y is leap year
private:
	bool isLeapYear() const; // check whether the year is leap year
	bool isValidDate(int y, int m, int d) const;
	void returnError() const;
	int year;
	int month;
	int day;
};

#endif