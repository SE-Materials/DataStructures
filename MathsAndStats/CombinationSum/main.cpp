//
//  main.cpp
//  CombinationSum
//
//  Created by Aniket Bhushan on 20/11/19.
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

void getCombination(int num, const std::vector<int>& v, int index, std::vector<int>& vi)
{    
    if (num == 0)
    {
        std::cout << vi << std::endl;
        return;
    }
    
    for (int i=index; i<v.size(); ++i)
    {
        if (v[i] > num)
        {
            break;
        }
        else
        {
            vi.push_back(v[i]);
            getCombination(num-v[i], v, i, vi);
            vi.pop_back();
        }
    }
}

void getCombinationWithoutRep(int num, const std::vector<int>& v, int index, std::vector<int>& vi)
{
    if (num == 0)
    {
        std::cout << vi << std::endl;
        return;
    }
    
    for (int i=index; i<v.size(); ++i)
    {
        if (v[i] > num)
        {
            break;
        }
        else
        {
            vi.push_back(v[i]);
            getCombinationWithoutRep(num-v[i], v, i+1, vi);
            vi.pop_back();
        }
    }
}

int main(int argc, const char * argv[])
{
    // Assuming v in increasing order
    std::vector<int> v {2, 3, 6, 7}; // 7
    std::vector<int> vi;
    getCombination(7, v, 0, vi);
    //    2 2 3
    //    7
    
    //    std::vector<int> v {2, 3, 6, 7}; // 7
    //    std::vector<int> vi;
    //    getCombinationWithoutRep(7, v, 0, vi);
    //    7
    
    //    std::vector<int> v {2, 3, 5}; // 7
    //    std::vector<int> vi;
    //    getCombination(8, v, 0, vi);
    //    2 2 2 2
    //    2 3 3
    //    3 5
    
    //    std::vector<int> v {2, 3, 5}; // 7
    //    std::vector<int> vi;
    //    getCombinationWithoutRep(8, v, 0, vi);
    //    3 5
    
    return 0;
}
