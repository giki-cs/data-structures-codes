#include <iostream>
using namespace std;

class node
{
    private:
        int data;
        node* next;
        static node* head;
        static node* last;

    public:
        static void insert(int);
        static void print();
        static void insertAt(int, int);
};

node* node::head = nullptr;
node* node::last = nullptr;

int main()
{
    
    while(1)
    {
        int choice;
        cout << "\n\n1. Insert\n2. Print\n3. Exit\n\nYour Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int val; cout << "Value: ";
            cin >> val;
            node::insert(val);
            break;
        case 2:
            cout << "Printing: ";
            node::print();
            break;
        case 3:
            return 0;
        default:
            cout << "Enter a valid choice...\n\n\n";
        }

    }

    return 0;
}

void node::insert(int val)
{
    node* temp = new node;
    temp->data = val;
    temp->next = nullptr;

    if ( head == nullptr )
        head = temp;
    else
        last->next = temp;
        
    last = temp;
}

void node::print()
{
    node* temp = head;

    while ( temp != nullptr )
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void node::insertAt(int val, int pos)
{
    node* temp = head;

    for(int i=2; i<pos; ++i)
    {
        if ( temp->next != nullptr )
            temp = temp->next;
        else
            break;
    }

    node* newNode = new node;
    newNode->data = val;
    newNode->next = nullptr;

    if( pos == 1 )
    {
        newNode->next = head;
        head = newNode;
        return;
    }
    else
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }

}