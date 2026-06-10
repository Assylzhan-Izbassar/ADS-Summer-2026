#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Stack {
private:
    int arr[1000];
    int i;

public:
    Stack() {
        i = 0;
    }
    void push(int x) {
        arr[1000 - 1 - i] = x;
    }
};

int main() {
    string braces;
    cin >> braces;

    stack<char> s;

    string openned = "({[";

    for (int i=0; i < braces.size(); ++i) {
        if (openned.find(braces[i]) != string::npos) {
            cout << "here\n";
            s.push(braces[i]);
        } else {
            cout << "not\n";
            char c = s.top();
            cout << c << " " << braces[i] << endl;
            
            if (c == braces[i]) {
                cout << "removed\n";
                s.pop();
            }
        }
    }

    cout << s.size() << "\n";

    if (s.empty()) {
        cout << "VALID!\n";
    } else {
        cout << "NOT VALID!\n";
    }

    return 0;
}