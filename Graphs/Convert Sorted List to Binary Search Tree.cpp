// https://www.interviewbit.com/problems/convert-sorted-list-to-binary-search-tree/

#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode (int x) : left {nullptr}, right {nullptr}, val (x) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : next {nullptr}, val (x) {}
};

class Solution {

public:
    TreeNode* sortedListToBST(ListNode* A);
};


// -- Method 1 : O(nlogn) -- Constructs tree from root to leaves --
ListNode* getMidNode(ListNode* start, ListNode* end) {
    ListNode* slow = start;
    ListNode* fast = start;

    while (fast != end && fast->next != end) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

TreeNode* f(ListNode* start, ListNode* end) {
    if (start == end) return nullptr;
    
    auto midNode = getMidNode(start, end);

    auto root = new TreeNode(midNode->val);
    
    root->left  = f(start, midNode);
    root->right = f(midNode->next, end);

    return root;
}

// -- Method 2 : O() -- Constructs tree from leaves to root --

TreeNode* Solution::sortedListToBST(ListNode* A)
{
    // return f(A, nullptr); // Method 1

}

int main(int argc, char const *argv[])
{
    Solution sol;
    
    ListNode root(1);
    ListNode* temp = &root;

    temp  = temp->next = &(ListNode(2));
    temp  = temp->next = &(ListNode(3));

    auto tree = sol.sortedListToBST(&root);
    return 0;
}
