#include <iostream>

using namespace std;

const int N = 1000;

class Stack {
private:
    int* arr = new int[N];
    int topIdx;
    int currSize = N;
public:
    Stack() {
        topIdx = -1;
    }
    void push(int x) {
        topIdx++;
        arr[topIdx] = x;
    }
    int top() {
        return arr[topIdx];
    }
    int pop() {
        if (topIdx == -1) {
            return -1;
        }
        int topElem = arr[topIdx];
        arr[topIdx] = -1;
        topIdx--;
        return topElem;
    }
    int size() {
        return topIdx + 1;
    }
    void resize() {
        const int newSize = 2 * currSize;
        int* newArr = new int[newSize];
        for (int i=0; i <= topIdx; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        currSize = newSize;
        arr = newArr;
    }

    void print() {
        for (int i=0; i <= topIdx; ++i) {
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
};

int main() {
    Stack st = Stack();
    st.push(10);
    st.push(20);
    st.push(30);

    st.print();

    st.pop();
    cout << st.top() << endl;

    return 0;
}
