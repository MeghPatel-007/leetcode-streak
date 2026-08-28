#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data = 0, Node *next = nullptr, Node *prev = nullptr)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

class dll
{
public:
    Node *head;
    dll(Node *head = new Node())
    {
        this->head = head;
    }
    void insertNode(int newData)
    {
        Node *newNode = new Node(newData);
        Node *travs = this->head;
        while (travs->next != nullptr)
        {
            travs = travs->next;
        }
        travs->next = newNode;
        newNode->prev = travs;
    }
    void insertNodeBeforeHead(int newData)
    {
        Node *newNode = new Node(newData);
        newNode->next = this->head;
        this->head->prev = newNode;
        this->head = newNode;
    }
    void printList()
    {
        Node *travs = this->head;
        while (travs != nullptr)
        {
            cout << travs->data << " ";
            travs = travs->next;
        }
        cout << endl;
    }
};

int main()
{
    dll *d1 = new dll();
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        d1->insertNode(i);
    }
    d1->printList();
    d1->insertNodeBeforeHead(20);
    d1->insertNodeBeforeHead(30);
    d1->printList();
    return 0;
}
