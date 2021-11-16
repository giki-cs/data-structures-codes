#include <iostream>
using namespace std;

struct node
{
    int data;
    node* ptrdiff;
} *head = nullptr, *tail = nullptr;

void insert(int val);
void print(int=0); //0 means not reverse, 1 means reverse print
bool memoryError(node*&);
node* xors(node*, node*);

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);

    print();
    print(1);
}

void insert(int val)
{
    node* curr = new node;
    memoryError(curr);
    curr->data = val;
    curr->ptrdiff = head;

    if(head != nullptr)
        head->ptrdiff = xors(head->ptrdiff, curr);
    else
        tail = curr;

    head = curr;
}


void print(int reverse)
{
    node* prev = nullptr, *next, *curr = reverse ? head:tail;

    while ( curr != nullptr )
    {
        cout << curr->data << " ";
        next = xors(curr->ptrdiff, prev);
        prev = curr;
        curr = next;
    }
    cout << endl;


}


node* xors(node* a, node* b)
{
    return reinterpret_cast<node*>( reinterpret_cast<uintptr_t>(a) ^ reinterpret_cast<uintptr_t>(b) );
}

bool memoryError(node*& temp)
{
    if(temp) return true;

    cerr << "\nMemory Error!\n";

    return true;
}
