#include <iostream>
#include <string>
#include "mystack.h"
using namespace std;

string toPostfix( string );
int prec(char);

int main()
{
    string exp = "k+l-m*n+(o^p)*w/u/v/*t+q";
                
    cout << toPostfix(exp);

    return 0;
}

string toPostfix(string exp)
{
    int size = exp.length();
    char str[size];
    int j = 0;
    int brac = 0;

    for(int i=0; i<size; ++i)
    {
        char ch = exp[i];

        if ( ch == '(' )
        {
            mystack::push(ch);
            ++brac;
        }                               
        else if ( ch == ')' )           
        {                               
            while ( mystack::see() != '(' )
                str[j++] = mystack::pop();
            mystack::pop();
            --brac;
        }
        else if ( ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '^' ) // left to right
        {
            if ( mystack::isEmpty() || brac || prec(ch) > prec(mystack::see()) )
            {
                mystack::push(ch);
                continue;
            }

            str[j++] = mystack::pop();

            if ( prec(mystack::see()) == prec(ch) )                
                mystack::push(ch);
            else
                --i;
        }
        else
            str[j++] = ch;
    }

    while ( !mystack::isEmpty() )
    {
        str[j++] = mystack::pop();
    }

    return str;
}

int prec(char op)
{
    switch(op)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        case '(':
            return 4;
    }

    return 0;
}