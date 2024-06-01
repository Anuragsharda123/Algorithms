#include<iostream>
#include<cstdlib>
using namespace std;

struct Node
{
    int info;
    Node *link;
};

class Linked_Queue
{
    Node *head;
    Node *tail;
public:
    Linked_Queue()
    {
        head = NULL;
        tail = NULL;
    }
    void Enqueue();
    void Dequeue();
    void Display();
};

int main()
{
    Linked_Queue LQ;
    char ch='y';
    cout<<"Enter Size of Queue: ";
    int choice;
    do
    {
        system("cls");
        cout<<"Press 1 for Enqueue\nPress 2 for Dequeue\nPress 3 for DISPLAY\nPress anything for EXIT\n"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1: LQ.Enqueue();
            break;
            case 2: LQ.Dequeue();
            break;
            case 3: LQ.Display();
            break;
            default: cout<<"Invalid Input";
        }
        cout<<"Do you want to Continue(y/n): ";
        cin>>ch;
    }
    while(ch=='y'||ch=='Y');
}

void Linked_Queue::Enqueue()
{
    Node *ptr = new Node;
    int n;
    cout<<"Enter info: ";
    cin>>n;
    ptr->info = n;
    ptr->link = NULL;
    if(head==NULL && tail==NULL)
    {
        head = ptr;
        tail = ptr;
    }
    else
    {
        tail->link = ptr;
        tail = ptr;
    }
}

void Linked_Queue::Display()
{
    if(head==NULL)
    {
        cout<<"Queue is Empty............"<<endl;
    }
    else
    {
    Node *ptr = new Node;
    ptr = head;
    cout<<"Queue: ";
    while(ptr!=NULL)
    {
        cout<<ptr->info<<"---->";
        ptr = ptr->link;
    }
    cout<<"NULL"<<endl;
    }
}

void Linked_Queue::Dequeue()
{
    if(head==NULL)
    {
        cout<<"Queue Underflow............"<<endl;
    }
    else
    {
        cout<<"Item "<<head->info<<"is deleted from Queue............."<<endl;
        head = head->link;

    }
}
