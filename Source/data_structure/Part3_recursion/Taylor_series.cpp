#include <iostream>
#include <cmath>
using namespace std;

double e(int m, int n) {
	if (n==0)
	{
		return 1;
	}
	static double p = 1, f = 1;
	double r;
	r = e(m, n - 1);
	p = p * m;
	f = f * n;
	return r + (p / f);
}

// Hàm tính giai thừa
long long factorial(int n) {
	if (n == 0 || n == 1) return 1;
	long long result = 1;
	for (int i = 2; i <= n; i++)
		result *= i;
	return result;
}

// Hàm tính e^x bằng chuỗi Taylor
double taylor_exp(double x, int terms) {
	double sum = 0.0;
	for (int n = 0; n < terms; n++) {
		sum += pow(x, n) / factorial(n);
	}
	return sum;
}

int main(){
	double x = 3;
	int n = 10;
	cout << e(3, 10) << endl;

	double approx = taylor_exp(x, n);
	double actual = exp(x); // Hàm e^x trong thư viện cmath

	cout << "Gia tri xap xi e^x = " << approx << endl;
	cout << "Gia tri thuc su e^x = " << actual << endl;
	cout << "Sai so = " << fabs(actual - approx) << endl;

	return 0;
}