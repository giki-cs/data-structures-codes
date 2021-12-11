#include <iostream>
using namespace std;

struct node
{
    int val;
    node *next;
};

node *head = nullptr;
node *last = nullptr;

void insert(int v)
{
    if (head == nullptr)
    {
        head = new node;
        head->val = v;
        head->next = nullptr;
        last = head;
        return;
    }

    node *newNode = new node;
    newNode->val = v;
    newNode->next = nullptr;
    last->next = newNode;
    last = newNode;
}

void printReverse(node* temp=head)
{
    if ( temp->next == nullptr )
    {
        cout << temp->val << " ";
        return;
    }

    printReverse(temp->next); // 101
    cout << temp->val << " ";
}

void print()
{
    node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

void deletes(int v)
{
    node *temp = head;
    node *prev = nullptr;

    while (temp->val != v)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;

    delete temp;
    temp = nullptr;
}

void add(int index, int value)
{
//time complexity = number of steps
    node *temp = head;

    for (int i = 0; i < index-1; i++)
    {
        temp = temp->next;
    }

    node *added = new node;

    added->val = value;
    added->next = temp->next;

    temp->next = added;
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    insert(7);
    insert(8);

    add(4, 10);
    deletes(2);

    cout << "Printing Forward: ";
    print();
    cout << endl;
    cout << "\nPrinting in reverse: "; 
    printReverse();

    return 0;
}