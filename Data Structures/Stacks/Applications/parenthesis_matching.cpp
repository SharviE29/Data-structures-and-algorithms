/********************
 
 Stacks for parenthesis matching

 *******************/

#include<iostream>
using namespace std;
class Node
{ 
  public:
  char data;
  Node *next;
};
class Stack
{  
private:
   int size;
   Node *top;
   char *s;
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
   int isBalanced(char *exp);
};
int Stack::isBalanced(char *exp)
{
    int i;
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
        {
            Push(exp[i]);
        }
        else if(exp[i]==')')
        {
            if(top!=NULL)
            {
                Pop();
            }
            else
            {
                return 0;
            }
        }
    }
    if(top==NULL)
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
    char *exp="((a+b)-(c*d)))";
    Stack st;
    int result=st.isBalanced(exp);
    if (result==1)
    {
        cout<<"The expression is well balanced !!"<<endl;
    }
    else
    {
        cout<<"The expression isn't well balanced !!"<<endl;
    }
    return 0;
}
/******************
 * OUTPUT *
 FOR ((a+b)-(c*d))
 The expression is well balanced !!

 FOR ((a+b)-(c*d)))
 FOR (((a+b)-(c*d))
 The expression isn't well balanced !!

 *******************/