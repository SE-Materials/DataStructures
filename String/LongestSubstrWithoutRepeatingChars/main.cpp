// https://leetcode.com/explore/interview/card/google/59/array-and-strings/3047/

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstringSol1(string s)
    {
        std::bitset<128> visited;

        int n = s.size();
        int maxlen = 0;
        int curlen = 0;
        int start = 0;

        for (int i = 0; i < n; i++)
        {
            char c = s[i];

            // cout << c << " : ";

            if (visited[c] == 1)
            {
                while (visited[c] == 1)
                    visited[s[start++]] = 0;

                curlen = i - start;
            }

            visited[c] = 1;
            curlen++;
            maxlen = max(maxlen, curlen);

            // cout << curlen << endl;
        }

        return maxlen;
    }

    int lengthOfLongestSubstring(string s) {
        
        int visited[128];
        memset(visited, -1, 128*sizeof(int));
        
        int n      = s.size();
        int maxlen = 0;
        int start  = 0;
        
        for (int i=0; i<n; i++) 
        {
            char c = s[i];
            
            if (visited[c] != -1 && visited[c] >= start) 
                start = visited[c] + 1;

            visited[c] = i;
            maxlen = max(maxlen, i - start + 1); 
        }
        
        return maxlen;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string s = "abcabcbb";

    cout << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}
