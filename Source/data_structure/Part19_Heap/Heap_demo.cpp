#include <iostream>
#include <vector>
using namespace std;

enum checkRL {left, right};

struct Heap
{
	vector<int> v;
};

void insertMaxHeap(Heap* tree, int key) {
	if (tree->v.empty())
	{
		tree->v.push_back(key);
		return;
	}

	tree->v.push_back(key);
	int key_index = tree->v.size()-1;

	while (key_index>0)
	{
		int parrent = (key_index - 1) / 2;
		if (tree->v.at(key_index)> tree->v.at(parrent))
		{
			swap(tree->v.at(key_index), tree->v.at(parrent));
			key_index = parrent;
		}
		else
		{
			break;
		}
	}
}

checkRL compareChill(Heap* tree, int x) {
	if (x==tree->v.size()-2|| x == tree->v.size() - 1)
	{
		return checkRL::left;
	}
	if (tree->v.at(2*x+1)> tree->v.at(2*x + 2))
	{
		return checkRL::left;
	}
	else
	{
		return checkRL::right;
	}
}

int isParrentNode(Heap* tree, int x) {
	if (x == tree->v.size() - 2 || x == tree->v.size() - 1)
	{
		return 0;
	}
	if (tree->v.at(x)< tree->v.at(x+1) || tree->v.at(x) < tree->v.at(x + 2))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void deleteHeap(Heap* tree) {
	int size = tree->v.size();
	int rightEnd = size - 1;
	int i = 0;
	swap(tree->v.at(0), tree->v.at(rightEnd));
	tree->v.pop_back();
	while (!isParrentNode(tree, i))
	{
		if (compareChill(tree, i)==checkRL::left)
		{
			swap(tree->v.at(i), tree->v.at(2*i + 1));
			i = 2*i + 1;
		}

		if (compareChill(tree, i) == checkRL::right)
		{
			swap(tree->v.at(i), tree->v.at(2*i + 2));
			i = 2*i + 2;
		}

		if (i>=12)
		{
			break;
		}
	}
}

void displayHeap(Heap* tree) {
	for (auto x : tree->v)
		cout << x << " ";
	cout << endl;
}

int main() {
	Heap h1;
	insertMaxHeap(&h1, 30);
	insertMaxHeap(&h1, 31);
	insertMaxHeap(&h1, 36);
	insertMaxHeap(&h1, 33);
	insertMaxHeap(&h1, 39);
	insertMaxHeap(&h1, 35);
	insertMaxHeap(&h1, 12);
	insertMaxHeap(&h1, 41);
	insertMaxHeap(&h1, 19);
	insertMaxHeap(&h1, 71);
	insertMaxHeap(&h1, 27);
	insertMaxHeap(&h1, 21);
	insertMaxHeap(&h1, 49);
	insertMaxHeap(&h1, 11);
	insertMaxHeap(&h1, 9);
	displayHeap(&h1);

	deleteHeap(&h1);
	displayHeap(&h1);
	return 0;
}