#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *output = new ListNode(0);
        ListNode *travs = output;
        int c = 0;
        while (l1 || l2 || c)
        {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = x + y + c;
            c = sum / 10;
            travs->next = new ListNode(sum % 10);
            travs = travs->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        return output->next;
    }
};