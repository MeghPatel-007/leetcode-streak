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
//* tortoise and hare algo
class Solution
{
public:
    int length(ListNode *head)
    {
        ListNode *travs = head;
        int len = 0;
        while (travs != nullptr)
        {
            len++;
            travs = travs->next;
        }
        return len;
    }
    ListNode *middleNode(ListNode *head)
    {
        int len = length(head);
        int mid = len / 2;
        ListNode *midNode = head;
        while (mid--)
        {
            midNode = midNode->next;
        }
        return midNode;
    }
};
