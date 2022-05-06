#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

class Solution {

public:
    int solve(std::vector<std::vector<int>> & A);
};

std::vector<std::vector<int>> visited;
std::vector<int> delI {0, 0, -1, 1, -1, -1, 1, 1};
std::vector<int> delJ {-1, 1, 0, 0, -1, 1, -1, 1};

void dfs(std::vector<std::vector<int>>& A, int i, int j, int& nComp) {
    visited[i][j] = 0;
    nComp++;

    for (int k=0; k<8; k++) {
        int i1 = i + delI[k];
        int j1 = j + delJ[k];

        if (i1 >= 0 && j1 >= 0 && i1 < A.size() && j1 < A[0].size() && visited[i1][j1] == 1) 
            dfs(A, i1, j1, nComp);
    }
}

void bfs(std::vector<std::vector<int>>& A, int i, int j, int& nComp) {
    std::queue<std::pair<int,int>> Q;
    
    Q.push({i, j});
    visited[i][j] = 0;
    
    while (!Q.empty()) {
        auto [u, v] = Q.front(); Q.pop();
        nComp++;

        for (int k=0; k<8; k++) {
            int i1 = u + delI[k];
            int j1 = v + delJ[k];

            if (i1 >= 0 && j1 >= 0 && i1 < A.size() && j1 < A[0].size() && visited[i1][j1] == 1) 
                bfs(A, i1, j1, nComp);
        }
    }
}


int Solution::solve(std::vector<std::vector<int>> & A) {
    visited = A;
    int ans {0};

    for (int i=0; i<A.size(); i++) {
        for (int j=0; j<A[0].size(); j++) {
            if (visited[i][j] == 1) {
                int nComponents {0};
                // dfs(A, i, j, nComponents);
                bfs(A, i, j, nComponents);
                ans = std::max(ans, nComponents);
            }
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    Solution sol;
    std::vector<std::vector<int>> A {
        {0, 0, 1, 1, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1}
    };
    std::cout << sol.solve(A) << std::endl;
    return 0;
}

