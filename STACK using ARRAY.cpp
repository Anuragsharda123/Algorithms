#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

int n, ITEM, c, j=1, TOP=-1;
int S[100];
void PUSH();
void POP();
void DISPLAY();

int main()
{
    cout<<"Enter Size of STACK: ";
    cin>>n;

    while(j)
    {
        system("cls");
        cout<<"Press 1 for PUSH ITEM"<<endl<<"Press 2 for POP ITEM"<<endl<<"Press 3 for DISPLAY ITEM"<<endl<<"Press 4 for EXIT"<<endl;
        cout<<"Enter Choice: ";
        cin>>c;
        switch(c)
        {
            case 1:PUSH();
            break;
            case 2:POP();
            break;
            case 3:DISPLAY();
            break;
            case 4:j=0;
            break;
            default: cout<<"Wrong Input........"<<endl;
            break;
        }
    }
    return 0;
}

void POP()
{
    if(TOP<=-1)
    {
        cout<<"Underflow..........."<<endl;
        cout<<"Press Enter to Continue.......";
        getch();
    }
    else
    {
        cout<<"Value at "<<TOP<<" Index: "<<S[TOP]<<" is deleted"<<endl;
        TOP--;
        cout<<"Press Enter to Continue.......";
        getch();
    }
}

void PUSH()
{
    if(TOP>=n-1)
    {
        cout<<"STACK OVERFLOW............."<<endl;
        cout<<"Press Enter to Continue.......";
        getch();
    }
    else
    {
        cout<<"Enter ITEM: ";
        cin>>ITEM;
        TOP = TOP+1;
        S[TOP] = ITEM;
        cout<<"Press Enter to Continue.......";
        getch();
    }
}

void DISPLAY()
{
    if(TOP>=0)
    {
        for(int i=TOP;i>=0;i--)
        {
            cout<<"STACK["<<i<<"]: "<<S[i]<<endl;
        }
        cout<<"Press Enter to Continue.......";
        getch();
    }
    else
    {
        cout<<"STACK is EMPTY........"<<endl;
        cout<<"Press Enter to Continue.......";
        getch();
    }
}
