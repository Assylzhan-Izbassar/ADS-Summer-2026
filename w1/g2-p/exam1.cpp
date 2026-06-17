#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    int sumOdd = 0, sumEven = 0;

    for (int i=1; i <= 2 * n; ++i) {
        if (i % 2 == 0) {
            sumEven += i; 
        } else {
            sumOdd += i;
        }
    }

    cout << sumEven << " " << sumOdd << endl;

    cout << gcd(sumEven, sumOdd) << endl;
    return 0;
}