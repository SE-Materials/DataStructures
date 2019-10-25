//
//  main.cpp
//  TwoNumbersThatAddToValue
//
//  Created by Aniket Bhushan on 06/10/19.
//  Copyright © 2019 Aniket Bhushan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

typedef std::vector<int> vi;

void findTwoNumbers(const vi& v, int sum)
{
    std::unordered_set<int> seenValues;
    for (const auto& k : v)
    {
        auto iter = seenValues.find(sum-k);
        if (iter != seenValues.end())
            std::cout << k << ", " << sum-k << std::endl;
        seenValues.insert(k);
    }
}

int main(int argc, const char * argv[]) {
    vi v {80, 98, 83, 92, 1, 38, 37, 54, 58, 89};
    int sum {181};
    
    findTwoNumbers(v, sum);
    return 0;
}
