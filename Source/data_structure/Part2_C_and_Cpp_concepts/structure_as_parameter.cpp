#include <iostream>
#include <stdio.h>
using namespace std;

struct rectangle
{
	int lenghth;
	int breadth;
};

int func(struct rectangle r) {
	return r.lenghth * r.breadth;
}

int funcc(struct rectangle* r) {
	return r->lenghth * r->breadth;
}

struct rectangle *fun() {
	struct rectangle* rec = new (struct rectangle);
	rec->lenghth = 15;
	rec->breadth = 10;
	return rec;
}

int main() {
	struct rectangle r1 = { 10,5 };
	cout << "Dien tich hinh chu nhat 1 la " << func(r1) << " (don vi dien tich)" << endl;

	struct rectangle* ptr = fun();
	cout << "Dien tich hinh chu nhat 2 la " << funcc(ptr) << " (don vi dien tich)" << endl;

	return 0;
}