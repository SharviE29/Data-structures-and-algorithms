/*
Implementing queues using 2 stacks
*/

#include<iostream>
#include<stack>
using namespace std;
class Queue
{
    private:
    stack <int> s1;
    stack <int> s2;
    public:
    Queue(){};
    ~Queue(){};
    void enqueue(int x);
    int dequeue();
};
void Queue::enqueue(int x)
{
    s1.push(x);
}
int Queue::dequeue()
{
    int x=-1;
    if(s2.empty())
    {
        if(s1.empty())
        {
            cout<<"EMPTY !!"<<endl;
            return x;
        }
        else
        {
            while(s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
    x=s2.top();
    s2.pop();
    return x;
}
int main()
{
    Queue q;
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.dequeue();
    return 0;
}
//no display function is added