/*
* A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. 
* A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
* 
* The path sum of a path is the sum of the node's values in the path.
* 
* Given the root of a binary tree, return the maximum path sum of any non-empty path.
*/

#include <iostream>
#include <algorithm>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int ans {0};
    
    int maxPathSumInternalSimple(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        int lsum = max( maxPathSumInternal(root->left), 0);
        int rsum = max( maxPathSumInternal(root->right), 0);
        
        ans = max(ans, root->val + lsum + rsum);
        
        return root->val + max(lsum, rsum);
    }

    int maxPathSumInternal(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int lsum = maxPathSumInternal(root->left);
        int rsum = maxPathSumInternal(root->right);
        
        ans = max(ans, 
                  max(
                      {
                          root->val,
                          root->val + lsum,
                          root->val + rsum, 
                          root->val + lsum + rsum
                    }));
        
        return max(root->val, root->val + max(lsum, rsum));
    }
public:
    int maxPathSum(TreeNode* root) {
        ans = -2e9;
        maxPathSumInternal(root);
        // maxPathSumInternalSimple(root);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    // Nodes be negative as well!
    return 0;
}
