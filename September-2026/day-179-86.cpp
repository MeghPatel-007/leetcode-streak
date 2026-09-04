#include <bits/stdc++.h>
using namespace std;

// * LinkedList,twopointers
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
    ListNode *partition(ListNode *head, int x)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *l1Head = new ListNode();
        ListNode *l2Head = new ListNode();

        ListNode *l1Tail = l1Head;
        ListNode *l2Tail = l2Head;

        ListNode *curr = head, *temp = head;

        while (curr != nullptr)
        {
            temp = curr;
            curr = curr->next;
            temp->next = nullptr;
            if (temp->val < x)
            {
                l1Tail->next = temp;
                l1Tail = l1Tail->next;
            }
            else
            {
                l2Tail->next = temp;
                l2Tail = l2Tail->next;
            }
        }
        l1Tail->next = l2Head->next;
        return l1Head->next;
    }
};
