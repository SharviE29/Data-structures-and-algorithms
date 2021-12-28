/************************
 
 Stacks using parenthesis matching
 With using brackets of type {},[],()

 ************************/

#include<iostream>
using namespace std;
const int MAX=20;
class Node
{ 
  public:
  char data;
  Node *next;
};
class Stack
{  
public:
   char str[MAX];
   int size;
   Node *top;
   //char *s;
public:
   Stack()
   {
       top=NULL;
   }
   void Push(char x)
   { 
       Node *t=new Node();
       if(t==NULL)
       {
           cout<<"Stack overflow !!!!"<<endl;

       }
       else
       {
            t->data=x;
            t->next=top;
            top=t;
       }
   }
   char Pop()
   {   
       char x=-1;
       Node *t=new Node();
       if(t==NULL)
       {
           cout<<"Stack underflow !!!!"<<endl;
       }
       else
       {
           x=t->data;
           t=top;
           top=top->next;
           delete t;
       }
       return x;
   }
   int isEmpty()
   {
       if(top)
       {
           return 1;
       }
       else
       {
           return 0;
       }
   }
   //int isBalanced(char *exp);
};
int isBalanced(string exp)
{
    Stack s;
    int i;
    char ch;
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(' || exp[i]=='['|| exp[i]=='{')
        {
            s.Push(exp[i]);
        }
        else if(exp[i]==')'|| exp[i]=='}'||exp[i]==']')
        {
            if(s.top!=NULL)
            {
                ch=s.Pop();
            }
            else
            {
                return 0;
            }
        }
    }
    if(s.top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    //char *exp="([a+b]-{c*d})";
    Stack s;
    string st;
    char choice;
    do
    {
        cout<<"Enter expression :";
        cin>>st;
        int result=isBalanced(st);
        if (result==1)
        {
            cout<<"The expression is well balanced !!"<<endl;
        }
        else
        {
            cout<<"The expression isn't well balanced !!"<<endl;
        }
        cout<<"Do you want to continue ? (y/n) :";
        cin>>choice;

    } while(choice=='Y' || choice=='y');
    return 0;
}