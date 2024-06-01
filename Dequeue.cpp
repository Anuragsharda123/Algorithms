#include<iostream>
#include<stdlib.h>
using namespace std;

class DEQueue
{
private:
    int x, f=-1, r=-1, DQ[7];

public:
    void addatbeg();
    void addatend();
    void dltatbeg();
    void dltatend();
    void display();
};

int main()
{
    DEQueue q;
    int choice;
    do
    {
        cout<<"Press 1 ---> Insert at Beginning"<<endl;
        cout<<"Press 2 ---> Delete from Beginning"<<endl;
        cout<<"Press 3 ---> Insert at End"<<endl;
        cout<<"Press 4 ---> Delete from End"<<endl;
        cout<<"Press 5 ---> Display"<<endl;
        cout<<"Press 6 ---> Exit\n"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1: q.addatbeg();
            break;
            case 2: q.dltatbeg();
            break;
            case 3: q.addatend();
            break;
            case 4: q.dltatend();
            break;
            case 5: q.display();
            break;
            case 6: break;
        }
    }
    while(choice!=6);
}

void DEQueue::addatbeg()
{
    system("cls");
    if(f==0)
    {
        cout<<"Queue OverFlow.........\n"<<endl;
    }
    else
    {
        cout<<"Enter Element you want to Enter: ";
        cin>>x;
        int flag = 0;

        for(int i=f; i<=r; i++)
        {
            if(DQ[i]==x)
            {
                flag=1;
            }
        }

        if(flag==1)
        {
            cout<<x<<" is already in the Queue........."<<endl;
        }
        else
        {
            if(r<0 && f<0)
            {
                DQ[f+1] = x;
                f++;
                r++;
            }
            else if(f==r)
            {
                DQ[f-1] = x;
                f--;
            }
            else
            {
                DQ[f-1] = x;
                f--;
            }
        }
    }
}

void DEQueue::dltatbeg()
{
    system("cls");
    if((r<0 && f<0) || (r<f))
    {
        cout<<"Queue UnderFlow........."<<endl;
    }
    else
    {
        f++;
        cout<<"Item Deleted from Front........."<<endl;
    }
}

void DEQueue::addatend()
{
    system("cls");
    if(r==6)
    {
        cout<<"Queue OverFlow..........."<<endl;
    }
    else
    {
        cout<<"\nEnter element you want to Enter: ";
        cin>>x;
        int flag = 0;

        for(int i=f; i<=r; i++)
        {
            if(DQ[i]==x)
            {
                flag=1;
            }
        }

        if(flag==1)
        {
            cout<<x<<" is already in the Queue........"<<endl;
        }
        else
        {
            DQ[r+1] = x;

            if(f<0 && r<0)
            {
                r++;
                f++;
            }
            else
            {
                r++;
            }
        }
    }
}

void DEQueue::dltatend()
{
    system("cls");
    if((f<0 && r<0) || (r<f))
    {
        cout<<"Queue UnderFlow.........."<<endl;
    }
    else
    {
        r--;
    }
}

void DEQueue::display()
{
    system("cls");
    if((f<0 && r<0) || (r<f))
    {
        cout<<"Queue is Empty.........."<<endl;
    }
    else
    {
        for(int i=f; i<=r; i++)
        {
            cout<<"Queue["<<i<<"]: "<<DQ[i]<<endl;
        }
    }
}
