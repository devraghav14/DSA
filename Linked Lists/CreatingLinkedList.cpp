#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (tail == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    // Insert at head
    insertAtHead(head, tail, 90);
    insertAtHead(head, tail, 60);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 25);

    cout << "After head insertions: ";
    print(head);

    // Insert at tail
    insertAtTail(head, tail, 100);
    insertAtTail(head, tail, 120);

    cout << "After tail insertions: ";
    print(head);

    return 0;
}
