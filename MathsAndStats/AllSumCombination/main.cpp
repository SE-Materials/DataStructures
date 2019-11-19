//
//  main.cpp
//  AllSumCombination
//
//  Created by Aniket Bhushan on 17/11/19.
//  Copyright © 2019 Aniket Bhushan. All rights reserved.
//

#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v)
{
    for (const auto& e : v)
        os << e << " ";
    return os;
}

void getAllCombinations(int num, std::vector<int>& v)
{
    if (num == 0)
    {
        std::cout << v << std::endl;
        return;
    }
    
    int start = v.empty() ? 1 : v.back();
    
    for (int i = start; i<=num; i++) {
        v.push_back(i);
        getAllCombinations(num-i, v);
        v.pop_back();
    }
}

void getAllDifferentCombinations(int num, std::vector<int>& v)
{
    if (num == 0)
    {
        std::cout << v << std::endl;
        return;
    }
    
    int start = v.empty() ? 1 : v.back()+1;
    
    for (int i = start; i<=num; i++) {
        v.push_back(i);
        getAllDifferentCombinations(num-i, v);
        v.pop_back();
    }
}

int main(int argc, const char * argv[])
{
    std::vector<int> v {};
    getAllCombinations(5, v);
    
    std::cout << std::endl;
    getAllDifferentCombinations(5, v);
    
    return 0;
}
