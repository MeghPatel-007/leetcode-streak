#include <bits/stdc++.h>
using namespace std;

// * LinkedList
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
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *curr = head;
        ListNode *prev = curr;
        while (curr != nullptr)
        {
            bool dup = true;
            prev = curr;
            while (curr->next != nullptr && curr->val == curr->next->val)
            {
                curr = curr->next;
                dup = false;
            }
            if (!dup)
            {
                prev->next = curr->next;
            }
            curr = curr->next;
        }
        return head;
    }
};
