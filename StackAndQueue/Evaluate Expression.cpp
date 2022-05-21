#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {

public:
    int evalRPN(vector<string>& A);
};

int Solution::evalRPN(vector<string> &A) {

    stack<string> st;

    for (auto token : A)
    {
        if (token == "+" || token == "-" || token == "/" || token == "*") {
            int val2 = stoi(st.top()); st.pop();
            int val1 = stoi(st.top()); st.pop();

            if (token == "+") {
                st.push(to_string(val1 + val2));
            }
            else if (token == "-") {
                st.push(to_string(val1 - val2));
            }
            else if (token == "/") {
                st.push(to_string(val1 / val2));
            }
            else if (token == "*") {
                st.push(to_string(val1 * val2));
            }
        }
        else
            st.push(token);
    }
    return stoi(st.top());
}

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<string> expression {"9", "5", "1", "2", "+", "4", "*", "+", "3", "-"};

    cout << sol.evalRPN(expression) << endl;
    return 0;
}
