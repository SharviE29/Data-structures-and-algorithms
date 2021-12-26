/****************
 
Stacks using classes instead of structures

****************/

#include<iostream>
using namespace std;
class Node
{
  public://making them public so that the class Stack can access them
  int data;
  Node *next;
};

class Stack
{
  private:
  Node *top;//self-referencing
  public:
  Stack()
  {
      top=NULL;
  }
  void Push(int x);
  int Pop();
  void Display();
};

void Stack::Push(int x)
{
   Node *t=new Node();
   if(t==NULL)
   {
       cout<<"Stack is full!!! Stack overflow"<<endl;
   }
   else
   {
      t->data=x;
      t->next=top;
      top=t;
   }
}

int Stack::Pop()
{   
    int x=-1;
    Node *t=new Node();
    if(top==NULL)
    {
        cout<<"Stack is empty !!! Stack underflow !!!"<<endl;
    }
    else
    {
        x=top->data;
        Node *t=top;
        top=top->next;
        delete t;
    }
    return x;
}

void Stack::Display()
{
   Node *p=top;
   while(p)
   {
       cout<<p->data<<" ";
       p=p->next;
   }
   cout<<endl;
}
int main()
{
    Stack stack1;
    stack1.Push(10);
    stack1.Push(20);
    stack1.Push(30);
    stack1.Push(40);
    stack1.Push(50);
    stack1.Display();
    cout<<stack1.Pop();
    return 0;
}