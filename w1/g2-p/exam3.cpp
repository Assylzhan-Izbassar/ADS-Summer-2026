#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int>& nums) {
    for (int i=0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

vector<int> primes(int n) {
    vector<bool> p(n+1, true);
    p[0] = p[1] = false;

    for (int i=2; i <= n; ++i) {
        if (p[i]) {
            if (i * 1ll * i <= n) {
                for (int j=i*i; j <= n; j += i) {
                    p[j] = false;
                }
            }
        }
    }
    vector<int> result;
    for (int i=0; i < p.size(); ++i) {
        if (p[i]) {
            result.push_back(i); 
        }
    }
    return result;
}

int permute(vector<int>& primes, vector<int>& nums, int idx, int size, int cnt) {
    if (idx == size - 1) {
        cout << cnt << " ";
        print(nums);
        for (int i=0; i < nums.size(); ++i) {
            if (find(primes.begin(), primes.end(), nums[i]) != primes.end() && find(primes.begin(), primes.end(), i+1) == primes.end()) {
                //false;
            }
        }
        return cnt + 1;
    }
    for (int i=idx; i < size; ++i) {
        swap(nums[idx], nums[i]);
        cnt = permute(primes, nums, idx + 1, size, cnt);
        swap(nums[idx], nums[i]);
    }
    return cnt;
}

int numPrimeArrangements(int n) {
    vector<int> nums(n, 0);
    for (int i=1; i <= n; ++i) {
        nums[i-1] = i;
    }

    vector<int> p = primes(n);

    cout << p.size() << endl;
    return 0;

    long long result = 0;
    long long mod = 1e9 + 7;
    do {
        bool marker = true;
        for (int i=0; i < nums.size(); ++i) {
            if (find(p.begin(), p.end(), nums[i]) != p.end() && find(p.begin(), p.end(), i+1) == p.end()) {
                marker = false;
                break;
            }
        }
        if (marker) {
            result = (result + 1) % mod;
        }
    } while(next_permutation(nums.begin(), nums.end()));

    return result;
}


int main() {
    cout << numPrimeArrangements(5) << endl;

    return 0;
}