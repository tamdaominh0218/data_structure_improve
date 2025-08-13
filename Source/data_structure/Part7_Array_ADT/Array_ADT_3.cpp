#include <iostream>
#include <algorithm>
using namespace std;

struct Array {
	int A[20];
	int size;
	int length;
};

void display(struct Array* a) {
	for (size_t i = 0; i < a->length; i++)
	{
		cout << a->A[i] << " ";
	}
	cout << endl;
}

void insert_in_sorted(struct Array* arr, int key) {
	arr->length += 1;
	int i = arr->length - 2;
	while (key < arr->A[i])
	{
		if (key < arr->A[i])
		{
			arr->A[i + 1] = arr->A[i];
		}
		else
		{
			arr->A[i] = key;
		}
		i--;
	}
	arr->A[i + 1] = key;
}

void merging_arr(struct Array a1, struct Array a2) {
	for (size_t i = 0; i < a1.length; i++)
	{
		insert_in_sorted(&a2, a1.A[i]);
	}
	display(&a2);
}

void merging_arr2(struct Array a1, struct Array a2) {
	struct Array* a3 = new struct Array;
	a3->length = a1.length + a2.length;
	int m = 0, n = 0;
	for (size_t i = 0; i < a1.length + a2.length; i++)
	{
		if (a1.A[m] < a2.A[n])
		{
			a3->A[i] = a1.A[m++];
		}
		else if (a1.A[m] > a2.A[n])
		{
			a3->A[i] = a2.A[n++];
		}
		else
		{
			a3->A[i] = a1.A[m++]; //print same values 
			n++; //Union(same values are printed only one)
		}

		if (m > a1.length) {
			a3->A[i] = a2.A[n++];
		}
		if (n > a2.length) {
			a3->A[i] = a1.A[m++];
		}
	}
	display(a3);
	delete a3;
}

void sort_arr(struct Array* arr) {
	for (size_t i = 0; i < arr->length; i++)
	{
		for (size_t j = 0; j < arr->length; j++)
		{
			if (arr->A[i] < arr->A[j])
			{
				swap(arr->A[i], arr->A[j]);
			}
		}
	}
	display(arr);
}

void intersection(struct Array a1, struct Array a2) {
	struct Array* a3 = new struct Array;
	a3->length = 0;
	int m = 0, n = 0, k =0;
	for (size_t i = 0; i < a1.length; i++)
	{
		for (size_t j = 0; j < a2.length; j++)
		{
			if (a1.A[i]==a2.A[j])
			{
				a3->length++;
				a3->A[k++] = a1.A[i];
			}
		}
	}

	display(a3);
}

void difference(struct Array a1, struct Array a2) {
	struct Array* a3 = new struct Array;
	a3->length = 0;
	int k = 0, count = 0;
	for (size_t i = 0; i < a1.length; i++)
	{
		for (size_t j = 0; j < a2.length; j++)
		{
			if (a1.A[i]==a2.A[j])
			{
				break;
			}
			count++;
		}
		if (count==a2.length)
		{
			a3->length++;
			a3->A[k++] = a1.A[i];
		}
		count = 0;
	}

	display(a3);
}

int main() {
	struct Array arr = { {2,5,9,11,17,32,45,56,98,113,154,200,543,600}, 20, 14 };
	display(&arr);

	///*Binary search*/
	//cout << binarySearch1(arr, 600) << endl;

	/*Insert sorted*/
	insert_in_sorted(&arr, 114);
	display(&arr);

	/*Merger array*/
	struct Array arr1 = { {3,5,9,11,17}, 20, 5 };
	struct Array arr2 = { {4,11,21,33,44}, 20, 5 };
	merging_arr2(arr1, arr2);

	/*Sort*/
	struct Array arr3 = { {55,21,14,32,67,28,99,12,43,16}, 20, 10 };
	display(&arr3);
	sort_arr(&arr3);

	intersection(arr1, arr2);
	difference(arr1, arr2);

	return 0;
}