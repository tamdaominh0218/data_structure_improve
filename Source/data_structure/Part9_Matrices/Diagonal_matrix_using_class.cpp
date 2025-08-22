#include <iostream>
using namespace std;

class Matrices
{
private:
	int *A;
	int length;
public:
	Matrices();
	Matrices(int l);
	~Matrices();
	void set(int i, int j, int x);
	void display();
	int get(int i, int j);
};

Matrices::Matrices() : Matrices(5)
{
}

Matrices::Matrices(int l)
{
	length = l;
	A = new int[length];
}

Matrices::~Matrices()
{
	delete[] A;
}

void Matrices::set(int i, int j, int x) {
	if (i==j)
	{
		A[i - 1] = x;
	}
}

int Matrices::get(int i, int j) {
	if (i==j)
	{
		return A[i - 1];
	}
}

void Matrices::display() {
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = 0; j < length; j++)
		{
			if (i==j)
			{
				cout << A[i] << " ";
			}
			else
			{
				cout << 0 << " ";
			}
		}
		cout << endl;
	}
}

int main() {
	Matrices* arr = new Matrices(4);
	arr->set(1, 1, 10); arr->set(2, 2, 20); arr->set(3, 3, 30), arr->set(4, 4, 50);
	cout << arr->get(1, 1) << endl;
	cout << arr->get(4, 4) << endl;
	arr->display();
	delete arr;

	return 0;
}