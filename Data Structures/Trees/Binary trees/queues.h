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
class Stack
{
    private:
    int size;
    int top;
    Node **S;
    public:
    Stack();
    Stack(int size);
    void push(Node *x);
    Node *pop();
    bool isFull();
    bool isEmpty();
    Node *stackTop();
};
Stack::Stack()
{
    int size=50;
    top=-1;
    S=new Node *[size];
}
Stack::Stack(int size)
{
    this->size=size;
    top=-1;
    S=new Node *[size];
}
void Stack::push(Node *x)
{
    if(isFull())
    {
        cout<<"Stack overflow";
    }
    else
    {
        top++;
        S[top]=x;
    }
}
Node *Stack::pop()
{
    Node *x=nullptr;
    if(isEmpty())
    {
        cout<<"Stack underflow";
    }
    else
    {
        x=S[top];
        top--;
    }
    return x;
}
bool Stack::isFull()
{
    if(top==size-1)
       return true;
    return false;   
}
bool Stack::isEmpty()
{
    if(top==-1)
       return true;
    return false;   
}
Node *Stack::stackTop()
{
    if(isEmpty())
       return nullptr;
    else
       return S[top];   
}
#endif