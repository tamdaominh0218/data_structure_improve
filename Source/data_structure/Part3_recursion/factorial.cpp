#include <iostream>
using namespace std;

int fact(int n);
int fact_recursion(int n);

int main() {
	int a = 5;
	cout << fact(a) << endl;
	cout << fact_recursion(a) << endl;
	return 0;
}

int fact(int n) {
	int f = 1;
	while (n>0)
	{
		f *= n;
		n--;
	}
	return f;
}

int fact_recursion(int n) {
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return n * fact_recursion(n - 1);
	}
}