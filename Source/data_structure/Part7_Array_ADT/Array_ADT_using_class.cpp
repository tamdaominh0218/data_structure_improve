#include <iostream>
#include <algorithm>
using namespace std;

class Array {
private:
	int* A;
	int size;
	int length;
public:
	Array();
	Array(int sz);

	void display();
	void add(int val);
	void insert(int ele, int val);
	void remove(int ele);
	void insert_in_sorted(int val);
	bool is_sorted();
	void merging_arr(const Array& a2);
	void merging_arr2(const Array& a2);
	void sort_arr();
	void intersection(const Array& a2);
	void difference(const Array& a2);
	~Array();
};

Array::Array() {
	size = 10;
	length = 0;
	A = new int[size];
}

Array::Array(int sz) {
	size = sz;
	length = 0;
	A = new int[size];
}

void Array::add(int val) {
	if (length < size) {
		A[length] = val;
		length++;
	}
}

void Array::display() {
	for (size_t i = 0; i < length; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

void Array::insert(int ele, int val) {
	if (ele < size)
	{
		length++;
		for (size_t i = length; i > ele; i--)
		{
			A[i] = A[i - 1];
		}
		A[ele] = val;
	}
}

void Array::remove(int ele) {
	if (ele>=0&&ele<length)
	{
		for (size_t i = ele; i < length; i++)
		{
			A[i] = A[i + 1];
		}
		length--;
	}
}

void Array::insert_in_sorted(int val) {
	if (length<size&&is_sorted()==true)
	{
		int i = length;
		length++;
		while (i > 0 && val<A[i-1])
		{
			A[i] = A[i - 1];
			i--;
		}
		A[i] = val;
	}
	else
	{
		cout << "Array invalied to insert value into sorted!" << endl;
	}
}

bool Array::is_sorted() {
	for (size_t i = 0; i < length-1; i++)
	{
		if (A[i]>A[i+1])
		{
			return false;
		}
	}
	return true;
}

Array::~Array() {
	delete[] A;
}

void Array::merging_arr(const Array &a2) {
	for (size_t i = 0; i < a2.length; i++)
	{
		insert_in_sorted(a2.A[i]);
	}
}

void Array::merging_arr2(const Array &a2) {
	Array* a3 = new Array;
	a3->length = length + a2.length;
	int m = 0, n = 0;
	for (size_t i = 0; i < length + a2.length; i++)
	{
		if (A[m] < a2.A[n])
		{
			a3->A[i] = A[m++];
		}
		else if (A[m] > a2.A[n])
		{
			a3->A[i] = a2.A[n++];
		}
		else
		{
			a3->A[i] = A[m++]; //print same values 
			n++; //Union(same values are printed only one)
		}

		if (m > length) {
			a3->A[i] = a2.A[n++];
		}
		if (n > a2.length) {
			a3->A[i] = A[m++];
		}
	}
	a3->display();
	delete a3;
}

void Array::sort_arr() {
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = 0; j < length; j++)
		{
			if (A[i] < A[j])
			{
				swap(A[i], A[j]);
			}
		}
	}
	display();
}

void Array::intersection(const Array &a2) {
	Array* a3 = new Array;
	a3->length = 0;
	int m = 0, n = 0, k = 0;
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = 0; j < a2.length; j++)
		{
			if (A[i] == a2.A[j])
			{
				a3->length++;
				a3->A[k++] = A[i];
			}
		}
	}

	a3->display();
	delete a3;
}

void Array::difference(const Array &a2) {
	Array* a3 = new Array;
	a3->length = 0;
	int k = 0, count = 0;
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = 0; j < a2.length; j++)
		{
			if (A[i] == a2.A[j])
			{
				break;
			}
			count++;
		}
		if (count == a2.length)
		{
			a3->length++;
			a3->A[k++] = A[i];
		}
		count = 0;
	}

	a3->display();
}

int main() {
	int size, ch, ele, val;
	cout << "Enter size of array: ";
	cin >> size;
	Array* arr;
	arr = new Array(size);

	Array* arr2;
	arr2 = new Array(20);
	arr2->add(3);
	arr2->add(5);
	arr2->add(7);
	arr2->add(10);
	arr2->add(12);
	arr2->add(18);
	do
	{
		cout << "\n--------MENU--------\n";
		cout << "1. Insert\n";
		cout << "2. Delete\n";
		cout << "3. Display\n";
		cout << "4. Intersection\n";
		cout << "5. Exit\n";
		cout << "\n---------------------\n";
		cout << endl;
		cout << "Enter your choose: ";
		cin >> ch;

		switch (ch)
		{
		case 1: cout << "Enter index and value you want insert into array: ";
			cin >> ele >> val;
			arr->insert(ele, val);
			break;
		case 2: cout << "Enter index you want delete: ";
			cin >> ele;
			arr->remove(ele);
			break;
		case 3: arr->display();
			break;
		case 4: arr->intersection(*arr2);
			break;

		}
	} while (ch < 5);


	///*Array arr1(10);

	//arr1.add(3);
	//arr1.add(5);
	//arr1.add(7);
	//arr1.add(9);
	//arr1.display();

	//arr1.insert(3, 12);
	//arr1.display();

	//arr1.remove(1);
	//arr1.display();*/

	///*insert in sorted*/
	//Array arr2(20);
	//arr2.add(3);
	//arr2.add(5);
	//arr2.add(7);
	////arr2.add(9);
	////arr2.add(11);
	////arr2.add(15);
	////arr2.add(18);
	////arr2.add(21);
	////arr2.display();
	////arr2.insert_in_sorted(8);
	////arr2.insert_in_sorted(17);
	//arr2.display();

	//Array arr3(20);

	//arr3.add(30);
	//arr3.add(50);
	//arr3.add(70);
	//arr3.add(90);
	//arr3.merging_arr2(arr2);

	//Array arr4(20);
	//arr4.add(5);
	//arr4.add(2);
	//arr4.add(17);
	//arr4.add(10);
	//arr4.sort_arr();

	return 0;
}