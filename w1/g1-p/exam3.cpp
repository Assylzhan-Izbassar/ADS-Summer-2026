#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> x) {
    for (int i=0; i < x.size(); ++i) {
        cout << x[i] << " ";
    }
    cout << endl;
}

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    deque<int> unabled;
    while (!sandwiches.empty()) {
        if (students.empty()) {
            break;
        }
        if (students[0] == sandwiches[0]) {
            students.erase(students.begin());
            sandwiches.erase(sandwiches.begin());
        } else {
            unabled.push_back(students[0]);
            students.erase(students.begin());
        }
    }
    cout << unabled.size() << endl;
    cout << sandwiches.size() << endl;
    int operCnt = 0;
    while (!unabled.empty() && operCnt <= unabled.size()) {
        int student = unabled.front();
        if (student == sandwiches[0]) {
            sandwiches.erase(sandwiches.begin());
            unabled.pop_front();
            operCnt = 0;
        } else {
            unabled.push_back(student);
            unabled.pop_front();
            operCnt++;
        }
    }

    return unabled.size();
}

int main() {
    vector<int> students = {0,0,0,1,1,1,1,0,0,0};
    vector<int> sandwiches = {1,0,1,0,0,1,1,0,0,0};
    
    cout << countStudents(students, sandwiches) << endl;
    
    return 0;
}
