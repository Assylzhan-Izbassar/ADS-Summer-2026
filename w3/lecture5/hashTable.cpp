#include <iostream>
#include <vector>
#include <list>

using namespace std;

class HashTable {
private:
    int capacity;
    vector<list<pair<int, string>>> table;

    int hash(int key) {
        return key % capacity;
    }
public:
    HashTable(int capacity) {
        this->capacity = capacity;

        for (int i=0; i < capacity; ++i) {
            list<pair<int, string>> a;
            table.push_back(a);
        }
    }

    void insert(int x, string fruit) {
        int hash = this->hash(x);
        table[hash].push_back({x, fruit});
    }

    list<pair<int, string>> find(int x) { // find the fruits where the count is equal to x;
        return table[hash(x)];
    }
};

int main() {
    HashTable ht = HashTable(10);
    ht.insert(0, "orange");
    ht.insert(5, "apple");
    ht.insert(5, "banana");
    ht.insert(10, "kiwi");
    ht.insert(7, "cherry");
    
    for (pair<int, string> x: ht.find(10)) {
        cout << x.second << ", ";
    }
    return 0;
}