/* main.cpp */

#include <iostream>
#include <string.h>

#include "T_ExpandableArray.hpp"
#include "Date.hpp"

#define NUM_EA 30
#define NUM_EB 30
#define NUM_EA_INT 30
#define NUM_EA_DATE 10

using namespace std;

//function prototypes
bool isLeapYear(int y);
Date genRandDate();

//main
void main()
{
	T_ExpandableArray<double> eaDBL_A("eaDBL_A"), eaDBL_B("eaDBL_B"), eaDBL_C("eaDBL_C");
	T_ExpandableArray<int> eaInt("eaInt");
	T_ExpandableArray<Date> eaDate("eaDate");

	//Quicksort and shuffle expandable double array
	double d = 0.0;
	for (int i = 0; i < NUM_EA; i++)
	{
		eaDBL_A.insert(0, d);
		d += 1.1;
	}
	cout << "eaDBL_A : "; eaDBL_A.print(cout); cout << endl;
	eaDBL_A.quickSort();
	cout << "eaDBL_A (after sorting) :"; eaDBL_A.print(cout); cout << endl;
	eaDBL_A.suffle();
	cout << "eaDBL_A (after suffling) : "; eaDBL_A.print(cout); cout << endl;

	d = 10.0;
	for (int i = 0; i < NUM_EB; i++)
	{
		eaDBL_B.insert(0, d);
		d += 2.2;
	}

	//Chain assignmentation
	cout << "eaDBL_B : "; eaDBL_B.print(cout); cout << endl;
	eaDBL_C = eaDBL_A = eaDBL_B;
	cout << "eaDBL_A (after chained assignment) : "; eaDBL_A.print(cout); cout << endl;
	cout << "eaDBL_C (after chained assignment) : "; eaDBL_C.print(cout); cout << endl;

	//Doubling the elements
	for (int i = 0; i < eaDBL_C.size(); i++)
	{
		eaDBL_C[i] = eaDBL_C[i] * 2;
	}
	cout << "eaDBL_C (after doubling the elements) : "; eaDBL_C.print(cout); cout << endl;

	//Quicksort expandable integer array
	int k = 1;
	for (int i = 0; i < NUM_EA_INT; i++)
	{
		eaInt.insert(0, k);
		k += 1;
	}
	cout << "eaInt (before quick_sorting) : "; eaInt.print(cout); cout << endl;
	eaInt.quickSort();
	cout << "eaInt (after quick_sorting) : "; eaInt.print(cout); cout << endl;

	//Quicksort expandable date array
	Date dt;
	for (int i = 0; i < NUM_EA_INT; i++)
	{
		dt = genRandDate();
		eaDate.insert(i, dt);
	}
	cout << "eaDate (before quick_sorting) : "; eaDate.print(cout); cout << endl;
	eaDate.quickSort();
	cout << "eaDate (after quick_sorting) : "; eaDate.print(cout); cout << endl;
	eaDBL_A.~T_ExpandableArray();
	eaDBL_B.~T_ExpandableArray();
	eaDBL_C.~T_ExpandableArray();
	eaInt.~T_ExpandableArray();
	eaDate.~T_ExpandableArray();
}//end-main

//function bodies
bool isLeapYear(int y)
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

Date genRandDate()
{
	int y, m, d;
	int days_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	Date date;
	y = rand() % 3000 + 1000;
	m = rand() % 12 + 1;
	if (isLeapYear(y) && m == 2)
		days_month[2] = 29;
	d = rand() % days_month[m] + 1;
	date = Date(y, m, d);
	return date;
}