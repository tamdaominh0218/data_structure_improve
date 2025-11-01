#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& v, int key) {
	int l = 0;
	int h = v.size() - 1;

	while (l<=h)
	{
		int mid = l + (h - l) / 2;
		if (key==v[mid])
		{
			return  mid;
		}
		else if (key<v[mid])
		{
			h = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	return -1;
}

int binarySearchR(vector<int>& v, int l, int h, int key) {
	int mid = l + (h - l) / 2;
	if (l > h) return  -1;

	if (key == v[mid])
	{
		return mid;
	}
	else if (key<v[mid])
	{
		return binarySearchR(v, l, mid - 1, key);
	}
	else
	{
		return binarySearchR(v, mid+1, h, key);
	}
}

void merge(vector<int>& v, int l, int h) {
	int mid = l + (h - l) / 2;
	int i = l;
	int j = mid + 1;
	vector<int> B;
	while (i<=mid && j<=h)
	{
		if (v[i]<v[j])
		{
			B.push_back(v[i++]);
		}
		else
		{
			B.push_back(v[j++]);
		}
	}

	for (size_t; i <= mid; i++)
	{
		B.push_back(v[i]);
	}

	for (size_t; j <= h; j++)
	{
		B.push_back(v[j]);
	}

	int k = 0;
	for (size_t z = l; z <= h; z++)
	{
		v[z] = B[k++];
	}
}

void mergeSortR(vector<int>& v, int l, int h) {
	int mid = l + (h - l) / 2;
	if (l==h)
	{
		return;
	}

	mergeSortR(v, l, mid);
	mergeSortR(v, mid+1, h);
	merge(v, l, h);
}

void mergeSortI(vector<int>& v) {
	int n = v.size();
	for (int size = 1; size < n; size*=2)
	{
		for (int l = 0; l <n-size ; l=l+2*size)
		{
			int right = min(l + 2 * size - 1, n - 1);
			merge(v, l, right);
		}
	}
}

int main() {
	vector<int> arr = {6,2,34,1,5,3,9,11};
	mergeSortI(arr);

	for (size_t i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}
//0 1 2 3 4