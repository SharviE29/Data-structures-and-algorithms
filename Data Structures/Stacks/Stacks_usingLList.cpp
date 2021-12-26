/****************
 
 Stacks using linked lists

****************/

#include<stdlib.h>
#include<stdio.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
}*top=NULL;//global pointer

void Push(int x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    
    if(t==NULL)
    {
        printf("Stack is full \n");
    }
    else
    {
          t->data=x;
          t->next=top;
          top=t;
    }
}
int Pop()
{   
    int x=-1;
    struct Node *t;
    if(top==NULL)
    {
        printf("Stack is empty \n");
    }
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}
void display()
{
    struct Node *p;
    p=top;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main()
{
    Push(10);
    Push(20);
    Push(30);
    Push(40);
    display();
    printf("%d",Pop());
    return 0;
}
