#include<bits/stdc++.h>
using namespace std;

// * linkedList
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
        temp = head;
        while (temp != nullptr)
        {
            Node *newNode = temp->next;
            if (temp->random == nullptr)
            {
                newNode->random = nullptr;
            }
            else
            {
                newNode->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        Node *dummy = new Node(-1);
        Node *dummyTail = dummy;
        temp = head;
        while (temp != nullptr)
        {
            dummyTail->next = temp->next;
            temp->next = temp->next->next;
            temp = temp->next;
            dummyTail = dummyTail->next;
        }
        return dummy->next;
    }
};
