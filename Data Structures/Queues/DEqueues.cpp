/*
Double ended queues
Both insertion and deletion is done by front and rear pointers
FIFO isn't followed
*/

#include<iostream>
using namespace std;
class dequeue
{
    private:
    int front;
    int rear;
    int size;
    int *Q;

    public:
    dequeue(int size);
    ~dequeue();
    void display();
    void enqueuefront(int x);
    void enqueuerear(int x);
    int dequeFront();
    int dequeRear();
    bool isEmpty();
    bool isFull();
};

dequeue::dequeue(int size)
{
    this->size=size;
    front=-1;
    rear=-1;
    Q=new int[size];
}
dequeue::~dequeue()
{
    delete [] Q;
}
bool dequeue::isEmpty()
{
    if(front==rear)
    {
        return true;
    }
    return false;
}
bool dequeue::isFull()
{
    if(rear==size-1)
    {
        return true;
    }
    return false;
}
void dequeue::enqueuefront(int x)
{
    if(front==-1)
    {
        cout<<"FULL"<<endl;
    }
    else
    {
        Q[front]=x;
        front--;
    }
}
void dequeue::enqueuerear(int x)
{
    if(isFull())
    {
        cout<<"FULL"<<endl;
    }
    else
    {
        rear++;
        Q[rear]=x;
    }
}
int dequeue::dequeFront()
{
    int x=-1;
    if(isEmpty())
    {
        cout<<"EMPTY"<<endl;
    }
    else
    {
        x=Q[front];
        front++;
    }
    return x;
}
int dequeue::dequeRear()
{
    int x=-1;
    if(rear==-1)
    {
        cout<<"EMPTY"<<endl;
    }
    else
    {
        x=Q[rear];
        rear--;
    }
    return x;
}
void dequeue::display()
{
    for (int i=front+1; i<=rear; i++) {
        cout << Q[i] << " ";
    }
    cout << endl;
}
int main()
{
    dequeue de(4);
    de.enqueuerear(3);
    de.enqueuefront(4);
    de.dequeFront();
    de.dequeRear();
    de.display();    
}