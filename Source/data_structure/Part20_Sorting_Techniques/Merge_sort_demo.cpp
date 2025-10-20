#include <iostream>
#include <vector>

using namespace std;

//API cho merge 2 mảng
void insert(int* Arr, int key, int i) {
	Arr[i] = key;
}

//Hàm merge 2 mảng 
int* merge(int Arr1[], int Arr2[], int n1, int n2) {
	int* newArr = new int[n1 + n2];
	int i, j, k;
	i = j = k = 0;
	while (i < n1 && j < n2)
	{
		if (Arr1[i] < Arr2[j])
		{
			insert(newArr, Arr1[i++], k++);
		}
		else
		{
			insert(newArr, Arr2[j++], k++);
		}
	}

	//Sao chép phần còn lại của Arr1 (nếu có)
	while (i < n1)
	{
		insert(newArr, Arr1[i++], k++);
	}
	//Sao chép phần còn lại của Arr2 (nếu có)
	while (j < n2)
	{
		insert(newArr, Arr2[j++], k++);
	}
	return newArr;
}

//API cho Merge Sort Iterative
void merge(vector<int>& v, int left, int mid, int right) {
	vector<int> temp;
	int i, j, k;
	i = left;
	j = mid + 1;
	k = 0;
	while (i<=mid && j<= right)
	{
		if (v[i]<v[j])
		{
			temp.push_back(v[i++]);
		}
		else
		{
			temp.push_back(v[j++]);
		}
	}

	while (i<=mid)
	{
		temp.push_back(v[i++]);
	}
	while (j <= right)
	{
		temp.push_back(v[j++]);
	}

	for (size_t i = left; i <= right; i++)
	{
		v[i] = temp[k++];
	}
}

//Hàm Merge Sort Iterative
void mergeSort_Iterative(vector<int>& v) {
	int n = v.size();
	for (int size = 1; size < n; size*=2)
	{
		for (int left = 0; left < n-size; left+=2*size)
		{
			int mid = left + size - 1;
			int right = min(left + 2 * size - 1, n - 1);
			merge(v, left, mid, right);
		}
	}
}

//Hàm Merger Sort Revcusive
void mergeSort_Recusive(vector<int>& v, int l, int h) {
	int mid = (l + h) / 2;
	if (l<h)
	{
		mergeSort_Recusive(v, l, mid);
		mergeSort_Recusive(v, mid + 1, h);
		merge(v, l, mid, h);
	}
}

//API tìm max vector
int max_vector(vector<int>& v) {
	int vmax = INT_MIN;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]> vmax)
		{
			vmax = v[i];
		}
	}
	return vmax;
}

//API tìm min vector
int min_vector(vector<int>& v) {
	int vmin = INT_MAX;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] < vmin)
		{
			vmin = v[i];
		}
	}
	return vmin;
}


//Hàm Count Sort
void countSort(vector<int>& v) {
	int findMax = max_vector(v);
	int findMin = min_vector(v);
	int range = findMax - findMin + 1;
	int k = 0;
	vector<int> backUp (range+1, 0);

	//Nếu có số âm thì dịch giá trị về vùng dương bằng offset
	for (int x: v)
	{
		backUp[x-findMin]++;
	}

	//Ghi ngược lại vào mảng gốc
	/*for (int i = 0; i <= range; i++)
	{
		if (backUp[i]>0)
		{
			v[k++] = i+findMin;
		}
		else if (backUp[i] > 1)
		{
			while (backUp[i] > 0)
			{
				v[k++] = i+findMin;
				backUp[i]--;
			}
		}
	}*/

	for (int i = 0; i <= range; i++)
	{
		while (backUp[i]!=0)
		{
			v[k++] = i + findMin;
			backUp[i]--;
		}
	}
}

void displayArray(vector<int>& v) {
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

void printArr(int* a, int n) {
	for (int i = 0; i < n; ++i) {
		cout << a[i] << (i + 1 == n ? '\n' : ' ');
	}
}

int main() {
	//int A[] = { 2, 3, 8, 12, 5, 6, 7, 10 };
	//int length = sizeof(A) / sizeof(A[0]);
	//int l = 0;
	//int h = length - 1;
	//int mid = (l + h) / 2;
	//printArr(A, length);

	vector<int> Vec = { 2, 3, 3, 8, 12, 5, 6, 7 ,10};
	//mergeSort_Iterative(Vec);
	//mergeSort_Recusive(Vec, 0, Vec.size() - 1);
	countSort(Vec);
	displayArray(Vec);

	return 0;
}