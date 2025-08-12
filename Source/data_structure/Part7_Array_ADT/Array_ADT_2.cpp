#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Array2 {
	int A[20];
	int size;
	int length;
};

void display2(struct Array2 a) {
	for (size_t i = 0; i < a.length; i++)
	{
		cout << a.A[i] << " ";
	}
	cout << endl;
}

int max(struct Array2 arr) {
	int max = arr.A[0];
	for (size_t i = 0; i < arr.length; i++)
	{
		if (arr.A[i] > max)
		{
			max = arr.A[i];
		}
	}
	return max;
}

int min(struct Array2 arr) {
	int min = arr.A[0];
	for (size_t i = 0; i < arr.length; i++)
	{
		if (arr.A[i] < min)
		{
			min = arr.A[i];
		}
	}
	return min;
}

void reverse(struct Array2 *arr) {
	for (size_t i = 0; i < arr->length / 2; i++)
	{
		swap(arr->A[i], arr->A[arr->length - 1 - i]);
	}
}

int main() {

	/*Max - Min*/
	struct Array2 arr2 = { {100,40,24,67,88,24,11,99,34,101,73,21,5}, 20, 13 };
	display2(arr2);
	cout << max(arr2) << endl;
	cout << min(arr2) << endl;

	/*Reverse*/
	reverse(&arr2);
	display2(arr2);

	return 0;
}