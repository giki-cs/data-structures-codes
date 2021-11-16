#include <iostream>
#include <string>
using namespace std;

int precedence(char);

class stack
{
    public:
        stack(): top(nullptr){}
        bool isEmpty() { if( top == nullptr ) return true; else return false; }
        void push(char val)
        {
            if( top == nullptr )
            {
                top = new node;
                top->prev = nullptr;
            }
            else
            {
                top->next = new node;
                top->next->prev = top;
                top = top->next;
            }
            top->next = nullptr;
            top->val = val;
        }
        char pop() // not used when stack is empty
        {   
            char a = top->val;

            node* temp = top;
            top = top->prev;
            delete temp;
            temp = nullptr;

            return a;
        }
        char see()
        {
            return top->val;
        }

    private:
    struct node
    {
        char val;
        node* next;
        node* prev;
    };
    node* top;
};

void ip(string);

int main()
{
    string s = "k+l-m*n+(o^p)*w/u/v*t+q ";
    cout << "Infix: " << s << endl;
    cout << "Postfix: "; 
    ip(s);

    return EXIT_SUCCESS;
}

void ip(string s)
{
    int i=0;
    int j=0;
    stack stk;
    char newStr[s.length()];

    while(s[i] != '\0')
    {
        if ( s[i] == ')' )
        {
            while( stk.see() != '(' )
                newStr[j++] = stk.pop();
            while (stk.see() == '(' )
                stk.pop();
        }
        else if( s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^' || s[i] == '(' )
        {
            if( stk.isEmpty() || s[i] == '(')
                stk.push(s[i]);
            else if ( precedence(stk.see()) == precedence(s[i]) ) 
            {
                if( s[i] != '^' ) // for associativity left to right only
                    newStr[j++] = stk.pop();
                stk.push(s[i]);
            }
            
            else if ( precedence(stk.see()) < precedence(s[i]) )
                stk.push(s[i]);
            
            else
            {
                if ( stk.see() == '(' ) stk.push(s[i]);
                else
                {
                    newStr[j++] = stk.pop();
                    --i;
                }
            }
        }
        else
            newStr[j++] = s[i];
        ++i;
    } 
    while( ! stk.isEmpty() )
        newStr[j++] = stk.pop();
    i=0;
    while(i != j)
        cout << newStr[i++];
    cout << endl;
}

int precedence(char a)
{
    switch(a)
    {
        case '(':
        case ')':
            return 3;
        case '/':
        case '*':
            return 2;
        case '+':
        case '-':
            return 1;
    }
    return 0;
}