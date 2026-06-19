#include <iostream>

using namespace std;

void print(vector<int>& arr) {
    for (int x: arr) {
        cout << x << " ";
    }
    cout << endl;
}

int partition(vector<int>& arr, int left, int right) {
    // int mid = left + (right - left) / 2;
    int pivot = arr[right];
    int i = left - 1;

    for (int j=left; j <= right - 1; ++j) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[right]);
    print(arr);
    return i+1; 
}

void quickSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int pIdx = partition(arr, left, right);
        cout << pIdx << endl;
        quickSort(arr, left, pIdx - 1);
        quickSort(arr, pIdx + 1, right);
    }
}

int main() {
    vector<int> arr = {2, 5, 6, 1, 10, 7};
    int n = arr.size(); 
    quickSort(arr, 0, n-1);

    print(arr);
    return 0;
}