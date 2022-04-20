// https://leetcode.com/problems/binary-tree-postorder-traversal


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

// ------------------------------------------------------------------------------------
// Method 1: With stack + reverse
class Solution1 {
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


// ------------------------------------------------------------------------------------
// Method 2: With stack only
// https://youtu.be/9orU55BRidg
class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int>      ans;
        stack<TreeNode*> st;
        
        if (root == nullptr)
            return ans;
        
        while (!st.empty() || root != nullptr)
        {
            while (root != nullptr)
            {
                st.push(root);
                root = root->left;
            }
            
            auto right = st.top()->right;
            
            if (right != nullptr)
            {
                root = right;
            }
            else
            {
                auto node = st.top(); st.pop();
                while (!st.empty() && st.top()->right == node)
                {
                    ans.push_back(node->val);
                    node = st.top(); st.pop();
                }
                ans.push_back(node->val);
            }
        }

        return ans;
    }
};
