#include <iostream>
#include <set>
#include <vector>
using namespace std;

void bubbleSort(int Arr[], int n) {
	for (int i = 0; i < n-1; i++)
	{
		int flag = 0;
		for (int j = 0; j < n-1-i; j++)
		{
			if (Arr[j]>Arr[j+1])
			{
				swap(Arr[j], Arr[j+1]);
				flag = 1;
			}
		}

		if (flag == 0) break;
	}
}

void sortSTL(int Arr[], int n) {
	multiset<int> setSort;
	for (int i = 0; i < n; i++)
	{
		setSort.insert(Arr[i]);
	}
}

void mySort(int Arr[], int n) {
	for (size_t i = 0; i < n-1; i++)
	{
		int temp = Arr[i + 1];
		for (size_t j = 0; j < i+1 ; j++)
		{
			if (Arr[j]>temp)
			{
				swap(Arr[j], Arr[i+1]);
				temp = Arr[i+1];
			}
		}
	}
}

//insert sort phiên bản tụ dev
void insertSort(vector<int>&v, int n) {
	for (int i = 0; i < n - 1; i++)
	{
		//Tìm vị trí cần chèn
		int x = -1;
		for (size_t j = 0; j < i+1; j++)
		{
			if (v[j]>v[i+1])
			{
				x = j;
				break;
			}
			//TH ko cần chèn, v[i+1] đã lớn hơn tất cả thì giữ nguyên flag x = -1
			else
			{
				x = -1;
			}
		}
		if (x == -1)
		{
			continue; //vòng lặp i tiếp tục chạy
		}

		//biến temp để lưu giá trị cần chèn, tạo thêm y và k để hỗ trợ dịch
		int temp = v[i + 1];
		int y = i + 1;
		int k = i;
		//TH vị trí chèn ngay sát bên cạnh (cuối)
		if (k==x)
		{
			v[y] = v[k];
		}
		//TH vị trí chèn cần dịch
		else
		{
			while (y != x)
			{
				v[y--] = v[k--];
			}
		}
		//chèn data vào vị trí x là vị trí cần chèn
		v[x] = temp;
	}
}

////insert sort phiên bản tối ưu và clean hơn
//void insertSort(vector<int>& v, int n) {
//	for (int i = 0; i < n - 1; i++) {
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


void displayArray(vector<int>& v, int length) {
	for (size_t i = 0; i < length; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

int main() {
	vector<int> input = { 42, 17, 8, 23, 8, 99, 17, 56, 1, 45, 3, 8, 90, 12, 50, 50, 7, 18, 8, 9, 72, 42, 6, 25, 19, 60, 5, 8, 15, 2 };
	int length = input.size();
	displayArray(input, length);

	//bubbleSort(input, length);
	//mySort(input, length);
	insertSort(input, length);
	displayArray(input, length);

	return 0;
}