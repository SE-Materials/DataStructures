//
//  main.cpp
//  RemoveDuplicates
//
//  Created by Aniket Bhushan on 23/11/19.
//  Copyright © 2019 Aniket Bhushan. All rights reserved.
//

#include <iostream>
#include <unordered_set>

void removeDuplicates(std::string& str)
{
    std::unordered_set<char> map;
    
    int j=0;
    for (int i=0; i<str.size(); ++i)
    {
        auto iter = map.find(str[i]);
        if (iter == map.end())
        {
            map.insert(str[i]);
            str[j] = str[i];
            j++;
        }
    }
    
    str = str.substr(0, j);
}

void removeDuplicatesConstSpace(std::string& str)
{
    // Use bits
    int count = 0;
    
    int j = 0;
    for (int i=0; i<str.size(); ++i)
    {
        // Get ith bit
        bool isThere = count & (1<< (str[i]-'a')) != 0;
        if (isThere)
        {
            count = count | (1 << (str[i] - 'a'));
            str[j] = str[i];
            j++;
        }
    }
}

int main(int argc, const char * argv[]) {
    std::string str {"geeksforgeeks"};
    removeDuplicates(str);
    
    std::string str2 = str;
    removeDuplicatesConstSpace(str2);
    
    std::cout << str << std::endl;
    std::cout << str2 << std::endl;
    return 0;
}
