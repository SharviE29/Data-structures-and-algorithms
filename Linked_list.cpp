#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
}*first=NULL; //creating a global pointer

void create(int A[],int n)//Creating a linked list
{
    int i;
    struct Node *t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
       t=(struct Node *)malloc(sizeof(struct Node));
       t->data=A[i];
       t->next=NULL;
       last->next=t; 
       last=t;
    }
    
}

void display(struct Node*p)//displaying the linked list
{
  while(p!=NULL)
  {
      printf("%d",p->data);
      p=p->next;
  }
}
void RDisplay(struct Node *p)//displaying using recursive function
{
  if(p!=NULL)
  {
      //printf("%d", p->data," ");
      RDisplay(p->next);
      printf("%d", p->data," ");
  }
}

int count(struct Node *p)//counting the number of nodes
{
    int l=0;
    while(p)
    {
        l++;
        p=p->next;
    }
    return l;
}

int Rcount(struct Node *p)
{
    if (p!=NULL)
    {
        return Rcount(p->next)+1;
    }
    else 
      return 0;
}
int sum(struct Node *p)//sum of all the values in a linked list
{
    int s=0;
    while(p!=NULL)
    {
        s+=p->data;
        p=p->next;
    }
    return s;
}
int Rsum( struct Node *p)
{
    if(p==NULL)
    {
        return 0;
    }
    else 
     return Rsum(p->next)+p->data;
}
int Max(struct Node *p){//finding the maximum element in a linked list
    int max=INT32_MIN;//built in constant
    while(p)
    {
        if(p->data>max)
        {
            max=p->data;
        }
        p=p->next;
    }
    return max;
}
int Rmax(struct Node *p)
{
    int x=0;
    if(p==0)
        return INT32_MIN;
    x=Rmax(p->next);
    if(x>p->data)
      return x;
    else return p->data;      
}
struct Node *LSearch(struct Node *p,int key)
{
    while(p!=NULL)
    {
        if(key==p->data)
          return p;
        p=p->next;  
    }
    return NULL;
}
struct Node *RSearch(struct Node *p,int key)
{
    if(p==NULL)
       return NULL;
    if(key==p->data)
       return p;
    return RSearch(p->next,key);     
}
void insert(struct Node *p,int index, int x)
{
    struct Node *t; //creating a new node
    if(index<0||index>count(p))//invalid cases
       return;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    if(index==0)//inserting at the first position
    {
        t->next=first;
        first=t;
    }
    else{
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}
int main()
{   
    struct Node *temp;
    int A[]={3,5,7,10,15,34,56,78};
    create(A,8);
    //display(first);
    //RDisplay(first);
    //printf("Length is %d", Rcount(first));
    //cout<<"Sum is "<<Rsum(first);
    //cout<<Rmax(first);
    // temp=RSearch(first,25);
    // if(temp)
    //  cout<<"Key is found"<<temp->data;
    // else
    //   cout<<"Key is not found"<<endl;
    // return 0;
    insert(first,0,10);
    display(first);
    return 0;
}
