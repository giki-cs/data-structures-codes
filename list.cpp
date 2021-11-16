#include <iostream>
using namespace std;

struct node
{
    int data;
    node* ptr;
};

node* head = nullptr;
node* last = nullptr;

void insert(int );
void print();

int main()
{
    insert(5);
    insert(6);
    insert(9);
    insert(7);
    insert(10);

    print();

    return 0;
}

void insert( int val )
{
    node* newNode = new node;
    newNode->data = val;
    newNode->ptr = nullptr;
    

    if ( head == nullptr )
        head = newNode;
    else
    {
        last->ptr = newNode;
    }

    last = newNode;
}

void print()
{
    node* temp = head;

    while ( temp != nullptr )
    {
        cout << temp->data << endl;
        temp = temp->ptr;
    }
}