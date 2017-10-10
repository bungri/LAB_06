/* T_ExpandableArray.hpp */

#ifndef T_EXPANDABLE_ARRAY_HPP
#define T_EXPANDABLE_ARRAY_HPP

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#define MAX_STRING_LENGTH 10

template<typename T>

class T_ExpandableArray
{
	//friend ostream& operator<<(ostream&, T_ExpandableArray<T>&);
public:
	T_ExpandableArray(string name = ""); // default constructor
	~T_ExpandableArray(); // default destructor
	int size() const { return num; } // return number of elements
	int capacity() const { return capa; } // return the capacity
	bool empty() const { return num == 0; }
	void reserve(int N); // reserve at least N slots
	void insert(int i, T& element); // insert element e at index i
	void erase(int i); // delete/erase element at index i
	const T& at(int i); // read element at index i
	int search(T& element); //search same element in array
	void set(int i, T& element); // replace element e at index i
	void copy(const T_ExpandableArray<T>& ea); // copy from another expandable_array
	void print(ostream& fout);
	void quickSort(); // sort array
	void suffle();
	T& operator[](int sub);
	T_ExpandableArray<T>& T_ExpandableArray<T>::operator=(T_ExpandableArray& rightSide);
	const ExpandableArray operator=(const ExpandableArray rightSide);
	double& operator[](int i);
private:
	bool isValidIndex(int index) const;
	string name; // name of expandable array
	int capa;
	int num;
	T *t_array; // pointer of double array
};

#endif