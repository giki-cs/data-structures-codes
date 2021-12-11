#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

node* top = nullptr;

void push(int);
void print();
void pop();

int main()
{
    //incomplete


    return 0;
}

void push(int val)
{
    if ( top == nullptr )
    {
        top = new node;
        top->data = val;
        top->next = nullptr;

        return;
    }

    node* newNode = new node;
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    node* temp = top;
    top = temp->next;
    delete temp;
    temp = nullptr;
}