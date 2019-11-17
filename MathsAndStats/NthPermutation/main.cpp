//
//  main.cpp
//  NthPermutation
//
//  Created by Aniket Bhushan on 17/11/19.
//  Copyright © 2019 Aniket Bhushan. All rights reserved.
//

#include <iostream>
#include <string>

long long factorial(int num)
{
    return (num == 0 || num == 1) ? 1 : num*factorial(num-1);
}

// Assuming str is in sorted order
std::string getKthPermutation(const std::string& str, int k)
{
    std::string dest{};
    std::string source = str;
    
    long long f = factorial(str.size());
    while (!source.empty())
    {
        f = f/source.size();
        
        dest.push_back(source[k/f]);
        source.erase(source.begin()+k/f);
        k = k%f;
    }
    return dest;
}

int main(int argc, const char * argv[]) {
    std::string str {"12345"};
    
    auto numPermutations = factorial(str.size());
    for (int i=0; i<numPermutations; ++i) {
        std::cout << getKthPermutation(str, i) << std::endl;
    }
    
    return 0;
}
