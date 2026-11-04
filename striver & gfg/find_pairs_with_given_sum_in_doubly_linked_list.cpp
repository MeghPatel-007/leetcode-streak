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
    vector<pair<int, int>> sumPair(Node *head, int target)
    {
        vector<pair<int, int>> v;
        Node *left = head;
        Node *dummy = head;
        while (dummy->next != nullptr)
        {
            dummy = dummy->next;
        }
        Node *right = dummy;
        while (left->data <= right->data)
        {
            int sum = left->data + right->data;
            if (sum > target)
                right = right->prev;
            else if (sum < target)
                left = left->next;
            else
            {
                v.push_back({left->data, right->data});
                right = right->prev;
                left = left->next;
            }
        }
        return v;
    }
};

int main()
{
    Solution sol;
    Node *head = nullptr;
    vector<pair<int, int>> v;
    sol.insertAtEnd(head, 1);
    sol.insertAtEnd(head, 2);
    sol.insertAtEnd(head, 3);
    sol.insertAtEnd(head, 4);
    sol.insertAtEnd(head, 9);

    cout << "Original List:\n";
    sol.printList(head);

    int target = 5;

    v = sol.sumPair(head, target);

    for (auto it : v)
    {
        cout << "(" << it.first << "," << it.second << ")" << endl;
    }

    return 0;
}
