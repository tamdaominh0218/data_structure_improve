#include <iostream>
using namespace std;

int power(int m, int n);
int power2(int m, int n);
int power3(int m, int n);

int main() {
	int a = 2, b = 10;
	//cout << power(a, b) << endl;
	cout << power2(a, b) << endl;
	cout << power3(a, b) << endl;
	return 0;
}

int power(int m, int n) {
	if (n==0)
	{
		return 1;
	}
	else
	{
		return m * power(m, n - 1);
	}
}

int power2(int m, int n) {
	if (n == 0)
	{
		return 1;
	}
	if (n%2==0)
	{
		return power2(m*m, n / 2);
	}
	if (n%2!=0)
	{
		return m * power2(m * m, (n - 1) / 2);
	}
}

int power3(int m, int n) {
	if (n == 0)
	{
		return 1;
	}
	int power = 1;
	for (size_t i = 0; i < n; i++)
	{
		power *= m;
	}
	return power;
}