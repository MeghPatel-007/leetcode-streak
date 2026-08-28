#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data = 0, Node *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};

class ll
{
public:
    Node *insertNode(Node *head, int newData)
    {
        Node *newNode = new Node(newData, head);
        return newNode;
    }
    void printList(Node *head)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    ll l1;
    Node *head = new Node(2);
    head->next = new Node(3);
    cout << "Original List : ";
    l1.printList(head);
    cout << "Insert element : ";
    head = l1.insertNode(head, 10);
    l1.printList(head);

    return 0;
}
