#include <iostream>
#include <ctime>

using namespace std;

void print(int* arr, int n) {
    for (int i=0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int binarySearch(int *arr, int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        // int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}

int upperBinarySearch(int *arr, int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        // int mid = left + (right - left) / 2;
        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left - 1;
}

int lowerBinarySearch(int *arr, int n, int target) {
    int left = 0;
    int right = n;

    while (left < right) {
        int mid = (left + right) / 2;
        // int mid = left + (right - left) / 2;
        if (arr[mid] >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {

    int arr[] = {2, 7, 10, 12, 12, 12, 15, 20, 20, 20, 20};
    int n = sizeof(arr) / sizeof(int);

    cout << n << endl;

    print(arr, n);

    clock_t start = clock();
    int idx = lowerBinarySearch(arr, n, 12);
    clock_t end = clock();
    cout << end - start << " ms" << endl;

    cout << idx << endl;

    return 0;
}