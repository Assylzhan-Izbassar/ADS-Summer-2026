#include <iostream>

using namespace std;

class MinHeap {
private:
    vector<int> heap;
    int parent(int i) {
        return (i - 1) / 2;
    }
    int leftChild(int i) {
        return 2 * i + 1;
    }
    int rightChild(int i) {
        return 2 * i + 2;
    }
    void heapifyUp(int i) {
        while (i > 0) {
            int parent = this->parent(i);
            if (heap[i] < heap[parent]) {
                swap(heap[i], heap[parent]);
                i = parent;
            } else {
                break;
            }
        }
    }
    void heapifyDown(int i) {
        int n = this->heap.size();
        while (true) {
            int left = this->leftChild(i);
            int right = this->rightChild(i);
            int largestIdx = i;

            if (left < n && heap[left] < heap[largestIdx]) {
                largestIdx = left;
            }
            if (right < n && heap[right] < heap[largestIdx]) {
                largestIdx = right;
            }
            if (largestIdx != i) {
                swap(heap[i], heap[largestIdx]);
                i = largestIdx;
            } else {
                break;
            }
        }
    }
public:
    void insert(int x) {
        heap.push_back(x);
        int i = heap.size() - 1;
        heapifyUp(i);
    }
    int getMax() {
        return this->heap[0];
    }
    int extractTop() {
        int x = this->heap[0];
        int n = heap.size();
        swap(heap[0], heap[n-1]);
        this->heap.pop_back();
        heapifyDown(0);
        return x;
    }
    void print() {
        for (int i=0; i < heap.size(); ++i) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    vector<int> sort() {
        vector<int> result;
        vector<int> copiedHeap(heap);
        int n = heap.size();
        for (int i=0; i < n; ++i) {
            result.push_back(this->extractTop());
        }
        this->heap = copiedHeap;
        return result;
    }
};

int main() {
    vector<int> data = {5, 21, 12, 52, 765, 1};

    MinHeap mh = MinHeap(); 

    for (int x: data) {
        mh.insert(x);
    }
    cout << "sorted:\n";
    for (int x: mh.sort()) {
        cout << x << " ";
    }
    cout << endl;
    mh.print();


    return 0;
}