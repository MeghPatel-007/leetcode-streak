#include <bits/stdc++.h>
using namespace std;

// * linkedList
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
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *evenhead = new ListNode(-1), *eventail = evenhead;
        ListNode *oddhead = new ListNode(-1), *oddtail = oddhead;
        ListNode *curr = head, *temp;
        int idx = 1;
        while (curr != nullptr)
        {
            temp = curr;
            curr = curr->next;
            temp->next = nullptr;
            if (idx % 2 == 1)
            {
                oddtail->next = temp;
                oddtail = temp;
            }
            else
            {
                eventail->next = temp;
                eventail = temp;
            }
            idx++;
        }
        oddtail->next = evenhead->next;
        return oddhead->next;
    }
};
