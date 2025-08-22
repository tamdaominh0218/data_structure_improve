#include <iostream>
using namespace std;

void Hanoi_tower(int num_disk, char A, char B, char C) {
	if (num_disk>0)
	{
		Hanoi_tower(num_disk - 1, A, C, B);
		cout << "Move " << A << " to " << C << endl;
		Hanoi_tower(num_disk - 1, B, A, C);
	}
}

int main() {
	int num = 5;
	char A{ 'A' }, B{ 'B' }, C{ 'C' };
	Hanoi_tower(num, A, B, C);
	return 0;
}