#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string braces;
    cin >> braces;

    stack<char> s;

    string openned = "({[";

    for (int i=0; i < braces.size(); ++i) {
        if (openned.find(braces[i]) != string::npos || s.empty()) {
            s.push(braces[i]);
        } else {
            char c = s.top();
            
            if ((c == '(' && braces[i] == ')') || (c == '[' && braces[i] == ']') || (c == '{' && braces[i] == '}')) {
                s.pop();
            }
        }
    }

    if (s.empty()) {
        cout << "VALID!\n";
    } else {
        cout << "NOT VALID!\n";
    }

    return 0;
}