
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Pre order of : image tree -> reverse(pre order (l <-> r))

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int>      ans;
        stack<TreeNode*> st;
        
        if (root != nullptr)
            st.push(root);
        
        while (!st.empty())
        {
            root = st.top(); st.pop();
            
            if (root->left)
                st.push(root->left);
            
            if (root->right)
                st.push(root->right);
            
            ans.push_back(root->val);
        }
        
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
