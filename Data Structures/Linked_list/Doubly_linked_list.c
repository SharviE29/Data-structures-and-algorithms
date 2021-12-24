/*
Operations on Doubly Linked list
*/

#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};*first=NULL;//creating a global pointer

void create(int A[],int n)
{
    struct Node *t,last;
    int i;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;
    for(i=1;i<n;i++)//adding a node at the end of the list
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p)
{
        while(p!=NULL)
        {
            printf("%d",p->data);
            p=p->next;
        }
        printf("\n");
}

int length(struct Node *p)
{
    int len=0;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}
void Insert(struct Node*p,int index, int x)
{
    struct Node *t;
    int i;
    if(index <0 || index>length(p))
       return;
    //inserting a node at the first index
    if(index==0)
    {   
        /*
        creating a new node
        adding data to the node
        and linking the nodes
        for inserting at the first position, 
        3 links are modified.
        Time complexity is o(1).
        */
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }  
    //inserting a new node at any other position
    else 
    {
       /*
        creating a new node
        adding data to the node
        and linking the nodes
        for inserting at the first position, 
        4 links are modified.
        Time complexity is o(n).(Worst case complexity)
        */
       for(i=0;i<index-1;i++)
       {
           p=p->next;
       } 
       t=(struct Node *)malloc(sizeof(struct Node));
       t->next=p->next;
       t->prev=p;
       if(p->next)//if p is not the last node.
       //i.e p->next exists.
       //if the last node doesnt exist, then 3 links are modified. Otherwise 4 links will be modified.
       {
           p->next->prev=t;
       }
       p->next=t;
    }
}
int Delete(struct Node *p,int index)
{
    //struct Node *q;
    int x=-1,i;
    if(index<1 || index>length(p))
      return -1;
    if (index==1)
    {
        first=first->next;
        if(first)
        {
            first->prev=NULL;
        }
        x=p->data;
        free(p);
    }
    else{
       for(i=0;i<index-1;i++)
       {
           p=p->next;  
       } 
       p->prev->next=p->next;
       if(p->next)
       {
           p->next->prev=p->prev;
       }
       x=p->data;
       free(p);
    }   
    return x; 
}
void Reverse(struct Node *p)
{
    struct Node *temp;
    while(p!=NULL)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;//move p to the previous node
        //here the pointers are interchanged and hence making p point to the previous node is going to take it to the last node
        if(p!=NULL && p->next==NULL)
        {
            first=p;
        }
    }
}
int main()
{
    int A[]={10,20,30,40,50};
    create(A,5);
    printf("%d", length(first));
    Display(first);
    Insert(first,2,25);
    Delete(first,1);
    Reverse(first);
    return 0;
}    
