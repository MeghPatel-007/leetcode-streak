#include <bits/stdc++.h>
using namespace std;

// * linkedList,twopointer
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dummy = new ListNode();
        ListNode *dummyTail = dummy;

        while (head)
        {
            bool dup = false;
            while (head->next && head->val == head->next->val)
            {
                head = head->next;
                dup = true;
            }
            if (!dup)
            {
                dummyTail->next = head;
                dummyTail = dummyTail->next;
            }
            head = head->next;
        }
        dummyTail->next = nullptr;
        return dummy->next;
    }
};
