#include <iostream>
#include <vector>

using namespace std;

vector<int> getLPS(string& patt) {
    int n = patt.size();
    vector<int> lps(n, 0);

    int len = 0;
    int i = 1;

    while (i < n) {
        if (patt[i] == patt[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len == 0) {
                lps[i] = 0;
                i++;
            } else {
                len = lps[len-1];
            }
        }
    }
    return lps;
}

int main() {
    string s = "ababaa";

    vector<int> lps = getLPS(s);

    for (int x: lps) {
        cout << x << " "; 
    }
    cout << endl;

    return 0;
}