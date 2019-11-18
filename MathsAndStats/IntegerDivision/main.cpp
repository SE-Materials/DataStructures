//
//  main.cpp
//  IntegerDivision
//
//  Created by Aniket Bhushan on 17/11/19.
//  Copyright © 2019 Aniket Bhushan. All rights reserved.
//

#include <iostream>

int divide(int a, int b)
{
    bool isOneOfThemNegative = (a<0 && b>0) || (a>0 && b<0);
    a = abs(a);
    b = abs(b);
    
    if (a < b)
        return 0;
    int count {1}, bp {b};
    while (a>=bp)
    {
        bp = bp + b;
        count++;
    }
    return isOneOfThemNegative ? 1-count : count-1;
}

int divide2(int a, int b)
{
    int sign = (a<0)^(b<0) ? -1 : 1;
    
    int divisor {abs(b)}, dividend{abs(a)}, quotient {0};
    
    while (dividend-divisor >0)
    {
        int i = 0;
        while (dividend >= (divisor<<1<<i))
            i++;
        quotient |= (1<<i);
        dividend = dividend - (divisor<<i);
    }
    
    return sign*quotient;
}

int main(int argc, const char * argv[]) {
    int a {-15}, b{2};
    
    std::cout << divide2(a, b) << std::endl;
    return 0;
}
