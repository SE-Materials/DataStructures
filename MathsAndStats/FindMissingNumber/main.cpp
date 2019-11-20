//
//  main.cpp
//  FindMissingNumber
//
//  Created by Aniket Bhushan on 17/11/19.
//  Copyright © 2019 Aniket Bhushan. All rights reserved.
//

#include <iostream>
#include <vector>

//In sorted
int findMissingNumberSorted(const std::vector<int>& v)
{
    int f = 0, l = v.size()-1;
    int mid;
    while (f+1<l)
    {
        mid = (f+l)/2;
        if (v[f]-f != v[mid]-mid)
            l = mid;
        else if (v[l]-l != v[mid]-mid)
            f = mid;
    }
    
    return v[mid]+1;
}

// In Unsorted
int findMissingNumber(const std::vector<int>& v)
{
// Using xor
#ifdef XOR
    int n = v.size()+1;
    int x {};
    
    for (int i=1; i<=n; ++i) {
        x = x^i;
    }
    
    int y {};
    for (const auto& e : v)
        y = y^e;
    
    return x^y;
#endif
    
// Using difference avoiding overflow
    int total = v.size()+1;
    for (int i=0; i<v.size(); ++i) {
        total += (i+1);
        total = total - v[i];
    }
    
    return total;
}

int main(int argc, const char * argv[]) {
    std::vector<int> v {1, 2, 3, 5};
    std::cout << findMissingNumber(v) << std::endl;
    
    std::cout << findMissingNumberSorted(v) << std::endl;
    return 0;
}
