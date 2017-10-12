/* Date.cpp */

#include "Date.hpp"

//friend functions ------------------------------------------------------------------------------------------------------------------------------------------

istream & operator>>(istream &input, Date &date)
{
	input >> date.year;
	input >> date.month;
	input >> date.day;
	return input;
}

ostream & operator<<(ostream &output, const Date &date)
{
	output << "Date [" << setw(4) << date.getYear() << "." << setw(2) << date.getMonth() << "." << setw(2) << date.getDay() << ".]";
	return output;

}

//Constructors -----------------------------------------------------------------------------------------------------------------------------------------------

Date::Date()
{
	this->year = 1;
	this->month = 1;
	this->day = 1;
}

Date::Date(int y, int m, int d)
{
	setDate(y, m, d);
}


//Setter -----------------------------------------------------------------------------------------------------------------------------------------------------

void Date::setDate(int newYear, int newMonth, int newDay)
{
	if (newYear >= 1)
		this->year = newYear;
	else
		returnError();

	if ((newMonth >= 1) && (newMonth <= 12))
		this->month = newMonth;
	else
		returnError();

	int temp;
	if ((isLeapYear(this->year)) && (this->month == 2))
		temp = 29;
	else
		temp = monthlyDays[this->month - 1];

	if ((newDay >= 1) && (newDay <= temp))
		this->day = newDay;
	else
		returnError();
}

//Specific getter --------------------------------------------------------------------------------------------------------------------------------------------

int Date::getYearDay() const
{
	int yearDay = 0;
	for (int i = 1; i < this->month; i++)
	{
		if ((isLeapYear(this->year)) && (i == 2))
			yearDay += 29;
		else
			yearDay += monthlyDays[i - 1];
	}
	yearDay += this->day;
	return yearDay;
}

int Date::getWeekDay() const
{
	int weekDay = (getElapsedDays() - 1) % 7;
	return weekDay;
}

int Date::getElapsedDays() const
{
	int elapsedDays = 0;
	for (int i = 1; i < this->year; i++)
	{
		if (isLeapYear(i))
			elapsedDays += 366;
		else
			elapsedDays += 365;
	}
	elapsedDays += this->getYearDay();
	return elapsedDays;
}

//Operators --------------------------------------------------------------------------------------------------------------------------------------------------

const Date Date::operator=(const Date rightSide)
{
	int y, m, d;
	string n;
	y = rightSide.year;
	m = rightSide.month;
	d = rightSide.day;
	if (isValidDate(y, m, d))
	{
		this->year = y;
		this->month = m;
		this->day = d;
		return *this;
	}
	else {
		return Date(0, 0, 0);
	}
}

bool Date::operator>(Date rightSide)
{
	return this->getElapsedDays() > rightSide.getElapsedDays();
}

bool Date::operator<(Date rightSide)
{
	return this->getElapsedDays() < rightSide.getElapsedDays();
}

bool Date::operator==(Date rightSide)
{
	return this->getElapsedDays() == rightSide.getElapsedDays();
}

//LeapYear judgement functions --------------------------------------------------------------------------------------------------------------------------------

bool Date::isLeapYear(int y) const
{
	if (y % 4 == 0)
	{
		if (y % 100 == 0)
		{
			if (y % 400 == 0)
				return true;
			else
				return false;
		}
		return true;
	}
	return false;
}

bool Date::isLeapYear() const
{
	if (this->year % 4 == 0)
	{
		if (this->year % 100 == 0)
		{
			if (this->year % 400 == 0)
				return true;
			else
				return false;
		}
		return true;
	}
	return false;
}

//Date validation functions ------------------------------------------------------------------------------------------------------------------------------------

bool Date::isValidDate(int y, int m, int d) const
{
	if (y < 1)
		return false;

	if ((m < 1) && (m > 12))
		return false;

	bool tempflag = false;

	if ((isLeapYear(y)) && (m == 2) && (d < 29))
		tempflag = true;

	if ((d < 1) && (d > monthlyDays[m - 1]))
	{
		if (tempflag)
			return true;
		else
			return false;
	}
	return true;
}

//Error return functions

void Date::returnError() const
{
	cout << "Invaild operation! halt program." << endl;
	exit(1);
}