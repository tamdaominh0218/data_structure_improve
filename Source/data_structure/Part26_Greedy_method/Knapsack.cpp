#include <iostream>
#include <vector>

using namespace std;

int findMax(vector<float>& v) {
	float eMax = 0;
	int e;
	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i]>eMax)
		{
			eMax = v[i];
			e = i;
		}
	}
	return e;
}

void knapsack(vector<vector<int>>&v, int size) {
	vector<float> weight(7,0);
	vector<float> avr;
	int x;
	for (size_t i = 0; i < v[0].size(); i++)
	{
		x = (float)v[0][i] / v[1][i];
		avr.push_back(x);
	}

	int w = 0;
	while (w+ v[1][findMax(avr)] <size)
	{
		w += v[1][findMax(avr)];
		weight[findMax(avr)] = 1;
		avr[findMax(avr)] = 0;
	}
	weight[findMax(avr)] = (float)(size - w) / v[1][findMax(avr)];

	for (size_t i = 0; i < weight.size(); i++)
		cout << "Object " << i + 1 << ": " << weight[i] << endl;
}

int main() {
	int n = 7;
	vector<vector<int>> object= { {12,17,9,7,5,21,8},{2,5,7,3,1,4,1} };
	knapsack(object, 15);
	return 0;
}