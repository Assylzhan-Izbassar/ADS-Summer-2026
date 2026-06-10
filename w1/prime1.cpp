#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;

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

    for (int i=0; i < factors.size(); ++i) {
        cout << factors[i] << " ";
    }
    cout << endl;

    return 0;
}