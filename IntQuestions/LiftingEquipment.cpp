#include <iostream>
#include <vector>

using namespace std;

int getMinMoves(vector<int> plates) {

    int minElementIdx = 0, minElement = 2000000000;
    int maxElementIdx = 0, maxElement = 0;

    int nSwaps = 0;
    int n = plates.size();
    if (n == 0) 
        return 0;
        
    for (int i=0; i<plates.size(); i++) {
        if (plates[i] < minElement) {
            minElement = plates[i];
            minElementIdx = i;
        }

        if (plates[i] >= maxElement) {
            maxElement = plates[i];
            maxElementIdx = i;
        }
    }

    if (minElementIdx > maxElementIdx)
        return minElementIdx + (n - 1 - maxElementIdx) - 1;
    else 
        return minElementIdx + (n - 1 - maxElementIdx);
}

int main(int argc, char const *argv[])
{
    // vector<int> plates {3, 2, 1};
    // vector<int> plates {2, 4, 3, 1, 6};
    // vector<int> plates {2};
    // vector<int> plates {2, 2};
    // vector<int> plates {1, 2, 3, 1, 6};
    // vector<int> plates {1, 2, 6, 1, 1};
    vector<int> plates {};
    cout << getMinMoves(plates) << endl;
    return 0;
}
