//
//  main.cpp
//  ArrayOfProducts
//
//  Created by Aniket Bhushan on 06/10/19.
//  Copyright © 2019 Aniket Bhushan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

typedef std::vector<int> vi;
typedef std::vector<long long> vll;

vll getArrayOfProduct(const vi& v)
{
    vll productArray;
    long long product {1};
    
    std::transform(v.begin(), v.end(), std::back_inserter(productArray),
                   [&product](int e){auto temp = product; product *= e; return temp;});
    
    product = 1;
    std::transform(v.rbegin(), v.rend(), productArray.rbegin(), productArray.rbegin(),
                   [&product](int e, long long e2){auto temp = product; product *= e; return temp*e2;});
    
    return productArray;
}

void print(const vll& v)
{
    for (const auto& n : v)
        std::cout << n << " ";
    std::cout << std::endl;
}

int main(int argc, const char * argv[]) {
    vi v{10, 3, 5, 6, 2};
    
    print(getArrayOfProduct(v));
    return 0;
}
