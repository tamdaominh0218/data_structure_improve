#include <iostream>
using namespace std;

class LowerTri
{
private:
	int* A;
	int size;
public:
	LowerTri();
	LowerTri(int n);
	void rSet(int i, int j, int x);
	int rGet(int i, int j);
	void cSet(int i, int j, int x);
	int cGet(int i, int j);
	void rdisplay();
	void cdisplay();

	~LowerTri();
};

LowerTri::LowerTri() :LowerTri(2)
{
}

LowerTri::LowerTri(int n)
{
	size = n;
	A = new int[size*(size+1)/2];
}

void LowerTri::rSet(int i, int j, int x) {
	if (i>=j)
	{
		A[(i*(i - 1) / 2) + j - 1] = x;
	}
}

int LowerTri::rGet(int i, int j) {
	if (i>=j)
	{
		return A[(i * (i - 1) / 2) + j - 1];
	}
	else
		return 0;
}

void LowerTri::cSet(int i, int j, int x) {
	if (i >= j)
	{
		A[size * (j - 1) - (j - 2) * (j - 1) / 2 + i - j] = x;
	}
}

int LowerTri::cGet(int i, int j) {
	if (i >= j)
	{
		return A[size * (j - 1) - (j - 2) * (j - 1) / 2 + i - j];
	}
	else
		return 0;
}

void LowerTri::rdisplay() {
	for (size_t i = 1; i <= size; i++)
	{
		for (size_t j = 1; j <= size; j++)
		{
			if (i>=j)
			{
				cout << A[(i * (i - 1) / 2) + j - 1] << " ";
			}
			else
			{
				cout << 0 << " ";
			}
		}
		cout << endl;
	}
}

void LowerTri::cdisplay() {
	for (size_t i = 1; i <= size; i++)
	{
		for (size_t j = 1; j <= size; j++)
		{
			if (i >= j)
			{
				cout << A[size * (j - 1) - (j - 2) * (j - 1) / 2 + i - j] << " ";
			}
			else
			{
				cout << 0 << " ";
			}
		}
		cout << endl;
	}
}

LowerTri::~LowerTri()
{
	delete[] A;
}

int main() {
	int x;
	LowerTri matrix1(4);
	//for (size_t i = 1; i <= 4; i++)
	//{
	//	for (size_t j = 1; j <= 4; j++)
	//	{
	//		cin >> x;
	//		matrix1.rSet(i, j, x);
	//	}
	//}

	//cout << endl;
	//matrix1.rdisplay();

	for (size_t i = 1; i <= 4; i++)
	{
		for (size_t j = 1; j <= 4; j++)
		{
			cin >> x;
			matrix1.cSet(i, j, x);
		}
	}

	cout << endl;
	matrix1.cdisplay();

	return 0;
}