// https://leetcode.com/problems/flatten-binary-tree-to-linked-list

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
class Solution {
    
    TreeNode* prev = nullptr;
    
    void flattenRecursive(TreeNode* root)
    {
        if (root == nullptr)
            return;
        
        flattenRecursive(root->right);
        flattenRecursive(root->left);
        
        root->right = prev;
        root->left  = nullptr;
        
        prev = root;
    }
    
    void flattenIterative(TreeNode* root)
    {
        stack<TreeNode*> st;
        
        if (root != nullptr)
            st.push(root);
        
        while (!st.empty())
        {
            root = st.top(); st.pop();
            
            if (root->right != nullptr)
                st.push(root->right);
            
            if (root->left  != nullptr)
                st.push(root->left);
            
            if (!st.empty())
                root->right = st.top();
            
            root->left = nullptr;
        }
        
    }
    
    void flattenMorris(TreeNode* root)
    {
        TreeNode* curr = root;
        
        while (curr != nullptr)
        {
            if (curr->left != nullptr)
            {
                auto prev = curr->left;
                
                while (prev->right != nullptr)
                    prev = prev->right;
                
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left  = nullptr;
            }

            curr = curr->right;
        }
        
    }
    
public:
    void flatten(TreeNode* root) 
    {
        // flattenRecursive(root);
        // flattenIterative(root);
        flattenMorris(root);
    }
};
