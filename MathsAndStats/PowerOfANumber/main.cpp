//
//  main.cpp
//  PowerOfANumber
//
//  Created by Aniket Bhushan on 17/11/19.
//  Copyright © 2019 Aniket Bhushan. All rights reserved.
//

#include <iostream>

double power(double x, int y)
{
    if (y == 0)
        return 1;
    double temp = power(x, y/2);
    
    if (y%2 == 0)
    {
        return temp*temp;
    }
    else
    {
        if (y>0)
            return x*temp*temp;
        else
            return temp*temp/x;
    }
}

int main(int argc, const char * argv[]) {
    std::cout << power(5, 2) << std::endl;
    std::cout << power(5, 3) << std::endl;
    
    std::cout << power(0.5, 2) << std::endl;
    std::cout << power(0.5, 3) << std::endl;
    
    std::cout << power(-0.5, 2) << std::endl;
    std::cout << power(-0.5, 3) << std::endl;
    
    std::cout << power(2, -1) << std::endl;
    std::cout << power(2, -2) << std::endl;
    return 0;
}
