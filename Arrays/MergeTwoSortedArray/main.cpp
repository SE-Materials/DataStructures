//
//  main.cpp
//  MergeTwoSortedArray
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

vi mergeTwoVector(const vi& v1, const vi& v2)
{
    vi result;
    result.reserve(v1.size()+v2.size());
    
    auto iter1 = v1.begin(), iter2 = v2.begin();
    
    while (iter1 != v1.end() && iter2 != v2.end())
    {
        if (*iter1 < *iter2)
        {
            result.push_back(*iter1);
            ++iter1;
        }
        else
        {
            result.push_back(*iter2);
            ++iter2;
        }
    }
    
    while (iter1 != v1.end())
    {
        result.push_back(*iter1);
        ++iter1;
    }
    
    while (iter2 != v2.end())
    {
        result.push_back(*iter2);
        ++iter2;
    }
    
//    result.insert(result.end(), v1.begin(), v1.end());
//    result.insert(result.end(), v2.begin(), v2.end());
    return result;
}

int main(int argc, const char * argv[]) {
    vi v1 {};
    vi v2 {1, 3, 5, 6, 8};
    vi v {};
    
    v = mergeTwoVector(v1, v2);
    print(v);
    
    return 0;
}
