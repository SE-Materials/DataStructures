// https://labuladong.gitbook.io/algo-en/ii.-data-structure/monotonicstack#:~:text=Monotonic%20stack%20is%20actually%20a%20stack.%20It%20just,heap%3F%20No%2C%20monotonic%20stack%20is%20not%20widely%20used.

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        
        vector<int> ans(n, 0);
        
        for (int i=n-1; i>=0; i--) 
        {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i])
            {
                st.pop();
            }
            
            ans[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }
        
        return ans;
        
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        
        vector<int> ans (n, 0);
        int hottestTemp = 0;
        
        for (int i=n-1; i>=0; i--) 
        {
            int currTemp = temperatures[i];
            
            if (currTemp >= hottestTemp)
            {
                hottestTemp = currTemp;
                continue;
            }
            
            int days = 1;
            while (temperatures[i + days] <= currTemp) 
            {
                days = days + ans[i + days];
            }
            
            ans[i] = days;
        }
        
        return ans;
        
    }
};