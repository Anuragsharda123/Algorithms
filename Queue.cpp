#include<iostream>
#include<stdlib.h>
using namespace std;

class Queue
{
private:
    int f=-1, r=-1, Q[5], n;

public:
    int Enqueue()
    {
        cout<<"Enter Item you want to Insert: ";
        cin>>n;

        if(f<0 && r<0)
        {
            f++;
            r++;
        }
        else if(r == 4)
        {
            cout<<"Queue Overflow........."<<endl;
            return 0;
        }
        else
        {
            r++;
        }
        Q[r]=n;
        cout<<"Item Inserted"<<endl;
    }

    void Dequeue()
    {
        if(r<0 && f<0)
        {
            cout<<"Queue Underflow........."<<endl;
        }
        else if(r==f)
        {
            r--;
            f--;
            cout<<"Item Deleted"<<endl;
        }
        else
        {
            for(int i=0;i<r;i++)
            {
                Q[i]=Q[i+1];
            }
            r--;
            cout<<"Item Deleted"<<endl;
        }
    }
    void Display()
    {
        if(r<0 && f<0)
        {
            cout<<"Queue is Empty........"<<endl;
        }
        else
        {
            for(int i=0;i<=r;i++)
            {
                cout<<"Queue["<<i<<"]: "<<Q[i]<<endl;
            }
        }
    }
};
int main()
{
    Queue q;
    int choice;

    do
    {

        cout<<"Press 1 ---> Insert"<<endl;
        cout<<"Press 2 ---> Delete"<<endl;
        cout<<"Press 3 ---> Display"<<endl;
        cout<<"Press 4 ---> Exit\n"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1: q.Enqueue();
            break;
            case 2: q.Dequeue();
            break;
            case 3: q.Display();
            break;
            case 4: break;
        }
    }
    while(choice!=4);
    return 0;
}
