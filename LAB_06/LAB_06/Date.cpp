/* Date.cpp */

#include "Date.hpp"

//friend functions ------------------------------------------------------------------------------------------------------------------------------------------

istream & operator>>(istream &, Date &)
{
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
}

ostream & operator<<(ostream &, Date &)
{
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
}

//Constructors -----------------------------------------------------------------------------------------------------------------------------------------------

Date::Date()
{

}

Date::Date(int y, int m, int d)
{

}

//Setter -----------------------------------------------------------------------------------------------------------------------------------------------------

void Date::setDate(int newYear, int newMonth, int newDay)
{

}

//Specific getter --------------------------------------------------------------------------------------------------------------------------------------------

int Date::getYearDay() const
{
	return 0;
}

int Date::getWeekDay() const
{
	return 0;
}

int Date::getElapsedDays() const
{
	return 0;
}

//Operators --------------------------------------------------------------------------------------------------------------------------------------------------

const Date Date::operator=(const Date rightSide)
{
	return Date();
}

bool Date::operator>(Date rightSide)
{
	return false;
}

bool Date::operator<(Date rightSide)
{
	return false;
}

bool Date::operator==(Date rightSide)
{
	return false;
}

//LeapYear judgement functions --------------------------------------------------------------------------------------------------------------------------------

bool Date::isLeapYear(int y) const
{
	return false;
}

bool Date::isLeapYear() const
{
	return false;
}

//Date validation functions ------------------------------------------------------------------------------------------------------------------------------------

bool Date::isValidDate(int y, int m, int d) const
{
	return false;
}
