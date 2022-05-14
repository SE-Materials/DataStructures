#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

template <typename T>
std::ostream& operator<<(std::ostream& os, const vector<T>& vec) {
    for (auto e : vec) 
        os << e << " ";
    os << endl;
    return os;
}

class Solution {
public:
    vector<int> findSubstring(string A, const vector<string> &B);
};

vector<int> Solution::findSubstring(string A, const vector<string> &B) 
{
    unordered_map<string, int> words;
    for(auto b : B) 
        words[b]++;
    
    int numWords = B.size();
    int l = B[0].size();
    int n = A.size();
    vector<int> ans;

    for (int i=0; i < n - l*numWords + 1;) 
    {
        auto currWord = A.substr(i, l);
        if (words.count(currWord) > 0) 
        {
            unordered_map<string, int> wordsToFreq;
            int nWords = numWords;
            int start  = i;
            
            while(nWords) 
            {
                if (words.count(currWord) == 0 || wordsToFreq[currWord] >= words[currWord])
                {
                    break;
                }
                else
                {
                    wordsToFreq[currWord]++;
                    nWords--;
                }
                i = i + l;
                currWord = A.substr(i, l);
            }

            if (nWords == 0)
                ans.push_back(start);

            i = start + 1;
        } 
        else {
            i = i + 1;
        }
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    Solution sol;
    auto ans = sol.findSubstring("barfoothefoobarman", {"foo", "bar"});

    // string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    // vector<string> strs = {"aaa", "aaa", "aaa", "aaa", "aaa"};
    // auto ans = sol.findSubstring(str, strs);

    // string str = "abbaccaaabcabbbccbabbccabbacabcacbbaabbbbbaaabaccaacbccabcbababbbabccabacbbcabbaacaccccbaabcabaabaaaabcaabcacabaa";
    // vector<string> strs = {"cac", "aaa", "aba", "aab", "abc"};
    // auto ans = sol.findSubstring(str, strs); // expected: 97

    std::cout << ans << std::endl;
    return 0;
}
