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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *travs = head;
        int size = 0;
        while (travs != nullptr)
        {
            travs = travs->next;
            size++;
        }
        travs = head;
        ListNode *prev = travs;
        k %= size;
        while (k != 0)
        {
            if (travs->next == nullptr)
            {
                prev->next = nullptr;
                travs->next = head;
                head = travs;
                k--;
            }
            prev = travs;
            travs = travs->next;
        }
        return head;
    }
};
