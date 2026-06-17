#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void print(vector<int>& nums) {
    for (int i=0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

long long gcdSum(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefixGcd(n, 0);
    
    int mx = nums[0];

    for (int i=0; i < n; ++i) {
        mx = max(mx, nums[i]);
        prefixGcd[i] = gcd(mx, nums[i]);
    }
    sort(prefixGcd.begin(), prefixGcd.end());

    print(prefixGcd);

    long long result = 0;

    for (int i=0; i < n / 2; ++i) {
        result += gcd(prefixGcd[i], prefixGcd[n-1-i]);
    }
    return result;
}

int main() {
    vector<int> nums = {3,6,2,8};
    cout << gcdSum(nums) << "\n";
    return 0;
}