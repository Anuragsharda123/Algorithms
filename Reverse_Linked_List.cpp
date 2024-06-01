#include <iostream>
#include<cstdlib>

using namespace std;

struct Node
{
    int data;
    Node *link;
};

class LinkedList
{
    Node *start;
public:
    LinkedList()
    {
        start = NULL;
    }

    void Create();
    void Display();
    ~LinkedList();
};

void LinkedList::Create()
{
    Node *ptr;
    int x;
    char ch = 'y';
    while(ch == 'y')
    {
        ptr = new Node;
        cout<<"Enter number: ";
        cin>>x;

        ptr->data = x;
        ptr->link = start;

        start = ptr;
        cout.flush();
        cout<<endl;
        cout<<"Press y for continue\nPress anything to Exit\n";
        cin>>ch;
        cout<<endl;
    }
}

void LinkedList::Display()
{
    system("cls");
    Node *ptr=start;
    cout<<"\n\n";
    while(ptr!=NULL)
    {
        cout<<ptr->data<<"-------->";
        ptr = ptr->link;
    }
    cout<<"NULL";
}

LinkedList::~LinkedList()
{
    Node *ptr = start;
    cout<<"\n\nDistroyed Linked List..............."<<endl;
    while(ptr!=NULL)
    {
    ptr = ptr->link;
    delete start;
    start = ptr;
    }
}

int main()
{
    LinkedList LL;
    LL.Create();
    cout<<"LinkedList is:    ";
    LL.Display();
    return 0;
}
