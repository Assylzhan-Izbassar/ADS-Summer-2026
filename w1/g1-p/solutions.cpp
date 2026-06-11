#include <iostream>

using namespace std;

// TASK 1:
class Task1 {
private:
    int oneCount(int n) {
        int result = 0;
        while (n > 0) {
            result += n % 2;
            n /= 2;
        }
        return result;
    }

    bool isPrime(int n) {
        if (n == 0 || n == 1) {
            return false;
        }
        for (int i=2; i * i <= n; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
public:
    int countPrimeSetBits(int left, int right) {
        int result = 0;
        for (int x=left; x <= right; ++x) {
            if (isPrime(oneCount(x))) {
                result++;
            }
        }
        return result;
    }
};

// TASK 2:
class Task2 {    
public:
    int countPrimes(int n) {
        vector<bool> primes(n+1, true);
        primes[0] = primes[1] = false;

        for (int i=2; i < n; ++i) {
            if (primes[i]) {
                if (i * 1ll * i < n) {
                    for (int j = i * i; j <= n; j += i) {
                        primes[j] = false;
                    }
                }
            }
        }
        primes[n] = false;
        int result = 0;
        for (int i=0; i < primes.size(); ++i) {
            if (primes[i]) {
                result++;
            }
        }
        return result;
    }
};

// TASK 3:
class Task3 {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        string valid = "+DC";
        for (int i=0; i < operations.size(); ++i) {
            if (valid.find(operations[i]) == string::npos) {
                int decimal = stoi(operations[i]); 
                st.push(decimal);
            } else {
                if (operations[i] == "+") {
                    int first = st.top();
                    st.pop();
                    int second = st.top();
                    int newResult = first + second;
                    
                    st.push(first);
                    st.push(newResult);
                } else if (operations[i] == "D") {
                    int top = st.top();
                    st.push(2 * top);
                } else {
                    st.pop();
                }
            }
        }
        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};

// TASK 4:
class Task4 {
public:
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
        int operCnt = 0;
        while (!unabled.empty() && operCnt <= unabled.size()) {
            if (sandwiches.empty()) break;

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
};

int main() {
    return 0;
}