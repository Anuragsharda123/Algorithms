#include<iostream>
#include<cstdlib>
using namespace std;

struct Node
{
    int data;
    Node *link;
};
Node *temp;
Node *First;

class LinkedList
{
public:
    void Create();
    void Display();
    ~LinkedList();
};

void LinkedList::Create()
{
    Node *ptr;

    int x,a=0;
    char ch='y';
    while(ch=='y')
    {
        ptr = new Node;
        cout<<"Enter data: ";
        cin>>x;

        if(a==0)
        {
            ptr->data = x;
            ptr->link = NULL;
            temp = ptr;
            First = ptr;
            a=1;
        }
        else
        {
            ptr->data = x;
            ptr->link = NULL;
            temp->link = ptr;
            temp = ptr;
        }
        cout<<"\nPress y to Continue.\nPress n to Exit\n";
        cout<<"Choose: ";
        cin>>ch;
        cout<<endl;
    }
}

void LinkedList::Display()
{
    system("cls");
    cout<<endl;
    Node *ptr = First;

    while(ptr != NULL)
    {
        cout<<ptr->data<<"-------->";
        ptr = ptr->link;
    }
    cout<<"NULL\n\n";
}

LinkedList::~LinkedList()
{
    Node *ptr = First;
    Node *next;
    cout<<"Linked List is Destroyed...........\n";
    while(ptr!=NULL)
    {
        next = ptr->link;
        delete ptr;
        ptr = next->link;
    }
}

int main()
{
    LinkedList LL;
    LL.Create();
    cout<<"Linked List: ";
    LL.Display();
}
