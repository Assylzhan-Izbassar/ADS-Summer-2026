#include <iostream>
#include <vector>

using namespace std;

vector<int> rabinKarp(string& text, string& pattn) {
    const int p = 29;
    const int mod = 1e9;

    int n = pattn.size();
    int m = text.size();

    vector<long long> pPow(max(n, m));

    pPow[0] = 1;
    for (int i=1; i < pPow.size(); ++i) {
        pPow[i] = (pPow[i - 1] * p) % mod;
    }

    vector<long long> h(m + 1, 0);
    for (int i=0; i < m; ++i) {
        h[i+1] = (h[i] + (text[i] - 'a' + 1) * pPow[i]) % mod;
    }

    long long hashPattn = 0;

    for (int i=0; i < n; ++i) {
        hashPattn = (hashPattn  + (pattn[i] - 'a' + 1) * pPow[i]) % mod;
    }

    vector<int> occurance;

    for (int i=0; i < m - n + 1; ++i) {
        long long curr_h = (h[i+n] - h[i] + mod) % mod;

        if (curr_h == (hashPattn * pPow[i]) % mod) {
            occurance.push_back(i);
        }
    }

    for (int i=0; i < pPow.size(); ++i) {
        cout << pPow[i] << " ";
    }
    cout << endl;

    for (int i=0; i < h.size(); ++i) {
        cout << h[i] << " ";
    }
    cout << endl;

    cout << hashPattn << "\n";
    return occurance;
}

int main() {
    string text = "abcd";
    string pattn = "bc";

    vector<int> result = rabinKarp(text, pattn);

    for (int x: result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
