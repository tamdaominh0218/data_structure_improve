#include <iostream>
#include <vector>
#include "Hashing.h"
using namespace std;

void buildLinearProbing(vector<Node*>&H, const int key) {
	int remainder = key % 10;
	if (H[remainder]==nullptr)
	{
		insertNode(&H[remainder], key);
	}
	else
	{
		while (H[remainder]!=nullptr)
		{
			remainder++;
			if (remainder>9)
			{
				remainder = 0;
			}
		}
		insertNode(&H[remainder], key);
	}
}

bool search(vector<Node*>& v, int key) {
	int remainder = key%10;
	int count = 0;
	while (v[remainder]->data != key && v[remainder]!=nullptr && count <= 10)
	{
		count++;
		remainder++;
		if (remainder > 9)
		{
			remainder = 0;
		}

	}
	if (v[remainder]->data==key) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

void deleteLinearProbing(vector<Node*>& v, int key) {
	if (search(v, key)!=true)
	{
		return;
	}
	int remainder = key % 10;
	if (v[remainder]->data==key)
	{
		delete v[remainder];
	}
	else
	{
		while (v[remainder]->data == key)
		{
			remainder = (remainder++)%10;
		}
	}
}

int main() {
	vector<Node*> linerProbing(10, nullptr);
	buildLinearProbing(linerProbing, 26);
	buildLinearProbing(linerProbing, 30);
	buildLinearProbing(linerProbing, 45);
	buildLinearProbing(linerProbing, 23);
	buildLinearProbing(linerProbing, 25);
	buildLinearProbing(linerProbing, 43);
	buildLinearProbing(linerProbing, 74);
	buildLinearProbing(linerProbing, 19);
	buildLinearProbing(linerProbing, 29);


	return 0;
}