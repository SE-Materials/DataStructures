//
//  main.cpp
//  FirstUniqueIntegerInArray
//
//  Created by Aniket Bhushan on 06/10/19.
//  Copyright © 2019 Aniket Bhushan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

typedef std::vector<int> vi;
typedef std::unordered_map<int, int> numberToFrequencyMap;

int main()
{
    vi v {1, 1, 3, 8, 9, 0, 3, 9};
    numberToFrequencyMap mp;
    
    for (const auto& e : v)
        mp[e]++;
    
    bool found = false;
    for (const auto& e : v)
    {
        auto iter = mp.find(e);
        if (iter->second == 1)
        {
            std::cout << iter->first << std::endl;
            found = true;
            break;
        }
    }
    
    //    for (const auto& p : mp)
    //    {
    //        if (p.second == 1)
    //        {
    //            std::cout << p.first << std::endl;
    //            found = true;
    //            break;
    //        }
    //    }
    if (!found)
        std::cout << "No unique elements found" << std::endl;
    
    return 0;
}
