#include<iostream>
#include<cstdlib>
using namespace std;

struct Node
{
    int data;
    Node *link;
};
int ct=-1;
Node *temp;
Node *First;
void findnode(int n);

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
    char o = 'y';
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
            ct++;
            a=1;
        }
        else
        {
            ptr->data = x;
            ptr->link = NULL;
            temp->link = ptr;
            temp = ptr;
            ct++;
        }
        cout<<"\nPress y to Continue.\nPress n to Exit\n";
        cout<<"Choose: ";
        cin>>ch;
        cout<<endl;
    }
}

void LinkedList::Display()
{
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
    char o;
    int num;
    LinkedList LL;
    LL.Create();

    cout<<"Do you want to find a node:";
    cin>>o;
    if(o=='y')
    {
        cout<<"Enter number you want to find: ";
        cin>>num;
        findnode(num);
    }
    cout<<"Linked List: ";
    LL.Display();
}

void findnode(int n)
{
    system("cls");
    Node *ptr = First;
    int cc = -1, flag=0;

    while(ptr!=NULL)
    {
        cc++;
        if(n == ptr->data)
        {
            cout<<"Number: "<<n<<" is at node: "<<cc<<endl;
            flag++;
            break;
        }
        ptr = ptr->link;
    }
    if(flag==0)
    {
        cout<<"Element: "<<n<<" is not in the LinkedList..........."<<endl;
    }
}

/*void findnode(int n)
{
    system("cls");
    Node *ptr = First;
    int cc = -1, flag=0;

    while(ptr->data != n)
    {
        flag=1;
        cc++;
        ptr = ptr->link;
        if(ct==cc)
        {
            flag=0;
            cout<<"Element: "<<n<<" is not in the LinkedList..........."<<endl;
            break;
        }
    }
    if(flag!=0)
    {
        cout<<"Number: "<<n<<" is at node: "<<cc+1<<endl;
    }
}*/
