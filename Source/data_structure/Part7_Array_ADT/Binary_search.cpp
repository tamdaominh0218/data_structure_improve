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

int binarySearch1(struct Array arr, int key) {
	int l = 1, h = arr.length, mid = (l + h) / 2;;
	while (l<=mid)
	{
		if (arr.A[mid]==key)
		{
			return mid;
		}
		else if (arr.A[mid]>key)
		{
			mid = (l+mid - 1)/2;
		}
		else
		{
			l = mid + 1;
			mid = (l + h) / 2;
		}
	}
	return -1;
}

int main() {
	struct Array arr = { {2,5,9,11,17,32,45,56,98,113,154,200,543,600}, 20, 14 };
	display(&arr);

	/*Binary search*/
	cout << binarySearch1(arr, 600) << endl;

	return 0;
}