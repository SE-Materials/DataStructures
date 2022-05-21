/*
 * https://leetcode.com/explore/interview/card/google/60/linked-list-5/3063/
 *
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *vtoll(vector<int> &vect)
{
    ListNode *result = nullptr, *curr = nullptr;
    for (auto element : vect)
    {
        if (curr == nullptr)
        {
            result = new ListNode(element);
            curr = result;
        }
        else
        {
            curr->next = new ListNode(element);
            curr = curr->next;
        }
    }
    return result;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbersWthDummyHead(ListNode *l1, ListNode *l2)
    {
        ListNode *result = new ListNode(0);
        ListNode *curr   = result;

        int carry{0};
        int val1{0};
        int val2{0};

        while (l1 != nullptr || l2 != nullptr)
        {
            val1 = l1 != nullptr ? l1->val : 0;
            val2 = l2 != nullptr ? l2->val : 0;

            int currsum = val1 + val2 + carry;

            curr->next = new ListNode(currsum % 10);
            curr = curr->next;

            carry = currsum / 10;

            if (l1 != nullptr) l1 = l1->next;

            if (l2 != nullptr) l2 = l2->next;
        }

        if (carry)
            curr->next = new ListNode(carry);

        return result->next;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *result = nullptr, *curr = nullptr;
        int carry{0};
        int val1{0};
        int val2{0};

        while (l1 != nullptr || l2 != nullptr)
        {
            val1 = l1 != nullptr ? l1->val : 0;
            val2 = l2 != nullptr ? l2->val : 0;

            int currsum = val1 + val2 + carry;

            if (curr == nullptr)
            {
                result = new ListNode(currsum % 10);
                curr = result;
            }
            else
            {
                curr->next = new ListNode(currsum % 10);
                curr = curr->next;
            }

            carry = currsum / 10;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        if (carry)
            curr->next = new ListNode(carry);

        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> l = {9, 9, 9, 9, 9, 9, 9};
    vector<int> r = {9, 9, 9, 9};

    Solution sol;
    ListNode *res = sol.addTwoNumbers(vtoll(l), vtoll(r));

    while (res != nullptr)
    {
        cout << res->val << " ";
        res = res->next;
    }

    return 0;
}
