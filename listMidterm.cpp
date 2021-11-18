#include <iostream>
using namespace std;

class node
{
private:
    int data;
    node* next;

    static node* head;
    static node* tail;

public:
    node(int val) { data = val; next = nullptr; }

    static void insert(int val);
    static void printForward();
    static void printReverse(node* cur=head);
    static void reverse(node* prev=nullptr, node*cur=head);
};

node* node::head = nullptr;
node* node::tail = nullptr;

int main()
{
    for(int i=1; i<=10; ++i)
        node::insert(i);

    node::printForward();
    node::reverse();
    node::printForward();
    node::printReverse();

    return 0;
}

void node::reverse(node* prev, node* cur)
{
    if(cur->next == nullptr)
    {
        cur->next = prev;
        head = cur;
        return;

    }

    reverse(cur, cur->next);
    cur->next = prev;

}

void node::printReverse(node* cur)
{
    if(cur->next == nullptr)
    {
            cout << cur->data << " ";
            return;
    }

    printReverse(cur->next);
    cout << cur->data << " ";

}



void node::insert(int val)
{
    if(head == nullptr)
    {
        head = new node(val);
        tail = head;
        return;
    }

    tail->next = new node(val);
    tail = tail->next;
}

void node::printForward()
{
    node* temp = head;
    cout << "Print: ";
    while(temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}