/* Date.hpp */

#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

class Date
{
	friend istream &operator>>(istream &, Date &);
	friend ostream &operator<<(ostream &, Date &);
public:
	Date(); // default constructor
	Date(int y, int m, int d); // constructor
	void setDate(int newYear, int newMonth, int newDay);
	int getYear() const { return year; }
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
	int year;
	int month;
	int day;
};

#endif