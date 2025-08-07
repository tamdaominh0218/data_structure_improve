#include <iostream>
using namespace std;

int sumOfNumber(int n);
int sumOfNumber_recursion(int n);

int main() {
	int a = 7;
	cout << sumOfNumber(a) << endl;
	cout << sumOfNumber_recursion(a) << endl;
	return 0;
}

int sumOfNumber(int n) {
	int sum = 0;
	while (n>0)
	{
		sum += n;
		n--;
	}
	return sum;
}

int sumOfNumber_recursion(int n) {
	if (n==0)
	{
		return 0;
	}
	return sumOfNumber_recursion(n - 1) + n;
}