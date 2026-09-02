#include <bits/stdc++.h>
using namespace std;

// * linkedList , tortoise and hare
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head->next == nullptr && n == 1)
            return nullptr;
        if (head == nullptr || head->next == nullptr)
            return head;
        if (head->next->next == nullptr && n == 2)
            return head->next;
        if (head->next->next == nullptr && n == 1)
        {
            head->next = nullptr;
            return head;
        }
        ListNode *dummy = new ListNode(0, head);
        ListNode *fast = dummy;
        ListNode *slow = dummy;
        for (int i = 0; i <= n; i++)
        {
            fast = fast->next;
        }
        while (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};
