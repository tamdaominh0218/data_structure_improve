#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    // === Max Heap với priority_queue (mặc định là Max Heap) ===
    priority_queue<int> maxHeap;
    maxHeap.push(30);
    maxHeap.push(10);
    maxHeap.push(50);
    maxHeap.push(20);
    maxHeap.push(40);

    cout << "=== Max Heap (STL) ===" << endl;
    cout << "Top = " << maxHeap.top() << endl;  // luôn là phần tử lớn nhất
    cout << "Elements: ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl << endl;

    // === Min Heap với priority_queue (dùng greater<int>) ===
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(30);
    minHeap.push(10);
    minHeap.push(50);
    minHeap.push(20);
    minHeap.push(40);

    cout << "=== Min Heap (STL) ===" << endl;
    cout << "Top = " << minHeap.top() << endl;  // luôn là phần tử nhỏ nhất
    cout << "Elements: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;

    return 0;
}
