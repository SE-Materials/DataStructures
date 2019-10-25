//
//  main.cpp
//  RightRotateArray
//
//  Created by Aniket Bhushan on 03/10/19.
//  Copyright © 2019 Aniket Bhushan. All rights reserved.
//

#include <iostream>
#include <vector>

typedef std::vector<int> vi;

void print(const vi& v)
{
    for (auto e : v)
        std::cout << e << " ";
    std::cout << std::endl;
}

int getNext(int curr, int del, int max)
{
    curr = (curr + del + max)%max;
    return curr;
}

void rotate(vi& v, int k)
{
    k = k%v.size();
    
    // 1, 2, 3, 4, 5
    //
    
    int numOfSwaps = 0;
    for (int i=0; i<k; ++i)
    {
        int j = i;
        int jnext = getNext(j, -k, v.size());
        int key = v[j];
        while (jnext != i && numOfSwaps<v.size()-1)
        {
            v[j] = v[jnext];
            numOfSwaps++;
            j = jnext;
            jnext = getNext(jnext, -k, v.size());
        }
        
        v[j] = key;
    }
}

int main(int argc, const char * argv[]) {
    
    vi v{1, 2, 3, 4, 5, 6, 7};
    int k = 1;
    
    rotate(v, k);
    
    print(v);
    
    return 0;
}
