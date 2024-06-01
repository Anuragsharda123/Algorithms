#include<iostream>
#include<conio.h>
using namespace std;

#define MAXSIZE 5

class menuqueue
{
	int front,rear;
	int q[MAXSIZE];
	public:
	void qinsert();
	void qinsert1();
	void qdelete();
	void qdelete1();
	void qdisplay();
	void max();
	void min();
	menuqueue()
	{
		front=-1,rear=-1;
	}
};

int main()
{

	int choice;
	char ch;
	menuqueue me;
	do
	{
		cout<<endl<<"1-->insert at rear"<<endl;
		cout<<"2-->insert at front"<<endl;
		cout<<"3-->delete from front"<<endl;
		cout<<"4-->delete from rear"<<endl;
		cout<<"5-->display"<<endl;
		cout<<"6-->display max"<<endl;
		cout<<"7-->display min"<<endl;
		cout<<"8-->exit"<<endl;
		cout<<"enter your choice: "<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				me.qinsert();
				break;
            case 2:
                me.qinsert1();
                break;
			case 3:
				me.qdelete();
				break;
            case 4:
                me.qdelete1();
                break;
			case 5:
				me.qdisplay();
				break;
			case 6:
				me.max();
				break;
			case 7:
				me.min();
				break;
			case 8:
				return 0;
		}
		cout<<"Do you want to continue?(Y/N) ";
		cin>>ch;
	}while(ch == 'y'||ch=='Y');
	getch();
}
void menuqueue::qinsert()
{
	int num;
	if(rear==(MAXSIZE-1))
	{
		cout<<"queue is full"<<endl;
		return;
	}
	else
	{
		cout<<"enter no\n";
		cin>>num;
		rear=rear+1;
		q[rear]=num;
		if(front==-1)
		{
			front++;
		}
	}
	return;
}
void menuqueue::qinsert1()
{
	int num;
	if(front==-1)
	{
		cout<<"queue is full"<<endl;
		return;
	}
	else
	{
		cout<<"enter no\n";
		cin>>num;
		front=front-1;
		q[front]=num;

	}
	return;
}
void menuqueue::qdelete()
{
	int num;
	if(front==-1)
	{
	cout<<"queue empty"<<endl;
	getch();
	}
	else
	{
		if(front==rear)
			front=rear=-1;
		else
		{
			num=q[front];
			cout<<"deleted item="<<q[front];
			front++;
		}
	}
}
void menuqueue::qdelete1()
{
	int num;
	if(front==-1)
	{
	cout<<"queue empty"<<endl;
	getch();
	}
	else
	{
		if(front==rear)
			front=rear=-1;
		else
		{
			num=q[rear];
			cout<<"deleted item="<<q[rear];
			rear--;
		}
	}
}
void menuqueue::qdisplay()
{
	int i;
	if(front==-1)
	{
		cout<<"queue empty\n";
		return;
	}
	else
	{
		cout<<endl<<"The status of the queue"<<endl;
		for(i=front;i<=rear;i++)
		{
			cout<<endl<<q[i];
		}
	}
	cout<<endl;
}

void menuqueue::max()
{
	if (front<rear)
	{
		int mx = q[front];
		for (int i = front+1; i <= rear; i++)
		{
			if (q[i] > q[front])
			{
				mx = q[i];
			}
		}
		cout<<"\nMaximum element in the queue is "<<mx<<endl;
	}
}


void menuqueue::min()
{
	if (front<rear)
	{
		int mn = q[front];
		for (int i = front+1; i <= rear; i++)
		{
			if (q[i] < q[front])
			{
				mn = q[i];
			}
		}
		cout<<"\nMinimum element in the queue is "<<mn<<endl;
	}
}
