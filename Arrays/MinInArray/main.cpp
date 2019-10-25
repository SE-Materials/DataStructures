//
//  main.cpp
//  MinInArray
//
//  Created by Aniket Bhushan on 06/10/19.
//  Copyright © 2019 Aniket Bhushan. All rights reserved.
//

#include <iostream>
#include <vector>

typedef std::vector<int> vi;

int main(int argc, const char * argv[]) {
    vi v {1, 3, 0, -1, 5, 3, 9}  ;
    std::cout << *std::min_element(v.begin(), v.end()) << std::endl;
    
    return 0;
}
