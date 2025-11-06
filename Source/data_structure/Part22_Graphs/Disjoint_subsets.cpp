#include <iostream>
#include <vector>
using namespace std;

class Disjoint
{
	int n;
	vector<int> size;
public:
	Disjoint(int n) :n(n), size(n + 1, -1) {};
	Disjoint(int n, vector<int>&v) :n(n), size(v) {};
	void union_disjoint(int u, int v);
	int find(int x);
};

void Disjoint:: union_disjoint(int u, int v) {
	if (size[u]<size[v])
	{
		size[u] += size[v];
		size[v] = u;
	}
	else
	{
		size[v] += size[u];
		size[u] = v;
	}
}

int Disjoint::find(int x) {
	int k = x;
	while (size[k]>0)
	{
		k = size[k];
	}
	return k;
}

int main() {
	vector<int> s = { -1,-1,-1,-3,-4,3,-1,4,4,3,4 };
	Disjoint test = { 10, s};
	test.union_disjoint(3, 4);
	cout << test.find(1) << endl;
	cout << test.find(2) << endl;
	cout << test.find(3) << endl;
	cout << test.find(4) << endl;
	cout << test.find(5) << endl;
	cout << test.find(6) << endl;
	cout << test.find(7) << endl;
	cout << test.find(8) << endl;
	cout << test.find(9) << endl;
	cout << test.find(10) << endl;
	return 0;
}