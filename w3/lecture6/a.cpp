#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s1, s2;
    cin >> s1 >> s2;
    string temp = s1;
    int i = n - 1;
    do {
        char x = temp[i];
        x = x - 'a' + 1;

        temp[i] = 

    } while (temp != s2);
    return 0;
}