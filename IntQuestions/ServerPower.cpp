#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mod = 10000007;
int INF = 2000000000;
int findTotalPower(vector<int> power) {
    
    int cmin {INF};
    int sum  {0};
    int ans  {0};
    vector<int> sums(power.size(), 0);

    for (int i=0; i<power.size(); i++) 
    {
        cmin = min(cmin, power[i]);

        if (i > 0)
            sums[i] = power[i] + sums[i-1];
        else 
            sums[i] = power[i] ;
    }



    for (int i=0; i<power.size(); i++) 
    {
        if (i > 0)
            sums[i] = power[i] + sums[i-1];
        else 
            sums[i] = power[i] ;

        // for (int j=i; j<power.size(); j++) 
        // {
            
            // cmin = min(cmin, power[j]);
        //     sum = (sum + power[j]) % mod;

        //     // cout << i << ":" << j << " -- " << cmin << "*" << sum << " = " << (sum * cmin)%mod << endl;
        //     ans = ans + (sum * cmin)%mod;
        // }
        // sum = 0;
        // cmin = INF;
    }

    cout << "Sum : ";
    for (auto csum : sums) 
        cout << csum << " ";
    cout << endl;
    return ans;
}


int main(int argc, char const *argv[])
{
    // vector<int> power {2, 3, 2, 1};
    vector<int> power {2, 1, 3};

    auto totalPower = findTotalPower(power);

    cout << totalPower << endl;
    
    return 0;
}
