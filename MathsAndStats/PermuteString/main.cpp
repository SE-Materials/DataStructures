//
//  main.cpp
//  PermuteString
//
//  Created by Aniket Bhushan on 17/11/19.
//  Copyright © 2019 Aniket Bhushan. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_set>

//std::ostream& operator<<(std::ostream& os, const std::vector<std::string>& other)
//{
//    for (auto& s : other)
//        os << s << " ";
//    return os;
//}

std::unordered_set<std::string> st;

void recursive(std::string rem, std::string str)
{
    if (rem.empty())
    {
        auto iter = st.find(str);
        if (iter == st.end())
        {
            st.insert(str);
            std::cout << str << " ";
        }
    }
    
    for (int i=0; i<rem.size(); ++i)
        recursive(rem.substr(0, i) + rem.substr(i+1), str + rem[i]);
}

void stlPermutation(std::string& str)
{
    do
    {
        std::cout << str <<  " ";
    }
    while (std::next_permutation(str.begin(), str.end()));
}

void printAllPermutations(const std::string& str)
{
    recursive(str, "");
    std::cout << std::endl;
    
    std::string nstr = str;
    stlPermutation(nstr);
}

int main(int argc, const char * argv[]) {
    std::string str("ABCA");
    std::sort(str.begin(), str.end());
    printAllPermutations(str);
    
    return 0;
}
