//
//  main.cpp
//  SecondMaxInArray
//
//  Created by Aniket Bhushan on 06/10/19.
//  Copyright © 2019 Aniket Bhushan. All rights reserved.
//

#include <iostream>
#include <vector>

typedef std::vector<int> vi;

int getSecondMax(const vi& v)
{
    int maxValue {std::numeric_limits<int>::min()}, secondMaxValue {std::numeric_limits<int>::min()};
    
    for (const auto& e : v)
    {
        if (e > maxValue)
        {
            secondMaxValue = std::max(maxValue, secondMaxValue);
            maxValue = e;
        }
        else if (e < maxValue && e > secondMaxValue)
        {
            secondMaxValue = std::max(e, secondMaxValue);
        }
    }

    return secondMaxValue;
}

int main(int argc, const char * argv[]) {
    vi v {12, 35, 1, 10, 34, 1};
    
    std::cout << getSecondMax(v) << std::endl;
    return 0;
}
