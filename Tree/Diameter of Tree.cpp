// https://leetcode.com/problems/diameter-of-binary-tree/

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
    
    int ans;
    
    int diameter(TreeNode* node)
    {
        if (node == nullptr)
            return 0;
        int ln = diameter(node->left);
        int rn = diameter(node->right);
        
        ans = max(ans, 1 + ln + rn);
        return 1 + max(ln, rn);
    }
  
   int bfs()
   {
       // using BFS
        queue<TreeNode*> Q;
        Q.push(root);
        height[root] = 0;
        int deepestH = 0;
        TreeNode* deepestNode = root;
        
        while (!Q.empty()) {
            auto u = Q.front(); Q.pop();
            
            if (height[u] > deepestH) {
                deepestH = height[u];
                deepestNode = u;
            }
            
            if (u->left) {
                height[u->left] = height[u] + 1;
                parent[u->left] = u;
                Q.push(u->left);
            }
            
            if (u->right) {
                Q.push(u->right);
                parent[u->right] = u;
                height[u->right] = height[u] + 1;         
            }
        }
        
        // cout << "Deepest Node : " << deepestNode->val << " : " << deepestH << endl;
        // From deepestNode do DFS
        height.clear();
        Q.push(deepestNode);
        height[deepestNode] = 0;
        
        deepestH = 0;
        
        while (!Q.empty()) {
            auto u = Q.front(); Q.pop();
            // cout << "Node : " << u->val << " : " << height[u] << endl;

            if (height[u] > deepestH) {
                deepestH = height[u];
            }
            
            auto it = parent.find(u);
            if (it != parent.end() && !height[parent[u]]) {
                height[parent[u]] = 1 + height[u];
                Q.push(parent[u]);
            }
            
            if (u->left && u->left != deepestNode && !height[u->left]) {
                height[u->left] = 1 + height[u];
                Q.push(u->left);
            }
            
            if (u->right && u->right != deepestNode && !height[u->right]) {
                height[u->right] = 1 + height[u];
                Q.push(u->right);
            }
        }
        
        return deepestH; 
   }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        diameter(root);
        return ans-1;
    }
};
