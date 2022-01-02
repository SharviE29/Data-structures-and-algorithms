/*
Queues using linked lists
*/

#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
};

class Queue
{
  private:
  Node *front;
  Node *rear;

  public:
  Queue();
  ~Queue();
  void enqueue(int x);
  int dequeue();
  bool isEmpty();
  void display();
};

Queue::Queue()
{
    front=nullptr;
    rear=nullptr;
}
void Queue::enqueue(int x)
{
    Node *t=new Node;
    if(t==nullptr)
    {
        cout<<"Queue is full!!"<<endl;
    }
    else
    {
       t->data=x;
       t->next=nullptr;
       if(front==nullptr)//first node
       {
           front=t;
           rear=t;
       }
       else
       {
           rear->next=t;
           rear=t;
       }
    }
}
int Queue::dequeue()
{
    int x=-1;
    Node *p;
    if(isEmpty())
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
       p=front;
       front=front->next;
       x=p->data;
       delete p;
    }
    return x;
}
bool Queue::isEmpty()
{
    if(front==nullptr)
    {
        return true;
    }
    return false;
}
Queue::~Queue()
{
    Node *p=front;
    while(front)
    {
        front=front->next;
        delete p;
        p=front;
    }
}
void Queue::display()
{
    Node *p=front;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main()
{
    Queue q;
    q.enqueue(4);
    q.enqueue(9);
    q.enqueue(8);
    q.enqueue(3);
    q.display();
    cout<<q.dequeue();
    return 0;
}