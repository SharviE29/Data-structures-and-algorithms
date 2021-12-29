/*
 * job_queue.cpp
 *
 *  Created on: 28 Dec 2021
 *      Author: Sharvi
 */
#include<iostream>
#include<string>
#define MAX 30
using namespace std;
class Queue
{
private:
	int front;
	int rear;
	int size;
	string *Q;
public:
	Queue()//default Constructor
	{
		front=rear=-1;
		size=10;
		Q=new string[size];
	}
	Queue(int size)
	{
		front=rear=-1;
		this->size=size;
		Q=new string[this->size];
	}
	void enqueue(string x);
	string dequeue();
	void display();
	int isFull();
	int isEmpty();
};
void Queue::enqueue(string x)
{
	if(rear==size-1)
	{
		cout<<"Queue is full!!!"<<endl;
	}
	else
	{
		rear++;
		Q[rear]=x;
	}
}
string Queue::dequeue()
{
    string x="#";
	if(front==rear)
	{
		cout<<"Queue is empty !!"<<endl;
	}
	else
	{
		x=Q[front+1];
		front++;
	}
	return x;
}
void Queue::display()
{
	for(int i=front+1;i<=rear;i++)
	{
		cout<<Q[i]<<" ";
	}
	cout<<endl;
}
int Queue::isFull()
{
	if(rear==size-1)
		return 1;
	else
		return 0;
}
int Queue::isEmpty()
{
	if(rear==front)
		return 1;
	else
		return 0;
}
int main()
{
	int size;
	cout<<"Enter the size of the queue: "<<endl;
	cin>>size;
	Queue q(size);
	int ch;
	string x;
	do
	{
		cout<<"\n1.insert job\n2.delete job\n3.display\n4.Exit\nEnter your choice :";
		cin>>ch;
		switch(ch)
		{
		case 1:
			if(!q.isFull())
			{
				cout<<"Enter job name: ";
				cin>>x;
				q.enqueue(x);
			}
			else
			{
				cout<<"Queue overflow!!";
			}
			break;
		case 2:
			if(!q.isEmpty())
			{
				cout<<"Deleted job is: "<<q.dequeue()<<endl;
			}
			else
			{
				cout<<"Queue underflow!"<<endl;
			}
			cout<<"Remaining jobs:"<<endl;
			q.display();
			break;
		case 3:
			if(!q.isEmpty())
			{
				cout<<"Queue contains: "<<endl;
				q.display();
			}
			else
			{
				cout<<"Queue is empty!!"<<endl;
			}
			break;
		case 4:
			cout<<"Exit"<<endl;
			break;
		}
	}
	while(ch!=4);
	return 0;
}

