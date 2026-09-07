#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class Solution
{
public:
    void insertAtEnd(Node *&head, int val)
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
        newNode->prev = temp;
    }

    void printList(Node *head)
    {
        Node *temp = head;

        while (temp)
        {
            cout << temp->data;
            if (temp->next)
                cout << " <-> ";
            temp = temp->next;
        }
        cout << endl;
    }
    //  * DoubleLinkedList
    Node *deleteTargetNodes(Node *head, int target)
    {
        Node *dummy = head;
        while (dummy != nullptr)
        {
            if (dummy->data == target)
            {
                if (dummy->prev)
                {
                    dummy->prev->next = dummy->next;
                }
                else
                {
                    head = dummy->next;
                }
                if (dummy->next)
                {
                    dummy->next->prev = dummy->prev;
                }
            }
            dummy = dummy->next;
        }
        delete dummy;
        return head;
    }
};

int main()
{
    Solution sol;
    Node *head = nullptr;

    sol.insertAtEnd(head, 1);
    sol.insertAtEnd(head, 2);
    sol.insertAtEnd(head, 3);
    sol.insertAtEnd(head, 2);
    sol.insertAtEnd(head, 4);
    sol.insertAtEnd(head, 2);
    sol.insertAtEnd(head, 5);

    cout << "Original List:\n";
    sol.printList(head);

    int target = 2;

    head = sol.deleteTargetNodes(head, target);

    cout << "\nList after deleting value " << target << ":\n";
    sol.printList(head);

    return 0;
}
