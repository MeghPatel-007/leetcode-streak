#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList
{
public:
    Node *append(Node *head, int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            return newNode;
        }
        Node *current = head;
        while (current->next)
            current = current->next;
        current->next = newNode;
        return head;
    }

    void printList(Node *head)
    {
        Node *current = head;
        while (current)
        {
            cout << current->data;
            current = current->next;
        }
        cout << endl;
    }
};

class Solution
{
public:
    int addOneUtil(Node *node)
    {
        if (node == nullptr)
            return 1;
        int carry = addOneUtil(node->next);
        node->data += carry;
        if (node->data < 10)
        {
            return 0;
        }
        node->data = 0;
        return 1;
    }

    Node *addOne(Node *head)
    {
        int carry = addOneUtil(head);
        if (carry == 1)
        {
            Node *newNode = new Node(1);
            newNode->next = head;
            return newNode;
        }
        return head;
    }
};

int main()
{
    Node *head = nullptr;
    LinkedList ll;
    Solution sol;

    // Example: Number 129 (1 -> 2 -> 9)
    head = ll.append(head, 1);
    head = ll.append(head, 2);
    head = ll.append(head, 9);

    cout << "Original Number: ";
    ll.printList(head);

    head = sol.addOne(head);

    cout << "After Adding One: ";
    ll.printList(head);

    return 0;
}
