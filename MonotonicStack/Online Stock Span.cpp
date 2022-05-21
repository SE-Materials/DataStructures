class StockSpanner {
    vector<int> prices, ans;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        prices.push_back(price);
        
        if (prices.size() > 1)
        {
            int n = prices.size();
            
            int ndays = 1;
            while (n - 1 - ndays >= 0 && prices[n -1 - ndays] <= price)
            {
                ndays += ans[n - 1 - ndays];
            }
            
            ans.push_back(ndays);
        }
        else 
            ans.push_back(1);
        
        return ans.back();
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

#include <iostream>
#include <stack>

using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> st;
    
    StockSpanner() {
        ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    }
    
    int next(int price) {
        int count = 1;
        while(!st.empty() && st.top().first <= price)
        {
            count += st.top().second;
            st.pop();
        }
        st.push({price, count});

        return count;
    }
};