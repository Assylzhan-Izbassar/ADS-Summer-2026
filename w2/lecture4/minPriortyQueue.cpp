#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct CustomLess {
    bool operator()(const pair<int, int>& l, const pair<int, int>& r) {
        if (l.first == r.first) {
            return l.second > r.second;
        } 
        return l.first > r.first;
    }
};

int main() {
    // priority_queue<
    //     pair<int, int>,
    //     vector<pair<int, int>>,
    //     greater<pair<int, int>>> pq;
    vector<int> v = {4, 4, 6, 10, 1};

    priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    CustomLess> pq;
    
    for (int i=0; i < 5; ++i) {
        pq.push({v[i], i});
    }

    for (int i=0; i < 5; ++i) {
        pair<int, int> top = pq.top();
        cout << top.first << " " << top.second << endl;
        pq.pop();
    }
    

    return 0;
}