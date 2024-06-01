#include<iostream>
#include<cstdlib>
using namespace std;

int top = -1;

struct Node
{
    int data;
    Node *link;
};

class LinkedStack
{
    Node *start;

public:
    LinkedStack()
    {
        start = NULL;
    }
    void PUSH();
    void POP();
    void DISPLAY();
    void FindNode();
};

void LinkedStack::PUSH()
{
    Node *ptr = new Node;
    int n;

    cout<<"Enter data: ";
    cin>>n;
    ptr->data = n;
    ptr->link = start;
    start = ptr;
    top++;
}

void LinkedStack::POP()
{
    if(top<0)
    {
        cout<<"STACK UNDERFLOW............."<<endl;
    }
    else
    {
        Node *ptr = start;
        cout<<ptr->data<<" is POPed"<<endl;
        start = ptr->link;
        top--;
    }
}

void LinkedStack::DISPLAY()
{
    Node *ptr = start;
    if(top<0)
    {
        cout<<"Linked List is Empty.........."<<endl;
    }
    else
    {
        while(ptr!=NULL)
        {
            cout<<ptr->data<<"-------------->";
            ptr = ptr->link;
        }
        cout<<"NULL";
        cout<<endl;
    }
}

void LinkedStack::FindNode()
{
    Node *ptr = start;
    int n, index = top, flag=0;

    cout<<"Enter element you want to find: ";
    cin>>n;
    if(top<0)
    {
        cout<<"Linked List is Empty bro......................"<<endl;
    }
    else
    {
        while(ptr!=NULL)
        {
            if(n == ptr->data)
            {
                cout<<"Element: "<<n<<" is at Node: "<<index<<endl;
                flag=1;
                break;
            }
            else
            {
                ptr = ptr->link;
                index--;
            }
        }
        if(flag==0)
        {
            cout<<"Element: "<<n<<" is not in the Linked List..............."<<endl;
        }
    }
}

int main()
{
    LinkedStack LS;
    char ch='y';
    int choice;
    do
    {
        system("cls");
        cout<<"Press 1 for PUSH\nPress 2 for POP\nPress 3 for DISPLAY\nPress 4 for Find Location of data\nPress anything for EXIT\n"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1: LS.PUSH();
            break;
            case 2: LS.POP();
            break;
            case 3: LS.DISPLAY();
            break;
            case 4: LS.FindNode();
            break;
            default: cout<<"Invalid Input";
        }
        cout<<"Do you want to Continue(y/n): ";
        cin>>ch;
    }
    while(ch=='y'||ch=='Y');
}
