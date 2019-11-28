//
//  main.cpp
//  AllSubsets
//
//  Created by Aniket Bhushan on 17/11/19.
//  Copyright © 2019 Aniket Bhushan. All rights reserved.
//

#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vi)
{
    for (const auto& e : vi)
        os << e << " ";
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<int>>& vvi)
{
    for (const auto& v : vvi)
        os << v << std::endl;
    return os;
}

void findAllSubsets(std::vector<std::vector<int>>& sets, const std::vector<int>& v, int i, std::vector<int>& vc)
{
    if (i >= v.size()) {
        sets.push_back(vc);
        return;
    }
    
    // Include ii
    vc.push_back(v[i]);
    findAllSubsets(sets, v, i+1, vc);

    
    // Don't include ii
    vc.pop_back();
    findAllSubsets(sets, v, i+1, vc);
}

int main(int argc, const char * argv[]) {
    std::vector<int> v {1, 2, 3, 4};
    std::vector<std::vector<int>> ans;
    std::vector<int> vi;
    
    findAllSubsets(ans, v, 0, vi);
    std::cout << ans << std::endl;
    return 0;
}
