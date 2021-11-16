#include "mystack.h"

mystack* mystack::top = 0;

void mystack::push(char ch)
{
    mystack *temp = new mystack;
    temp->data = ch;
    temp->prev = top;
    top = temp;
}

char mystack::pop()
{
    if (top == 0)
        return ' ';
    
    char c = top->data;
    mystack *temp = top;
    top = top->prev;
    delete temp;
    return c;
}

bool mystack::isEmpty()
{
    if (top == 0)
        return true;

    return false;
}

char mystack::see()
{
    return top->data;
}