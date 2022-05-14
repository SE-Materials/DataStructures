#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int mod = 10000007;
int INF = 2000000000;
int findTotalPower(vector<int> power) {
    int n = power.size();
    stack<int> st;

    vector<int> left(n, 0);

    for (int i=0; i<n; i++) {
        while (!st.empty() && power[st.top()] > power[i]) {
            st.pop();
        }

        if (!st.empty()) {
            left[i] = left[st.top()] + (i - st.top())*power[i] ;
        } else {
            left[i] = (i + 1) * power[i];
        }
    }

    stack<int> st2;
    vector<int> right(n, 0);

    for (int i=n-1; i>=0; i--) {
        while (!st2.empty() && power[st2.top()] > power[i]) {
            st2.pop();
        }

        if (!st2.empty()) {
            right[i] = right[st2.top()] + (st2.top() - i)*power[i] ;
        } else {
            right[i] = (n - i) * power[i];
        }
    }

    vector<int> leftAcc, rightAcc;
    for (int i=0; i<n; i++) {
        leftAcc.push_back(leftAcc.empty() ? 0 : leftAcc.back() + left[i]);
        rightAcc.push_back(rightAcc.empty() ? 0 : rightAcc.back() + rightAcc[n - i - 1]);
    }

    int total = leftAcc.back();
    int ans = 0;

    for (int i=0; i<n; i++) {
        ans += (total - leftAcc[i] - rightAcc[n - i - 1])*power[i];
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    // vector<int> power {2, 3, 2, 1};
    vector<int> power {2, 1, 3};

    auto totalPower = findTotalPower(power);

    cout << totalPower << endl;
    
    return 0;
}