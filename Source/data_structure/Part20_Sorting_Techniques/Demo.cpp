#include <iostream>
#include <set>
#include <vector>
using namespace std;

void bubbleSort(vector<int>&v) {
	for (int i = 0; i < v.size() - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < v.size() - 1 -i; j++)
		{
			if (v[j]>v[j+1])
			{
				swap(v[j], v[j+1]);
				flag = 1;
			}
		}

		if (flag == 0) break;
	}
}

void sortSTL(vector<int>&v) {
	multiset<int> setSort;
	for (int i = 0; i < v.size(); i++)
	{
		setSort.insert(v[i]);
	}
}

void mySort(vector<int>&v) {
	for (size_t i = 0; i < v.size() - 1; i++)
	{
		int temp = v[i + 1];
		for (size_t j = 0; j < i+1 ; j++)
		{
			if (v[j]>temp)
			{
				swap(v[j], v[i+1]);
				temp = v[i+1];
			}
		}
	}
}

////insert sort phiên bản tự dev
//void insertSort(vector<int>&v) {
//	for (int i = 0; i < v.size() - 1; i++)
//	{
//		//Tìm vị trí cần chèn
//		int x = -1;
//		for (size_t j = 0; j < i+1; j++)
//		{
//			if (v[j]>v[i+1])
//			{
//				x = j;
//				break;
//			}
//			//TH ko cần chèn, v[i+1] đã lớn hơn tất cả thì giữ nguyên flag x = -1
//			else
//			{
//				x = -1;
//			}
//		}
//		if (x == -1)
//		{
//			continue; //vòng lặp i tiếp tục chạy
//		}
//
//		//biến temp để lưu giá trị cần chèn, tạo thêm y và k để hỗ trợ dịch
//		int temp = v[i + 1];
//		int y = i + 1;
//		int k = i;
//		//TH vị trí chèn ngay sát bên cạnh (cuối)
//		if (k==x)
//		{
//			v[y] = v[k];
//		}
//		//TH vị trí chèn cần dịch
//		else
//		{
//			while (y != x)
//			{
//				v[y--] = v[k--];
//			}
//		}
//		//chèn data vào vị trí x là vị trí cần chèn
//		v[x] = temp;
//	}
//}

////insert sort phiên bản tối ưu và clean hơn
//void insertSort(vector<int>& v) {
//	for (int i = 0; i < v.size() - 1; i++) {
//		int x = -1;
//
//		// Tìm vị trí cần chèn v[i+1] trong đoạn [0..i]
//		for (int j = 0; j <= i; j++) {
//			if (v[j] > v[i + 1]) {
//				x = j;
//				break;
//			}
//		}
//
//		// Nếu không cần chèn (v[i+1] đã đúng vị trí)
//		if (x == -1)
//			continue;
//
//		int temp = v[i + 1];
//		int y = i + 1;
//
//		// Dịch các phần tử sang phải để tạo chỗ trống
//		while (y > x) {
//			v[y] = v[y - 1];
//			y--;
//		}
//
//		// Chèn phần tử vào vị trí đúng
//		v[x] = temp;
//	}
//}

//Insert sort phiên bản udemy
void insertSort(vector<int>& v) {
	for (int i = 1; i < v.size() - 1; i++)
	{
		int x = v[i];
		int j = i - 1;
		while (j>-1 && v[j]>x)
		{
			v[j+1] = v[j];
			j--; 
		}
		//tăng j lên 1 vì đã j-- ở trên vòng lặp while
		v[j+1] = x;
	}
}

//Chọn phần tử có giá trị nhỏ nhất trong mảng chưa sắp xếp rồi swap với phần tử đầu
void selectionSort(vector<int>& v) {
	for (int i = 0; i < v.size() - 1; i++)
	{
		int y, min_idx;
		y = min_idx = i;
		while (y< v.size() - 1)
		{
			y++;
			if (v[y]<v[min_idx])
			{
				min_idx = y;
			}
		}
		swap(v[min_idx], v[i]);
	}
}

//Quick sort phiên bản tự dev
void quickSort(vector<int>& v, int left, int right) {
	if (left>=right)
	{
		return;
	}

	int pivot = v[right];
	int i = left-1;
	int j = right;

	while (i<j)
	{
		do
		{
			i++;
		} while (v[i] < pivot);

		do
		{
			if (j == 0) break;
			j--;
		} while (v[j] > pivot);

		if (i <= j) {
			swap(v[i], v[j]);
		}
	}

	swap(v[right], v[i]);
	quickSort(v, left, i - 1);
	quickSort(v, i + 1, right);
}

////Quick sort phiên bản chuản Pseudocode (chatGPT)
//void quickSort(vector<int>& arr, int left, int right) {
//	if (left >= right) return; // dừng khi mảng con rỗng hoặc chỉ có 1 phần tử
//
//	int pivot = arr[right]; // chọn pivot là phần tử cuối
//	int i = left - 1;
//
//	for (int j = left; j < right; j++) {
//		if (arr[j] < pivot) {
//			i++;
//			swap(arr[i], arr[j]);
//		}
//	}
//
//	// Đưa pivot về đúng vị trí
//	swap(arr[i + 1], arr[right]);
//
//	// Gọi đệ quy cho hai nửa
//	quickSort(arr, left, i);
//	quickSort(arr, i + 2, right);
//}

void insert(int* Arr, int key, int i) {
	Arr[i] = key;
}

int* merge(int Arr1[], int Arr2[], int n1, int n2) {
	int* newArr = new int[n1 + n2];
	int i,j,k;
	i = j = k = 0;
	while (i<n1&&j<n2)
	{
		if (Arr1[i]<Arr2[j])
		{
			insert(newArr, Arr1[i++], k++);
		}
		else
		{
			insert(newArr, Arr2[j++], k++);
		}
	}

	//Sao chép phần còn lại của Arr1 (nếu có)
	while (i<n1)
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

void displayArray(vector<int>& v) {
	for (size_t i = 0; i < v.size() - 1; i++)
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
	//vector<int> input = { 42, 17, 8, 23, 8, 99, 17, 56, 1, 45, 3, 8, 90, 12, 50, 50, 7, 18, 8, 9, 72, 42, 6, 25, 19, 60, 5, 8, 15, 2 };
	//vector<int> input = { 7, 2, 1, 6, 8, 5, 3, 4 };
	//int length = input.size();
	//displayArray(input);

	//bubbleSort(input, length);
	//mySort(input, length);
	//insertSort(input, length);
	//selectionSort(input);
	//quickSort(input, 0, length - 1);
	//displayArray(input);

	int A[] = { 1 };
	int B[] = { 2,3,4 };

	int l1 = sizeof(A) / sizeof(A[0]);
	int l2 = sizeof(B) / sizeof(B[0]);
	
	int* newA_ptr = nullptr;
	newA_ptr = merge(A, B, l1, l2);
	printArr(newA_ptr, l1 + l2);

	return 0;
}