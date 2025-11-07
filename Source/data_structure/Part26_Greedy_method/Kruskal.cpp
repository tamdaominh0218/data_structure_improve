#include <iostream>
#include <vector>
using namespace std;

class Disjoint
{
	int n;
	vector<int> size;
public:
	Disjoint(int n) :n(n), size(n + 1, -1) {};
	Disjoint(int n, vector<int>& v) :n(n), size(v) {};
	void union_disjoint(int u, int v);
	int find(int x);
	int kruskal_algorithm(vector<vector<int>>& v);
};

void Disjoint::union_disjoint(int u, int v) {
	if (size[u] < size[v])
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
	while (size[k] > 0)
	{
		k = size[k];
	}
	return k;
}

int Disjoint::kruskal_algorithm(vector<vector<int>>& v) {
	int countC = 0, numPeaks = 7, WeightOpt=0;
	while (countC<numPeaks-1)
	{
		int minWeight = INT_MAX;
		int k = 0;  //save element of minWeight
		for (size_t i = 0; i < v.size(); i++)
		{
			if (v[i][2]<minWeight)
			{
				minWeight = v[i][2];
				k = i;
			}
		}

		v[k][2] = INT_MAX; //update min weight to max to find next min weight;

		if (find(v[k][1])!=find(v[k][0]))
		{
			countC++;
			WeightOpt += minWeight;
			size[v[k][1]] = v[k][0];
		}

	}
	return WeightOpt;
}

int main() {
	vector<vector<int>> arr = { {1,2,28}, {1,6,10}, {2,3,16}, {2,7,14}, {3,4,12}, {4,5,22}, {4,7,18}, {5,6,25}, {5,7,24} };
	Disjoint* d = new Disjoint(arr.size());
	cout << d->kruskal_algorithm(arr);
	return 0;
}