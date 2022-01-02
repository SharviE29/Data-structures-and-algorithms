#include<iostream>
using namespace std;
class Queue
{
    private:
    int front;
    int rear;
    int size;
    int *Q;

    public:
    Queue()
    {
        front=rear=0;
        size=10;
        Q=new int[size];
    }
    Queue(int size)
    {
        front=rear=-1;
        this->size=size;
        Q=new int[this->size];
    }
    void enqueue(int x);
    int dequeue();
    void Display();
};
void Queue::enqueue(int x)
{
    if((rear+1)%size==front)
    {
        cout<<"Queue is full !!"<<endl;
    }
    else
    {
        rear=(rear+1)%size;
        Q[rear]=x;
    }
}
int Queue::dequeue()
{   
    int x=-1;
    if(front==rear)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        x=Q[front+1];
        front=(front+1)%size;
    }
    return x;
}
void Queue::Display()
{   
    int i=front+1;
    do
    {
        cout<<Q[i];
        i=(i+1)%size;
    } while (i!=(rear+1)%size);
    
    for(int i=front+1;i<=rear;i++)
    {
        cout<<Q[i]<<" ";
    }
    cout<<endl;
}
int main()
{  
   int size;
   int element;
   cout<<"Enter the size of the queue:"<<endl;
   cin>>size;
   Queue q(size);
   for(int i=0;i<size;i++)
   {   
       cout<<"Enter element at position "<<i<<":";
       cin>>element;
       q.enqueue(element);
   }
   q.Display();
   cout<<"Dequeue:"<<q.dequeue()<<endl;
   q.Display();
   return 0;
}