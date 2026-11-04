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
    Node *tail;
    dll(Node *head = new Node())
    {
        this->head = head;
        this->tail = head;
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
        this->tail = newNode;
    }
    void deleteNode()
    {
        if (this->head == nullptr && this->tail == nullptr)
            return;
        if (this->head->next == nullptr)
        {
            delete this->head;
            this->head = nullptr;
            this->tail = nullptr;
            return;
        }
        Node *travs = this->tail;
        this->tail = travs->prev;
        this->tail->next = nullptr;
        delete travs;
        return;
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
    void reversePrintList(Node *head)
    {
        Node *travs = head;
        while (travs != nullptr)
        {
            cout << travs->data << " ";
            travs = travs->prev;
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
    d1->deleteNode();
    d1->printList();
    d1->reversePrintList(d1->tail);
    return 0;
}
