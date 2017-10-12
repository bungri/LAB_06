/* T_ExpandableArray.hpp */

#ifndef T_EXPANDABLE_ARRAY_HPP
#define T_EXPANDABLE_ARRAY_HPP

#include <iostream>
#include <iomanip>
#include <string>

#include "Date.hpp"

using namespace std;

#define MAX_STRING_LENGTH 10

template<typename T>

class T_ExpandableArray
{
	//friend ostream& operator<<(ostream&, T_ExpandableArray<T>&);
public:
	T_ExpandableArray(string name = ""); // default constructor
	T_ExpandableArray(string name, int num, int capa, T* t_arr); // constructor for quicksorting
	virtual ~T_ExpandableArray(); // default destructor
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
	void swap(T *dst, T *src);
	T& operator[](int sub);
	T_ExpandableArray<T>& T_ExpandableArray<T>::operator=(T_ExpandableArray& rightSide);
	//const T_ExpandableArray operator=(const ExpandableArray rightSide);
	//double& operator[](int i);
private:
	bool isValidIndex(int index) const;
	string name; // name of expandable array
	int capa;
	int num;
	T *t_array; // pointer of double array
};

//Constructor & Destructor ------------------------------------------------------------------------------------------------------------------------------
template<typename T>
T_ExpandableArray<T>::T_ExpandableArray(string name)
{
	this->name = name;
	this->capa = 1;
	this->t_array = new T[capa];
	this->num = 0;
}

template<typename T>
inline T_ExpandableArray<T>::T_ExpandableArray(string name, int num, int capa, T * t_arr)
{
	this->name = name;
	this->num = num;
	this->capa = capa;
	this->t_array = t_arr;
}

template<typename T>
T_ExpandableArray<T>::~T_ExpandableArray()
{
	if (this->name != string("SortArr"))
		delete[] this->t_array;
}

//Capacity expand function ------------------------------------------------------------------------------------------------------------------------------------
template<typename T>
void T_ExpandableArray<T>::reserve(int N)
{
	T *new_t_array = new T[N];
	for (int i = 0; i < this->capa; i++)
	{
		new_t_array[i] = this->t_array[i];
	}
	delete[] this->t_array;
	this->t_array = new_t_array;
	this->capa = N;
}

//Expandable array i/o function -------------------------------------------------------------------------------------------------------------------------------
template<typename T>
void T_ExpandableArray<T>::insert(int i, T & element)
{
	if (num == this->capa)
	{
		if (this->capa < 1024)
			reserve(this->capa * 2);
		else
			reserve(this->capa + 1024);
	}

	if (!this->isValidIndex(i))
	{
		cout << "Invalid index (" << i << "). halt program." << endl;
		exit(1);
	}
	
	if (i >= this->num)
		this->t_array[i] = element;
	else
	{
		for (int index = num; index > i; index--)
			this->t_array[index] = this->t_array[index - 1];
		this->t_array[i] = element;
	}
	this->num++;
}

template<typename T>
void T_ExpandableArray<T>::erase(int i)
{
	if (!this->isValidIndex(i))
	{
		cout << "Invalid index (" << i << "). halt program." << endl;
		exit(1);
	}
	if (i >= n)
		dA[i] = 0;
	else
	{
		for (int index = i; index < n - 1; index++)
			this->t_array[index] = this->t_array[index + 1];
	}
	this->num--;
}

template<typename T>
void T_ExpandableArray<T>::set(int i, T & element)
{
	if (!this->isValidIndex(i))
	{
		cout << "Invalid index (" << i << "). halt program." << endl;
		exit(1);
	}
	this->t_array[i] = element;
}

//Indexing function --------------------------------------------------------------------------------------------------------------------------------------------
template<typename T>
const T & T_ExpandableArray<T>::at(int i)
{
	if (this->isValidIndex(i))
	{
		return this->t_array[i];
	}
}

template<typename T>
int T_ExpandableArray<T>::search(T & element)
{
	int low = 0, high = num - 1, mid;
	while (low <= high)	//Ž���� ���ڰ� ���� �ִٸ� Ž�� ����
	{
		mid = (low + high) / 2;
		if (element == arr[mid])
			return mid;	//Ž�� ����, ����� ��ȯ
		else if (arr[mid] > element)	//mid������ Ž���� ���� �� ũ�ٸ� mid - 1 ������ high ����
			high = mid - 1;
		else //mid ������ Ž���� ���� �� �۴ٸ� mid + 1 ������ low ����
			low = mid + 1;
	}
	return 0;	//����
}

//Copy array ----------------------------------------------------------------------------------------------------------------------------------------------------

template<typename T>
void T_ExpandableArray<T>::copy(const T_ExpandableArray<T>& ea)
{
	while (this->capa < ea.capa)
		this->reserve(ea.capa);
	this->num = ea.num;
	for (int i = 0; i < ea.num; i++)
		this->t_array[i] = ea.t_array[i];;
}

//Print Array----------------------------------------------------------------------------------------------------------------------------------------------------

template<typename T>
void T_ExpandableArray<T>::print(ostream & fout)
{
	string T_type;
	int count = 0;
	T_type = typeid(T).name();
	fout << "T-genBigRand for " << T_type << " array of size " << num << endl;
	if (num <= 0)
	{
		fout << "T_ExpandableArray is empty" << endl;
	}
	else if ((T_type == string("int")) || (T_type == string("double")))
	{
		for (int i = 0; i < this->num; i++)
		{
			fout << setw(6) << t_array[i] << " ";
			if ((i + 1) % 10 == 0)
				fout << endl;
		}
	}
	else if (T_type == string("class Date"))
	{
		for (int i = 0; i < this->num; i++)
		{
			fout << t_array[i] << " ";
			if ((i + 1) % 5 == 0)
				fout << endl;
		}
	}
	else
	{
		fout << "Error :: T - genBigRand for " << T_type << " array is not implemented !!" << endl;
	}
}

//Sort & Shuffle Algorithm ---------------------------------------------------------------------------------------------------------------------------------------
template<typename T>
void T_ExpandableArray<T>::quickSort()
{
	//sorts the given arr of students in increasing order of ID.Using the printStudents()
	//print out the arr of sorted arr of students.
	if (this->num <= 1)	//���̻� sorting �� �׸��� ����!
	{
		return;
	}
		int right = this->num - 1;
	int storeIndex = 0;
	T pivotValue = this->t_array[right / 2];
	swap(this->t_array + right / 2, this->t_array + right);	//������� pivotIndex�� ��� right ���� ���� �� pivotValue ����

	if (this->num > 1)
	{
		for (int left = 0; left < this->num; left++)
		{
			if (this->t_array[left] < pivotValue) {
				if (left == storeIndex)	//storeIndex�� left�� ���ٸ� swap�� �ϴ� ���� �޸� ����!
				{
					storeIndex++;
					continue;
				}
				swap(this->t_array + left, this->t_array + storeIndex);	//left�� pivotVale���� �۴ٸ� storeIndex�� ���� �� storeIndex 1 ����
				storeIndex++;
			}
		}
		swap(this->t_array + storeIndex, this->t_array + right);	//������� ����
	}
	T_ExpandableArray<T> LeftArr("SortArr", storeIndex, this->capa, this->t_array);
	LeftArr.quickSort();	//recursive call - ���� / cut �� �迭�� ������ �ִ밪�� cut �ؼ� �Լ� ȣ��
	T_ExpandableArray<T> RightArr("SortArr", this->num - (storeIndex + 1), this->capa, this->t_array + (storeIndex + 1));
	RightArr.quickSort();	//sorting�� �Ϸ�� ���� �迭�� �߶󳻰� ������ �迭�� �μ��� ����
}

template<typename T>
void T_ExpandableArray<T>::suffle()
{
	srand(time(NULL));
	int freq = rand() % 100 + this->num;
	cout << "Shuffle array " << this->name << " " << freq << " times \n";
	for (int i = 0; i < freq; i++)
		swap(this->t_array + rand() % this->num, this->t_array + rand() % this->num);
}

//Index validation function --------------------------------------------------------------------------------------------------------------------------------------

template<typename T>
bool T_ExpandableArray<T>::isValidIndex(int index) const
{
	if ((index >= 0 )&&(index < this->capa))
		return true;
	else
		return false;
}

//Operator overloading -------------------------------------------------------------------------------------------------------------------------------------------

template<typename T>
T & T_ExpandableArray<T>::operator[](int sub)
{
	if (this->isValidIndex(sub))
		return this->t_array[sub];
	cout << "Invalid index (" << sub << "). halt program." << endl;
	exit(1);
}

template<typename T>
T_ExpandableArray<T>& T_ExpandableArray<T>::operator=(T_ExpandableArray & rightSide)
{
	if (this->capa != rightSide.capa)
		this->reserve(rightSide.capa);
	this->num = rightSide.num;
	for (int i = 0; i < rightSide.num; i++)
		this->t_array[i] = rightSide.t_array[i];
	return (*this);
}

/*template<typename T>
const ExpandableArray T_ExpandableArray<T>::operator=(const ExpandableArray rightSide)
{
	return ExpandableArray();
}
*/

//Swap function ------------------------------------------------------------------------------------------------------------------------------------------------------
template<typename T>
inline void T_ExpandableArray<T>::swap(T *dst, T *src) {
	T temp = *src;
	*src = *dst;
	*dst = temp;
}
#endif