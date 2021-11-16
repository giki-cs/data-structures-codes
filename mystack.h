#ifndef MYSTACK_H
#define MYSTACK_H

class mystack
{
private:
    static mystack* top;
    mystack* prev;
    char data;
public:
    static void push(char ch);
    static bool isEmpty();
    static char pop();
    static char see();
};

#endif