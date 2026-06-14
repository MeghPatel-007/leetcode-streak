#include <bits/stdc++.h>
using namespace std;

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int pairSum(ListNode *head)
    {
        ListNode *current = head;
        int n = 0;
        while (current != nullptr)
        {
            current = current->next;
            n++;
        }
        int mid = n / 2 - 1;
        stack<int> s;
        current = head;
        int maxi = INT_MIN;
        while (current != nullptr)
        {
            if (mid >= 0)
            {
                s.push(current->val);
                --mid;
            }
            else
            {
                maxi = max(maxi, s.top() + current->val);
                s.pop();
            }
            current = current->next;
        }
        return maxi;
    }
};
