
// https://leetcode.com/problems/binary-search-tree-iterator

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
class BSTIterator 
{
    TreeNode*        m_root;
    stack<TreeNode*> m_st;
    
    void insertLeft(TreeNode* node)
    {
        while (node)
        {
            m_st.push(node);
            node = node->left;
        }
    }
    
    public:
    
    BSTIterator(TreeNode* root) : m_root {root}, m_st{} 
    {
        insertLeft(m_root);
    }
    
    int next() 
    {
        if (hasNext())
        {
            auto top = m_st.top(); m_st.pop();
            
            if (top->right)
            {
                insertLeft(top->right); 
            }
            
            return top->val;
        }
        return -1;
    }
    
    bool hasNext() 
    {
        return !m_st.empty();    
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
