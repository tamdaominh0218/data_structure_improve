#include <iostream>
#include <vector>

using namespace std;

vector<int> coin_change(vector<int>& v, int key) {
	int x = v.size() - 1;
	int val = 0;

	vector<int> backUp;
	while (x>=0 && val!=key)
	{
		while (val+v[x] <= key)
		{
			backUp.push_back(x);
			val += v[x];
		}
			x--;
	}
	return backUp;
}

void print(vector<int>& v, vector<int>& p) {
	for (auto x : p) {
		cout << v[x] << " ";
	}
}

int main() {
	vector<int> m = { 1,2,5,10,20,50,100,200,500 };
	int key =368;

	vector<int> p = coin_change(m, key);
	print(m, p);
	return 0;
}