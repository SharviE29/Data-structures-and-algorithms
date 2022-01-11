#ifndef queues_h
#define queues_h
using namespace std;
class Node
{
    public:
    int data;
    Node *lchild;
    Node *rchild;
    //Node *next;
};
class Queue
{
  private:
  int front;
  int rear;
  int size;
  Node **Q;//queue should store the addresses of a tree.
  public:
  Queue();
  Queue(int x);
//   ~Queue();
  void enqueue(Node *x);
  Node *dequeue();
  bool isEmpty();
  void display();
};
Queue::Queue()
{
    front=rear=-1;
    size=10;
    Q=new Node *[size];
}
Queue::Queue(int size)
{
    front=rear=-1;
    this->size=size;
    Q=new Node *[this->size];
}
void Queue::enqueue(Node *x)
{
    // Node *t=new Node;
    // if(t==nullptr)
    // {
    //     cout<<"Queue is full!!"<<endl;
    // }
    // else
    // {
    //    t->data=x;
    //    t->next=nullptr;
    //    if(front==nullptr)//first node
    //    {
    //        front=t;
    //        rear=t;
    //    }
    //    else
    //    {
    //        rear->next=t;
    //        rear=t;
    //    }
    // }
    if(rear==size-1)
       cout<<"Queue is full"<<endl;
    else
    {
        rear++;
        Q[rear]=x;
    }
}
Node* Queue::dequeue()
{
    // Node* x=nullptr;
    // Node *p;
    // if(isEmpty())
    // {
    //     cout<<"Queue is empty"<<endl;
    // }
    // else
    // {
    //    p=front;
    //    front=front->next;
    //    x=p->data;
    //    delete p;
    // }
    // return x;
    Node *x=NULL;
    if(front==rear)
      cout<<"Queue is empty"<<endl;
    else
    {
        x=Q[front+1];
        front++;
    }
    return x;
}
bool Queue::isEmpty()
{
    if(front==rear)
    {
        return true;
    }
    return false;
}
// Queue::~Queue()
// {
//     Node *p=front;
//     while(front)
//     {
//         front=front->next;
//         delete p;
//         p=front;
//     }
// }
// void Queue::display()
// {
//     Node *p=front;
//     while(p)
//     {
//         cout<<p->data<<" ";
//         p=p->next;
//     }
//     cout<<endl;
// }
#endif