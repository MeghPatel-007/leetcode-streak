#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *child;
    ListNode()
    {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *next2)
    {
        val = data1;
        next = next1;
        child = next1;
    }
};

class Solution
{
private:
    ListNode *merge(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *dummyTail = dummy;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                dummyTail->child = list1;
                dummyTail = list1;
                list1 = list1->child;
            }
            else
            {
                dummyTail->child = list2;
                dummyTail = list2;
                list2 = list2->child;
            }
            dummyTail->next = nullptr;
        }
        dummyTail->child = (list1 != nullptr) ? list1 : list2;
        if (dummyTail->child)
            dummyTail->child->next = nullptr;
        return dummy->child;
    }

public:
    ListNode *flattenLinkedList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *mergeHead = flattenLinkedList(head->next);
        merge(head, mergeHead);
        return head;
    }
};

void printLinkedList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->child;
    }
    cout << endl;
}

void printOriginalLinkedList(ListNode *head, int depth)
{
    while (head != nullptr)
    {
        cout << head->val;

        if (head->child)
        {
            cout << " -> ";
            printOriginalLinkedList(head->child, depth + 1);
        }

        if (head->next)
        {
            cout << endl;
            for (int i = 0; i < depth; ++i)
            {
                cout << "| ";
            }
        }
        head = head->next;
    }
}

int main()
{
    ListNode *head = new ListNode(5);
    head->child = new ListNode(14);

    head->next = new ListNode(10);
    head->next->child = new ListNode(4);

    head->next->next = new ListNode(12);
    head->next->next->child = new ListNode(20);
    head->next->next->child->child = new ListNode(13);

    head->next->next->next = new ListNode(7);
    head->next->next->next->child = new ListNode(17);

    cout << "Original linked list:" << endl;
    printOriginalLinkedList(head, 0);

    Solution sol;

    ListNode *flattened = sol.flattenLinkedList(head);

    cout << "\nFlattened linked list: ";
    printLinkedList(flattened);

    return 0;
}
