#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Arr {
	int* a;
	int size;
	int length;
};

void display(struct Arr* a) {
	for (size_t i = 0; i < a->length; i++)
	{
		cout << a->a[i] << " ";
	}
	cout << endl;
}

void remove(struct Arr* a, int ele) {
	if (ele<a->length)
	{
		for (size_t i = ele; i < a->length; i++)
		{
			a->a[i] = a->a[i+1];
		}
		a->length--;
	}
}

void insert(struct Arr* a, int ele, int val) {
	if (ele < a->size)
	{
		a->length++;
		for (size_t i = a->length; i > ele; i--)
		{
			a->a[i] = a->a[i - 1];
		}
		a->a[ele] = val;
	}
}

int main() {
	struct Arr arr;
	arr.size = 10;
	arr.a = new int[arr.size];
	arr.length = 5;

	cout << "Enter value of each element of your array: " << endl;
	for (size_t i = 0; i < arr.length; i++)
	{
		cin >> arr.a[i];
	}
	display(&arr);

	/*Delete*/
	remove(&arr, 2);
	display(&arr);

	/*Insert*/
	insert(&arr, 1, 100);
	display(&arr);

	return 0;
}