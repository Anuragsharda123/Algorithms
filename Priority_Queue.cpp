#include<iostream>
#include<cstdlib>

using namespace std;
int index = -1;
struct Node
{
    int info;
    int priority, i;
    Node *link = NULL;
};

class Priority_Queue
{
    Node *head;
    Node *tail;
public:
    Priority_Queue()
    {
        head=NULL;
        tail=NULL;
    }
    void Enqueue();
    void Dequeue();
    void Display();
    void Swap(int a, int b);
};

int main()
{
    Priority_Queue PQ;
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
            case 1: PQ.Enqueue();
            break;
            case 2: PQ.Dequeue();
            break;
            case 3: PQ.Display();
            break;
            default: cout<<"Invalid Input";
        }
        cout<<"Do you want to Continue(y/n): ";
        cin>>ch;
    }
    while(ch=='y'||ch=='Y');

}

void Priority_Queue::Swap(int n, int n_pri)
{
    Node *ptr = new Node;
    Node *start = head;
    ptr->info = n;
    ptr->priority = n_pri;
    index++;
    ptr->i = index;

    if(head==NULL && tail==NULL)
    {
        ptr->link = start;
        head = ptr;
        tail = ptr;
    }
    else
    {
        if(n_pri < start->priority)
        {
            ptr->link = head;
            head = ptr;
        }
        else
        {
            while(start->link!=NULL)
            {
                if(n_pri>=start->link->priority)
                {
                    start = start->link;
                }
                else
                {
                    break;
                }
            }

            if(start->link!=NULL)
            {
                ptr->link = start->link;
                start->link = ptr;
            }
            else
            {
                ptr->link=NULL;
                tail->link = ptr;
                tail = ptr;
            }
        }
    }
}

void Priority_Queue::Enqueue()
{
    int n, n_pri;

    cout<<"Enter info: ";
    cin>>n;

    cout<<"Enter Priority: ";
    cin>>n_pri;

 //   Swap(int n, int n_pri);
}


void Priority_Queue::Dequeue()
{
    if(head==NULL)
    {
        cout<<"Queue is Empty............"<<endl;
    }
    else
    {
        cout<<head->info<<" is deleted from the Queue........."<<endl;
        head = head->link;
    }
}

void Priority_Queue::Display()
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
            cout<<ptr->info<<"|"<<ptr->priority<<"|"<<ptr->i<<"|---->";
            ptr = ptr->link;
        }
        cout<<"NULL"<<endl;
    }
}
