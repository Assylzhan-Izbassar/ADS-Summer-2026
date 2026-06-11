#include <iostream>

using namespace std;

int oneCount(int n) {
    int result = 0;
    while (n > 0) {
        result += n % 2;
        n /= 2;
    }
    return result;
}

bool isPrime(int n) {
    if (n == 0 || n == 1) {
        return false;
    }
    for (int i=2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    // int n;
    // cin >> n;

    for (int i=6; i <= 10; ++i) {
        cout << oneCount(i) << endl;
    }


    return 0;
}