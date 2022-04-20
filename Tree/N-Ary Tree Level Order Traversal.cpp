// https://leetcode.com/problems/n-ary-tree-level-order-traversal/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

//-------------------------------------------------------------------------------------
// Method 1
class Solution1 
{
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<vector<int>> ans;
        vector<int> level;
        
        queue<Node*> q;
        
        if (root == nullptr)
            return ans;
        
        q.push(root);
        q.push(nullptr);
        
        while (!q.empty())
        {
            root = q.front(); q.pop();
            
            if (root == nullptr)
            {
                ans.push_back(level);
                level.clear();
                
                if (!q.empty() && q.front() != nullptr)
                    q.push(nullptr);
                
                continue;
            }
            
            level.push_back(root->val);

            
            for (auto child : root->children)
                if (child != nullptr)
                    q.push(child);
        }
        
        return ans;
    }
};

// -------------------------------------------------------------------------------------------
// Method 2:

class Solution2 
{
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<vector<int>> ans;
        vector<int> level;
        
        queue<Node*> q;
        
        if (root == nullptr)
            return ans;
        
        q.push(root);
        
        while (!q.empty())
        {
            int size = q.size();
            
            while (size--)
            {
                root = q.front(); q.pop();
                for (auto child : root->children)
                {
                    q.push(child);    
                }
                
                level.push_back(root->val);
            }
            
            ans.push_back(level);
            level.clear();
        }
        
        return ans;
    }
};
