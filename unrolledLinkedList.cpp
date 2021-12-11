#include <iostream>
using namespace std;
#define SIZE 5

struct node
{
    int data;
    node* next;
} *tail = nullptr;

struct linkedBlock
{
    linkedBlock* next;
    node* listHead;
    int nodeCount;

} *linkedHead = nullptr, *currentBlock = nullptr;

void insert(int);
void createBlock(linkedBlock**);
void print();

int main()
{
    for(int i=0; i<10; ++i)
        insert(i);
    print();

    return 0;
}

void print()
{
    node* temp = linkedHead->listHead;

    while(temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insert(int val)
{
    node* newNode = new node;
    newNode->data = val;
    newNode->next = nullptr;

    if(linkedHead == nullptr)
    {   
        createBlock(&linkedHead);
        currentBlock->listHead = newNode;
        tail = newNode;
        return;
    }
    else if(currentBlock->nodeCount == SIZE)
    {
        createBlock(&currentBlock->next);
        tail->next = newNode;
        currentBlock->listHead = newNode;
        tail = newNode;
        return;
    }
    
    tail->next = newNode;
    tail = newNode;


    ++currentBlock->nodeCount;
    tail = newNode;
}

void createBlock(linkedBlock** ptr)
{
    *ptr = new linkedBlock;
    (*ptr)->listHead = nullptr;
    (*ptr)->next = nullptr;
    (*ptr)->nodeCount = 0;
    currentBlock = *ptr;
}