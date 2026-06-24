#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& arr, string comment="") {
    cout << comment << endl;
    for (int x: arr) {
        cout << x << " ";
    }
    cout << endl;
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i=0; i < n1; ++i) {
        L[i] = arr[left+i];
    }
    for (int j=0; j < n2; ++j) {
        R[j] = arr[mid+1+j];
    }

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++; 
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Remainder
    while (i < n1) {
        arr[k] = L[i];
        i++; 
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    string comment = to_string(mid) + ":";
    print(arr, comment);
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        // int mid = left + (right - left) / 2; // overfloat
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = {80, 2, 5, 12, 24};
    
    int left = 0;
    int right = arr.size() - 1;
    mergeSort(arr, left, right);

    print(arr);

    return 0;
}