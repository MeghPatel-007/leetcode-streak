#include <bits/stdc++.h>
using namespace std;

// * LinkedList , two pointer , hash map
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        if (temp1 == temp2)
            return temp1;
        while (temp1 != temp2)
        {
            temp1 = temp1 == nullptr ? headB : temp1->next;
            temp2 = temp2 == nullptr ? headA : temp2->next;
        }
        return temp1;
    }
};
