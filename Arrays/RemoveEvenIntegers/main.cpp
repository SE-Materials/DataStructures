//
//  main.cpp
//  RemoveEvenIntegers
//
//  Created by Aniket Bhushan on 03/10/19.
//  Copyright © 2019 Aniket Bhushan. All rights reserved.
//

#include <iostream>
#include <vector>

typedef std::vector<int> vi;

void print(const vi& v)
{
    for (const auto& e : v)
        std::cout << e << " ";
    std::cout << std::endl;
}

void removeEvenNumber(vi& v)
{
    int first {-1};
    
    int i {0};
    while (i < v.size())
    {
        if (v.at(i)%2 != 0)
            std::swap(v[++first], v[i]);
        ++i;
    }
    v.erase(v.begin()+first+1, v.end());
}

int main(int argc, const char * argv[]) {
    vi v {2};
    removeEvenNumber(v);
    
    print(v);
    return 0;
}
