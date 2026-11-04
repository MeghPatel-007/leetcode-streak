
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = nullptr;
    }

    void insert(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void print()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data;
            if (temp->next)
                cout << " -> ";
            temp = temp->next;
        }
        cout << " -> NULL\n";
    }
};

class Solution
{
public:
    void sortZeroOneTwo(LinkedList &ll)
    {
        Node *zeroHead = new Node(-1);
        Node *oneHead = new Node(-1);
        Node *twoHead = new Node(-1);

        Node *zeroTail = zeroHead;
        Node *oneTail = oneHead;
        Node *twoTail = twoHead;

        Node *travs = ll.head;
        while (travs != nullptr)
        {
            if (travs->data == 0)
            {
                zeroTail->next = travs;
                zeroTail = zeroTail->next;
            }
            else if (travs->data == 1)
            {
                oneTail->next = travs;
                oneTail = oneTail->next;
            }
            else
            {
                twoTail->next = travs;
                twoTail = twoTail->next;
            }
            travs = travs->next;
        }
        zeroTail->next = oneHead->next ? oneHead->next : twoHead->next;
        oneTail->next = twoHead->next;
        twoTail->next = nullptr;
        ll.head = zeroHead->next;
        delete zeroHead;
        delete oneHead;
        delete twoHead;
    }
};

// Driver code to demonstrate usage
int main()
{
    LinkedList ll;
    Solution sol;

    // Insert nodes into the list
    ll.insert(1);
    ll.insert(2);
    ll.insert(0);
    ll.insert(1);
    ll.insert(2);
    ll.insert(0);

    cout << "Original List:\n";
    ll.print();

    // Sort the list using rearrangement of links
    sol.sortZeroOneTwo(ll);

    cout << "Sorted List:\n";
    ll.print();

    return 0;
}
