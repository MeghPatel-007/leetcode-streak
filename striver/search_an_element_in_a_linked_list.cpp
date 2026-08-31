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
    Node *head;
    int len;
    ll(Node *head = new Node())
    {
        this->head = head;
        len = -1;
    }
    void insertNode(Node *head, int newData)
    {
        this->len++;
        Node *newNode = new Node(newData);
        Node *travs = head;
        while (travs->next != nullptr)
        {
            travs = travs->next;
        }
        travs->next = newNode;
    }
    void printList(Node *head)
    {
        Node *travs = head->next;
        while (travs != nullptr)
        {
            cout << travs->data << " ";
            travs = travs->next;
        }
        cout << endl;
    }
    bool search(Node *head, int find)
    {
        Node *travs = head;
        while (travs->next != nullptr)
        {
            if (travs->data != find)
            {
                travs = travs->next;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    ll *l1 = new ll();
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        l1->insertNode(l1->head, i);
    }
    l1->printList(l1->head->next);
    cout << l1->len << endl;
    cout << boolalpha << l1->search(l1->head, -1);
}
