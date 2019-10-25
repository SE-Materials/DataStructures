//
//  main.cpp
//  RearrangePositionAndNegative
//
//  Created by Aniket Bhushan on 06/10/19.
//  Copyright © 2019 Aniket Bhushan. All rights reserved.
//

#include <iostream>
#include <vector>

typedef std::vector<int> vi;

void separatePositiveAndNegative(vi& v)
{
    int neg {}, pos {};
    for (auto n : v)
        if (n < 0)
            pos++;
    
    for (int i=0; i<v.size(); ++i)
    {
        if (v[i] < 0)
        {
            std::swap(v[i], v[neg++]);
        }
        else
        {
            std::swap(v[i], v[pos++]);
        }
    }
}

void print(const vi& v)
{
    for (const auto& e : v)
        std::cout << e << " ";
    std::cout << std::endl;
}

int main(int argc, const char * argv[]) {
    vi v {12, 11, -13, -5, 6, -7, 5, -3, -6};
    
    separatePositiveAndNegative(v);
    print(v);
    return 0;
}
