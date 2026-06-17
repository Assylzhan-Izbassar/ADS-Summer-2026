#include <iostream>

using namespace std;

int calculate(string s) {
    string expressions = "+-*/";
    stack<string> st;
    string num = "";
    string doOper = "";

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            s.erase(s.begin() + i);
            i--;
        }
    }

    for (int i=0; i < s.size(); ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            num += s[i];
        }
        if (i == s.size() - 1 || expressions.find(s[i]) != string::npos) {
            if (doOper.size() != 0) {
                int x = stoi(st.top());
                st.pop();
                if (doOper == "*") {
                    x *= stoi(num);
                } else if (doOper == "/") {
                    x /= stoi(num);
                }
                st.push(to_string(x));
                doOper = "";
            } else {
                st.push(num);
            }
            if (s[i] == '*' || s[i] == '/') {
                doOper += s[i];
            } else if (s[i] == '+' || s[i] == '-') {
                string op(1, s[i]);
                st.push(op);
            }
            num="";
        }
    }
    
    int result = 0;

    while(!st.empty()) {
        // cout << st.top() << endl;
        // st.pop();
        int x = stoi(st.top()); st.pop();
        if (!st.empty()) {
            string oper = st.top(); st.pop();
            int y = stoi(st.top()); st.pop();
            if (oper == "+") {
                st.push(to_string(x + y));
            } else {
                st.push(to_string(y - x));
            }
        } else {
            result = x;
        }
    }

    return result;
}

int main() {
    string s = "1+1+1";
    cout << calculate(s) << endl;

    return 0;
}
