#include<iostream>
using namespace std;

string str, post_str;
int priority, top=-1;
char ar[50];

void STACK(char op, int priority);
void set_postfix(char ch);

int main()
{
    cout<<"Enter String: ";
    cin>>str;

    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='+' || str[i]=='-')
        {
            priority = 1;
            STACK(str[i], priority);
        }
        else if(str[i]=='*' || str[i]=='/' || str[i]=='%')
        {
            priority = 2;
            STACK(str[i], priority);
        }
        else if(str[i]=='$' || str[i]=='^')
        {
            priority = 3;
            STACK(str[i], priority);
        }
        else if(str[i]=='(' || str[i]==')' || str[i]=='[' || str[i]==']' || str[i]=='{' || str[i]=='}')
        {
            priority = 8;
            STACK(str[i], priority);
        }
        else
        {
            set_postfix(str[i]);
        }
    }

    while(top>-1)
       {
           set_postfix(ar[top]);

           top = top - 1;
       }

    cout<<"POSTFIX String: "<<post_str;
}


void STACK(char ch, int priority)
{
    int stack_ch_pri;
    char stack_ch;

    if(top<0)
    {
        top += 1;
        ar[top] = ch;
    }
    else
    {
        if(ar[top]=='+' || ar[top]=='-')
        {
            stack_ch_pri = 1;
        }
        else if(ar[top]=='*' || ar[top]=='/' || ar[top]=='%')
        {
            stack_ch_pri = 2;
        }
        else if(ar[top]=='$' || ar[top]=='^')
        {
            stack_ch_pri = 3;
        }
        else if(ar[top]=='(' || ar[top]=='[' || ar[top]=='{')
        {
            stack_ch_pri = 0;
        }
        else{}

        if(ch=='(' || ch=='[' || ch=='{')
        {
            top += 1;
            ar[top] = ch;
        }

        else if(ch==')')
        {
            while(ar[top] != '(')
            {
                set_postfix(ar[top]);
                top = top - 1;
            }
            top -= 1;
        }
        else{}

        if(ch!='(' && ch!=')')
        {
            if(stack_ch_pri >= priority)
            {
                stack_ch = ar[top];
                ar[top] = ch;
                set_postfix(stack_ch);
            }
            else
            {
                top += 1;
                ar[top] = ch;
            }
        }
    }
}


void set_postfix(char ch)
{
    post_str += ch;
}
