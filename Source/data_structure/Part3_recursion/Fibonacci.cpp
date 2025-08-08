#include <iostream>
#include <stdio.h>
using namespace std;

long long fibo(int n) {
	if (n==0||n==1)
	{
		return n;
	}
	int a = 0, b = 1, sum;
	for (int i = 2; i <= n; i++)
	{
		sum = a + b;
		a = b;
		b = sum;
	}
	return sum;
}

int daonguoc(int num) {
	int du, r=0;
	while (num != 0)
	{
		du = num % 10;
		r = r*10 + du;
		num /= 10;
	}
	return r;
}

void daonguocchu(string name) {
	int size = name.length();
	for (size_t i = 0; i <size/2; i++)
	{
		swap(name[i], name[size - i-1]);
	}
	cout << name;
}

int main() {
	int num = 7;
	cout << fibo(num) << endl;

	/*int n = 1234;
	cout << daonguoc(n) << endl;
	return 0;*/

	/*string my_name = "DAOMINHTAM";
	daonguocchu(my_name);*/

	return 0;
}

//0 1 1 2 3 5 8