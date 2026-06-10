#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

// Algorithm 2 - Eratosthenes: O(n * log(log(n)))
vector<bool> collectPrimes2(int n) {
    vector<bool> isPrimes(n+1, true);
    
    isPrimes[0] = isPrimes[1] = false;
    for (int i=2; i <= n; ++i) {
        if (isPrimes[i]) {
            // Validation for prime number
            if (i * i * 1ll <= n) {
                for (int j = i * i; j <= n; j += i) {
                    isPrimes[j] = false;
                }
            }
        }
    }
    // vector<int> primes;
    // for (int i=0; i < isPrimes.size(); ++i) {
    //     if (isPrimes[i]) primes.push_back(i);
    // }
    return isPrimes;
}

// Algorithm 1: O(n * sqrt(n))
bool isPrime(int x){
    for (int i=2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

vector<int> collectPrimes(int n) {
    vector<int> primes;
    for (int i=2; i <= n; ++i) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main() {
    int n;
    cin >> n;

    clock_t start = clock();

    vector<bool> primes = collectPrimes2(n);

    clock_t end = clock();

    cout << end - start << " ms\n";

    // for (int i=0; i < primes.size(); ++i) {
    //     cout << primes[i] << " ";
    // }
    // cout << endl;

    cout << primes.size() << endl;

    return 0;
}