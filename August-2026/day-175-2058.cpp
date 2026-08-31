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
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return {-1, -1};
        ListNode *prevNode = head;
        ListNode *currNode = head->next;
        int firstCp = -1;
        int prevCp = -1;
        int pos = 2;
        int minDist = INT_MAX;
        while (currNode->next != nullptr)
        {
            if ((prevNode->val < currNode->val && currNode->next->val < currNode->val) ||
                (prevNode->val > currNode->val && currNode->next->val > currNode->val))
            {
                if (firstCp == -1)
                {
                    firstCp = pos;
                }
                else
                {
                    minDist = min(minDist, pos - prevCp);
                }
                prevCp = pos;
            }
            prevNode = currNode;
            currNode = currNode->next;
            pos++;
        }
        if (firstCp == -1 || firstCp == prevCp)
        {
            return {-1, -1};
        }
        return {minDist, prevCp - firstCp};
    }
};
