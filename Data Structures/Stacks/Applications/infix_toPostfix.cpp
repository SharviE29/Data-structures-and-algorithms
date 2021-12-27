/*********************
 * 
 * Infix to Postfix conversion
 * 
 * ******************/

#include<iostream>
#include<strings.h>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
using namespace std;

class Node
{   
    public:
    char data;
    Node *next;
}*top=NULL;

void push(char x)
{
    Node *t=new Node();
    if(t==NULL)
    {
        cout<<"Stack overflow !!!"<<endl;
    }
    else
    {
       t->data=x;
       t->next=top;
       top=t;
    }
}
char pop()
{
    Node *t;
    char x=-1;
    if(top==NULL)
    {
        cout<<"Stack underflow!!!"<<endl;
    }
    else
    {  
       t=top;
       top=top->next;
       x=t->data;
       delete t;
    }
    return x;
}
void display()
{
    Node *p;
    p=top;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
//function to calculate the precedence of the operators
int precedence(char x)
{
  if(x=='+'|| x=='-')
  {
      return 1;
  }
  else if(x=='*'|| x=='/')
  {
      return 2;
  }
  else
  {
      return 0;
  }
}
int isOperand(char x)
{
    if(x=='+' || x=='/'|| x=='-'|| x=='*')
    {
       return 0;
    }
    else
    {
        return 1;
    }
}
char *inToPost(char *infix)
{
    int i=0,j=0;
    char *postfix;//a pointer to postfix array
    int len=strlen(infix);
    postfix=(char *)malloc((len+2)*sizeof(char));
    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
        {
            postfix[j++]=infix[i++];
        }
        else//operator found
        {
           if(precedence(infix[i])>precedence(top->data))
           {
               push(infix[i++]);
           }
           else
           {
               postfix[j++]=pop();
           }
        }
    }
    while(top!=NULL)//stack isn't empty
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    return postfix;
}
int main()
{
    char *infix="a+b*c-d/e";
    push('.');
    char *postfix=inToPost(infix);
    cout<<postfix;
    return 0;
}
/**********************
 * OUTPUT
 * abc*+de/-.
 * *******************/