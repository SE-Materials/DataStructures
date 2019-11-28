//
//  main.cpp
//  CalculateSquareRoot
//
//  Created by Aniket Bhushan on 17/11/19.
//  Copyright © 2019 Aniket Bhushan. All rights reserved.
//

#include <iostream>

double sqrt(int n, int precision)
{
    int l = 0, r = n;
    float ans = 0;
    while (l <= r)
    {
        int mid = (l + r)/2;
        if (mid*mid == n)
        {
            ans = mid;
            break;
        }
        else if (mid*mid > n)
        {
            r = mid-1;
            ans = r;
        }
        else
        {
            l = mid+1;
        }
    }
    
    float incremnt = 0.1;
    
    for (int i=0; i<precision; ++i)
    {
        while (ans*ans <= n)
        {
            ans += incremnt;
        }
        
        ans = ans - incremnt;
        incremnt /= 10;
    }

    return ans;
}

int main(int argc, const char * argv[]) {

    std::cout << sqrt(1, 2) << std::endl;
    std::cout << sqrt(2, 2) << std::endl;
    std::cout << sqrt(3, 2) << std::endl;
    std::cout << sqrt(4, 2) << std::endl;
    std::cout << sqrt(5, 2) << std::endl;
    std::cout << sqrt(6, 2) << std::endl;
    std::cout << sqrt(7, 2) << std::endl;
    std::cout << sqrt(8, 2) << std::endl;
    std::cout << sqrt(9, 2) << std::endl;
    return 0;
}
