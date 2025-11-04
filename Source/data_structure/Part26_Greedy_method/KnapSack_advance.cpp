#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Object
{
	int profit;
	int weight;
public:
	Object(int p, int w);
	int getProfit();
	int getWeight();
	double ratio() const;
};

void mergeSortR(vector<Object>& v, int l, int h);

Object::Object(int p, int w)
{
	profit = p;
	weight = w;
}

int Object::getProfit()
{
	return profit;
}

int Object::getWeight()
{
	return weight;
	;
}

double Object::ratio() const {
	return (double)profit / weight;
}

double knapsackGreedy(vector<Object>& v, int bagSize) {
	//Sắp xếp lại các đối tượng từ nhỏ đến lớn theo ratio
	//mergeSortR(v, 0, v.size() - 1);
	sort(v.begin(), v.end(), [](const Object& a, const Object& b) {return a.ratio() < b.ratio(); });
	double totalProfit = 0;
	double load = 0;

	for (int i = v.size()-1; i>=0; i--)
	{
		if (load + v[i].getWeight()<=bagSize)
		{
			totalProfit += v[i].getProfit();
			load += v[i].getWeight();

			cout << "Get all objects with weight " << v[i].getWeight() << " and total value is "<< v[i].getProfit() << endl;
		}
		else
		{
			double r = (double)(bagSize - load) / v[i].getWeight();
			totalProfit += r * v[i].getProfit();
			cout << "Get " << (double)100*r << "% objects with weight " << v[i].getWeight() << " and total value is " << r*v[i].getProfit() << endl;
			break;
		}
	}
	return totalProfit;
}

void merge(vector<Object>& v, int l, int h) {
	int mid = l + (h - l) / 2;
	int i = l;
	int j = mid + 1;
	vector<Object> B;
	while (i <= mid && j <= h)
	{
		if (v[i].ratio() < v[j].ratio())
		{
			B.push_back(v[i++]);
		}
		else
		{
			B.push_back(v[j++]);
		}
	}

	for (size_t; i <= mid; i++)
	{
		B.push_back(v[i]);
	}

	for (size_t; j <= h; j++)
	{
		B.push_back(v[j]);
	}

	int k = 0;
	for (size_t z = l; z <= h; z++)
	{
		v[z] = B[k++];
	}
}

//Merge sort
void mergeSortR(vector<Object>& v, int l, int h) {
	int mid = l + (h - l) / 2;
	if (l >= h)
	{
		return;
	}

	mergeSortR(v, l, mid);
	mergeSortR(v, mid + 1, h);
	merge(v, l, h);
}

int main() {
	vector<Object> items = { {8,1}, {12,2}, {5,1}, {21,4}, {17,5}, {7,3}, {9,7} };
	int cap = 15;
	
	double optimalProfit = knapsackGreedy(items, cap);
	cout << "The optimal total value is: " << optimalProfit << endl;

	return 0;
}