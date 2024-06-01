#include<iostream>
#include<unistd.h>
#include<stdlib.h>

using namespace std;

int time_slice;
int n_process = 0;
int time_count;

struct Node
{
    char process;
    int A_T, E_T;
    Node *next;
    Node *prev;
};

class Doubly_Circular_LL
{
    Node *start;
    Node *head;
    Node *tail;

public:
    Doubly_Circular_LL()
    {
        start = NULL;
        head = NULL;
        tail = NULL;
    }

    void Create();
    void Execute();
    void Display();
};

int main()
{
    Doubly_Circular_LL DCL;
    char ch='y';
    cout<<"Enter Size of Queue: ";
    int choice;
    do
    {
        system("cls");
        cout<<"Press 1 for Process\nPress 2 for Execute Processes\nPress 3 for DISPLAY\nPress anything for EXIT\n"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1: DCL.Create();
            break;
            case 2: DCL.Execute();
            return 0;
            case 3: DCL.Display();
            break;
            default: cout<<"Invalid Input";
        }
        cout<<"Do you want to Continue(y/n): ";
        cin>>ch;
    }
    while(ch=='y'||ch=='Y');
}

void Doubly_Circular_LL::Create()
{
    cout<<"Enter number of processes you want to Enter: ";
    cin>>n_process;
    int n=0;

    while(n < n_process)
    {
        Node *ptr = new Node;
        cout<<"Enter Name of Process(char): ";
        cin>>ptr->process;
        cout<<"Enter Arrival time: ";
        cin>>ptr->A_T;
        cout<<"Enter Execution time: ";
        cin>>ptr->E_T;
        if(head==NULL && tail==NULL)
        {
            ptr->prev = NULL;
            head = ptr;
            ptr->next = head;
            tail = ptr;
        }
        else
        {
            start = head;
            do
            {
                if(start->A_T > ptr->A_T)
                {
                    if(start == head)
                    {
                        head->prev = ptr;
                        ptr->next = head;
                        ptr->prev = NULL;
                        head = ptr;
                        tail->next = head;
                        break;
                    }
                    else
                    {
                        start->prev->next = ptr;
                        ptr->prev = start->prev;
                        start->prev = ptr;
                        ptr->next = start;
                        break;
                    }
                }
                else
                {
                    start = start->next;
                }
            }
            while(start != head);
            if(ptr->A_T > tail->A_T)
            {
                tail->next = ptr;
                ptr->prev = tail;
                ptr->next = head;
                tail = ptr;
            }
        }
        n++;
    }
}


void Doubly_Circular_LL::Display()
{
    if(head==NULL && tail==NULL)
    {
        cout<<"Not any Process in Queue............"<<endl;
    }
    else
    {
        Node *s = head;
        do
        {
            cout<<"|"<<s->process<<"|"<<s->A_T<<"|"<<s->E_T<<"|----";
            s = s->next;
        }
        while(s->prev!=NULL);
        cout<<"---->"<<head->process<<endl;
    }
}

void Doubly_Circular_LL::Execute()
{
    cout<<"Enter Time Slice: ";
    cin>>time_slice;
    time_count = 0;
    if(head==NULL && tail==NULL)
    {
        cout<<endl<<"Process Queue is Empty.............."<<endl;
    }
    else
    {
        while(n_process != 0)
    {
        start=head;
        do
        {
            if(start->A_T <= time_count)
            {
                if(start->E_T > time_slice)
                {
                    cout<<"|"<<start->process<<"|"<<time_slice<<"|-----";
                    start->E_T -= time_slice;
                    time_count += time_slice;
                    start = start->next;
                    sleep(time_slice);
                    continue;
                }
                else if(start->E_T <= time_slice)
                {
                    if(head == tail)
                    {
                        cout<<"|"<<start->process<<"|"<<start->E_T<<"|----";
                        time_count += start->E_T;
                        sleep(start->E_T);
                        start = NULL;
                        head = NULL;
                        tail = NULL;
                        cout<<" Empty"<<endl;
                        cout<<"All Processes are completed"<<endl;
                        n_process--;
                        continue;
                    }
                    else if(start == head)
                    {
                        cout<<"|"<<start->process<<"|"<<start->E_T<<"|----";
                        time_count += start->E_T;
                        sleep(start->E_T);
                        start->E_T = 0;
                        start->next->prev = NULL;
                        start = start->next;
                        head = start;
                        tail->next = head;
                        n_process--;
                        continue;
                    }
                    else if(start == tail)
                    {
                        cout<<"|"<<start->process<<"|"<<start->E_T<<"|----";
                        time_count += start->E_T;
                        sleep(start->E_T);
                        start->prev->next = head;
                        tail = start->prev;
                        start = start->next;
                        n_process--;
                        continue;
                    }
                    else
                    {
                        cout<<"|"<<start->process<<"|"<<start->E_T<<"|----";
                        time_count += start->E_T;
                        sleep(time_slice);
                        start->prev->next = start->next;
                        start->next->prev = start->prev;
                        start = start->next;
                        n_process--;
                        continue;
                    }
                }
                else
                {
                    cout<<"EXTRA"<<endl;
                }
            }
            else
            {
                time_count++;
                start = head;
                continue;
            }
        }
        while(start != head);
      }
    }
}
