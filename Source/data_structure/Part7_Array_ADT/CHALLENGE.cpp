#include <iostream>
using namespace std;

void display(int *arr, int length){
	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int sigle_element_missing(const int *arr,const int length) {
	for (size_t i = 0; i < length; i++)
	{
		if (arr[i]!=arr[i+1]-1)
		{
			return arr[i] + 1;
		}
	}
	return -1;
}

void multi_element_missing(const int* arr, const int size) {
	int* backup = new int[size];
	int k = 0, length = 0;
	for (size_t i = 0; i < size-1; i++)
	{
		if (arr[i] != arr[i + 1] - 1)
		{
			length++;
			backup[k++]=arr[i]+1;
		}
	}
	display(backup, length);
}

//void find_duplicate_elements(const int* arr, int length) {
//	int lastDulicate = 0;
//	for (size_t i = 0; i < length-1; i++)
//	{
//		if (arr[i] == arr[i + 1]) 
//		{
//			if (lastDulicate == 0) 
//			{
//				cout << arr[i] << endl;
//			}
//			lastDulicate = arr[i];
//		}
//		else
//		{
//			lastDulicate = 0;
//		}
//	}
//}

void find_duplicate_elements2(const int* arr, int length) {
	int* A = new int[arr[length - 1]];
	for (size_t i = 0; i <= arr[length - 1]; i++)
	{
		A[i] = 0;
	}
	for (size_t i = 0; i < length; i++)
	{
		A[arr[i]] += arr[i];
	}
	for (size_t i = 0; i <= arr[length - 1]; i++)
	{
		if (A[i]!=i&&A[i]!=0)
		{
			cout << A[i]/i << " lan " << i << endl;
		}
	}
	delete[] A;
}

void find_pair_element_with_sum_k(const int* arr, int length, int sum) {
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = 0; j < length; j++)
		{
			if (arr[i] == sum - arr[j])
			{
				cout << sum << " is sum of " << arr[i] << " and " << arr[j] << endl;
			}
		}
	}
}

int main() {
	/*int a[10] = { 1,2,3,4,5,6,7,8,10,11 };
	cout << sigle_element_missing(a, 10) << endl;

	int a1[10] = { 1,2,4,5,6,7,8,10,11,12 };
	multi_element_missing(a1, 10);*/
	
	/*int a2[10] = { 3,6,8,8,12,12,15,15,15,20 };
	find_duplicate_elements2(a2, 10);*/

	int sum = 10;
	int a2[10] = { 6,3,8,10,16,7,5,2,9,14 };
	find_pair_element_with_sum_k(a2, 10, sum);
	return 0;
}

//0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
//0 0 0 3 0 0 6 0 8 0 0  0  0  0  0  0  0  0  0  0  0