#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
    vector<int> v;
    bool isMaxHeap;  // true = MaxHeap, false = MinHeap

    // Hàm heapify-up (sau khi insert)
    void heapifyUp(int idx) {
        if (idx == 0) return; // root thì dừng
        int parent = (idx - 1) / 2;

        if (isMaxHeap) {
            if (v[idx] > v[parent]) {
                swap(v[idx], v[parent]);
                heapifyUp(parent);
            }
        }
        else { // MinHeap
            if (v[idx] < v[parent]) {
                swap(v[idx], v[parent]);
                heapifyUp(parent);
            }
        }
    }

    // Hàm heapify-down (sau khi xóa root)
    void heapifyDown(int idx) {
        int left = idx * 2 + 1;
        int right = idx * 2 + 2;
        int target = idx;

        if (isMaxHeap) {
            if (left < v.size() && v[left] > v[target]) target = left;
            if (right < v.size() && v[right] > v[target]) target = right;
        }
        else {
            if (left < v.size() && v[left] < v[target]) target = left;
            if (right < v.size() && v[right] < v[target]) target = right;
        }

        if (target != idx) {
            swap(v[idx], v[target]);
            heapifyDown(target);
        }
    }

public:
    Heap(bool maxHeap = true) {
        isMaxHeap = maxHeap;
    }

    void insert(int key) {
        v.push_back(key);
        heapifyUp(v.size() - 1);
    }

    int top() {
        if (v.empty()) throw runtime_error("Heap is empty!");
        return v[0];
    }

    void pop() {
        if (v.empty()) throw runtime_error("Heap is empty!");
        v[0] = v.back();
        v.pop_back();
        if (!v.empty()) heapifyDown(0);
    }

    void display() {
        for (int x : v) cout << x << " ";
        cout << endl;
    }
};

int main() {
    cout << "=== Max Heap ===" << endl;
    Heap maxHeap(true);
    maxHeap.insert(30);
    maxHeap.insert(10);
    maxHeap.insert(50);
    maxHeap.insert(20);
    maxHeap.insert(40);
    maxHeap.display();
    cout << "Top = " << maxHeap.top() << endl;
    maxHeap.pop();
    maxHeap.display();

    cout << "\n=== Min Heap ===" << endl;
    Heap minHeap(false);
    minHeap.insert(30);
    minHeap.insert(10);
    minHeap.insert(50);
    minHeap.insert(20);
    minHeap.insert(40);
    minHeap.display();
    cout << "Top = " << minHeap.top() << endl;
    minHeap.pop();
    minHeap.display();

    return 0;
}
