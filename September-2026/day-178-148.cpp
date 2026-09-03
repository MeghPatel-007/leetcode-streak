#include <bits/stdc++.h>
using namespace std;

// * Linkedlist , mergesort , two pointer
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
    ListNode *findMiddle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode *ml = new ListNode();
        ListNode *mltail = ml;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                mltail->next = l1;
                l1 = l1->next;
            }
            else if (l1->val > l2->val)
            {
                mltail->next = l2;
                l2 = l2->next;
            }
            mltail = mltail->next;
        }
        mltail->next = (l1 != nullptr) ? l1 : l2;
        return ml->next;
    }
    ListNode *func(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *middle = findMiddle(head);
        ListNode *leftHead = head;
        ListNode *rightHead = middle->next;
        middle->next = nullptr;
        leftHead = func(leftHead);
        rightHead = func(rightHead);
        return merge(leftHead, rightHead);
    }
    ListNode *sortList(ListNode *head)
    {
        return func(head);
    }
};
