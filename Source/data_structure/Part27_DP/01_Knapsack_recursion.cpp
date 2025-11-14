#include <iostream>
#include <vector>

using namespace std;

int K_recursion(vector<int>& value, vector<int>& weight, int n, int capacity) {
	if (n ==0 || capacity==0)
	{
		return 0;
	}

	if (weight[n-1]<=capacity)
	{
		int no = K_recursion(value, weight, n-1, capacity);
		int yes = value[n-1]+K_recursion(value, weight, n-1, capacity-weight[n-1]);
		return no > yes ? no : yes;
	}
	
	return K_recursion(value, weight, n-1, capacity);
}

int main() {
	vector<int> p = { 6,5,3,8 };
	vector<int> w = { 1,2,1,2 };
	int n = 4; int cap = 5;
	cout << K_recursion(p, w, n, cap);

	return 0;
}