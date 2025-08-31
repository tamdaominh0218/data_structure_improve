#include <iostream>
using namespace std;

void update(int** p) {
	int* newPtr = new int(100);
	*p = newPtr;
}

template <typename T>
void swap(T* a, T* b) {

	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

int main() {
	/*int num = 10;
	int* ptr = &num;
	update(&ptr);
	cout << *ptr << endl;*/

	int num1 = 5, num2 = 3;
	int *prt1 = &num1; 
	int *prt2 = &num2;
	cout << num1 << " " << num2 << endl;
	swap<int>(prt1, prt2);
	cout << num1 << " " << num2 << endl;

	return 0;
}