//
//  main.cpp
//  PythagoreanTriplets
//
//  Created by Aniket Bhushan on 17/11/19.
//  Copyright © 2019 Aniket Bhushan. All rights reserved.
//

// This problem is same as unique triplets with given sum !!
// Finding all pythagorean triplets in an array!

#include <iostream>
#include <vector>
#include <unordered_map>
//#include <algorithm>

typedef std::vector<std::vector<int>> vvi;

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v)
{
    for (auto& e : v)
        os << e << " ";
    os << std::endl;
    return os;
}

std::ostream& operator<<(std::ostream& os, const vvi& vv)
{
    for (auto& v : vv)
        os << v;
    return os;
}

// There are two ways, hashing and l-r pointer.
// Going with l-r pointer, but this needs sorting !
vvi findAllPythagoreanTriplets(const std::vector<int>& v)
{
    // Best sort first
    std::vector<int> vi(v);
    
    std::sort(vi.begin(), vi.end());
    vvi ans;
    
    for (int i=0; i<v.size()-2; ++i)
    {
        int aa = vi[i]*vi[i];
        std::unordered_map<int,int> s;
        
        for (int j=i+1; j<v.size(); ++j)
        {
            int cc = vi[j]*vi[j];
            
            auto iter = s.find(cc-aa);
            if (iter == s.end())
            {
                s.insert(std::make_pair(cc, j));
            }
            else
            {
                ans.push_back({vi[i], vi[iter->second], vi[j]});
            }
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    std::vector<int> v {10, 4, 6, 12, 5};
    
    auto ans = findAllPythagoreanTriplets(v);
    
    std::cout << ans << std::endl;
    return 0;
}
