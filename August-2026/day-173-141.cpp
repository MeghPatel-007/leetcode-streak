#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        // if(head == nullptr)return false;
        // if(head->next == nullptr)return false;
        // ListNode* travs = head;
        // unordered_map<ListNode*,int>m;
        // while(travs->next != nullptr){
        //     m[travs]++;
        //     if(m[travs] > 1)return true;
        //     travs = travs->next;
        // }
        // return false;

        //* tortoise and hare algo
        if (head == nullptr)
            return false;
        if (head->next == nullptr)
            return false;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};
