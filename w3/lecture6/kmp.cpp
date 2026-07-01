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

vector<int> kmp(string& text, string& patt) {
    vector<int> lps = getLPS(patt);
    vector<int> result;

    int n = text.size();
    int m = patt.size();

    int i = 0;
    int j = 0;

    while (i < n) {
        if (text[i] == patt[j]) {
            i++;
            j++;

            if (j == m) {
                result.push_back(i - j);
                j = lps[j-1];
            }
        } else {
            if (j == 0) {
                i++;
            } else {
                j = lps[j-1];
            }
        }
    }

    return result;
}

int main() {
    string text = "algorithm";

    string binary = "011000010110110001100111011011110111001001101001011101000110100001101101";
    string patt = "0110011101101111";

    vector<int> lps = kmp(binary, patt);

    for (int x: lps) {
        cout << x << " "; 
    }
    cout << endl;

    return 0;
}