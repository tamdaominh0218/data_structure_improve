#include <iostream>
#include "Queue.h"
#include "Tree.h"

using namespace std;

int main(){
	vector<int> v = { 1,2,3,-1,5,-1,7 };
	Tree tr1;
	tr1.createfromVector(v);
	tr1.displayOder();
	return 0;
}