#include <bits/stdc++.h>
using namespace std;

// * mergeList,linkedList
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
    ListNode *mergeLists(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        ListNode *mlHead = new ListNode();
        ListNode *mlTail = mlHead;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                mlTail->next = l1;
                l1 = l1->next;
            }
            else
            {
                mlTail->next = l2;
                l2 = l2->next;
            }
            mlTail = mlTail->next;
        }
        mlTail->next = (l1 != nullptr) ? l1 : l2;
        return mlHead->next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *mainMerge = nullptr;
        int n = lists.size();
        if (n == 0)
            return nullptr;
        for (int i = 0; i < n; i++)
        {
            mainMerge = mergeLists(mainMerge, lists[i]);
        }
        return mainMerge;
    }
};
