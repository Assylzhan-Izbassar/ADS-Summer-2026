#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

vector<int> primeFactors(int n) {
    int temp = n;
    vector<int> factors;

    for (int i=2; i < n; ++i) {
        while (temp % i == 0) {
            temp /= i;
            factors.push_back(i);
        }
        if (temp == 0) {
            break;
        }
    }

    return factors;
}

void print(vector<int> numbers) {
    for (int i=0; i < numbers.size(); ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

vector<int> getIntersection(vector<int> v1, vector<int> v2) {
    // v1 size is always less than v2 size;
    vector<int> intersection;
    
    int i = 0;
    for (int j=0; j < v1.size(); ++j) {
        if (i < v2.size() && v1[j] == v2[i]) {
            intersection.push_back(v1[j]);
            i++;
            continue;
        }
        if ((v1[j] > v2[i] && i + 1 < v2.size())) {
            i++;
            j--;
        }
    } 

    return intersection;
}

int main() {
    int x1, x2;
    cin >> x1 >> x2;

    vector<int> f1 = primeFactors(x1);
    vector<int> f2 = primeFactors(x2);
    vector<int> inter;

    if (f1.size() < f2.size()) {
        inter = getIntersection(f1, f2);
    } else {
        inter = getIntersection(f2, f1);
    }

    // print(f1);
    // print(f2);

    long long result = 1;
    for (int i=0; i < inter.size(); ++i) {
        result *= inter[i];
    }
    cout << "brute: " <<  result << endl;

    cout << "euclid: " << gcd(x1, x2) << endl;

    return 0;
}