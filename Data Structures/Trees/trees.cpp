#include<iostream>
#include "queues.h"
using namespace std;
class Tree
{  
private:
   Node *root;
public:
   Tree()
   {
       root=nullptr;
   }
   void createTree();
   void preOrder(Node *p);
   void postOrder(Node *p);
   void inOrder(Node *p);
   void levelOrder(Node *p);
   int height(Node *p);
   //if root is to be made private
   void preOrder()
   {
     preOrder(root);
   }
   void postOrder()
   {
     postOrder(root);
   }
   void inOrder()
   {
     inOrder(root);
   }
   void levelOrder()
   {
     levelOrder(root);
   }
   void preorderIter(Node *p);
   void inorderIter(Node *p);
   void postorderIter(Node *p);
   int count(Node *p);
   int sum(Node *p);
   int nodewithLandRchild(Node *p);
   int countLeafnodes(Node *p);
   int nodewithLorandRchild(Node *p);
   int nodewithLorRchild(Node *p);
};
void Tree::createTree()
{
    Node *p,*t;
    int x;
    Queue q(100);
    cout<<"Enter the value of the root node:";
    cin>>x;
    root=new Node;
    root->data=x;
    root->lchild=root->rchild=nullptr;
    q.enqueue(root);

    while(!q.isEmpty())
    {
        p=q.dequeue();
        cout<<"Enter the left child of "<<p->data<<":";
        cin>>x;
        if(x!=-1)
        {
            t=new Node();
            t->data=x;
            t->lchild=t->rchild=nullptr;
            p->lchild=t;
            q.enqueue(t);
        }
        cout<<"Enter the right child of "<<p->data<<":";
        cin>>x;
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=nullptr;
            p->rchild=t;
            q.enqueue(t);
        }
    }
}
void Tree::preOrder(Node *p)
{
  if(p)
  {
      cout<<p->data<<" ";
      preOrder(p->lchild);
      preOrder(p->rchild);
  }
  //cout<<endl;
}
void Tree::inOrder(Node *p)
{
  if(p)
  {
      inOrder(p->lchild);
      cout<<p->data<<" ";
      inOrder(p->rchild);
  }
  //cout<<endl;
}
void Tree::postOrder(Node *p)
{
  if(p)
  {
      postOrder(p->lchild);
      postOrder(p->rchild);
      cout<<p->data<<" ";
  }
  //cout<<endl;
}
void Tree::levelOrder(Node *root)
{
  Queue q(100);
  cout<<root->data<<" ";
  q.enqueue(root);
  while(!q.isEmpty())
  {
    root=q.dequeue();
    if(root->lchild)
    {
      cout<<root->lchild->data<<" ";
      q.enqueue(root->lchild);
    } 
    if(root->rchild)
    {
      cout<<root->rchild->data<<" ";
      q.enqueue(root->rchild);
    } 
  }
  //cout<<endl;
}
int Tree::height(Node *root)
{
  int x=0,y=0;
  if(root==0)
       return 0;
  x=height(root->lchild);
  y=height(root->rchild);
  if(x>y)
     return x+1;
  else
     return y+1;   
}
int Tree::count(Node *p)
{
  int x,y;
  if(p!=nullptr)
    x=count(p->lchild);
    y=count(p->rchild);
    return x+y+1;
  return 0;
  //instead of assigning the values to x and y
  //return count(p->lchild)+count(p->rchild)+1
}
int Tree::sum(Node *p)
{
  int x,y;
  if(p!=nullptr)
    x=count(p->lchild);
    y=count(p->rchild);
    return x+y+p->data;
  return 0;
}
int Tree::nodewithLandRchild(Node *p)//counting nodes with degree 2
{
  int x,y;
  if(p!=nullptr)
    x=count(p->lchild);
    y=count(p->rchild);
    if(p->lchild!=nullptr && p->rchild!=nullptr)
      return x+y+1;
    else
      return x+y;  
  return 0;
}
int Tree::countLeafnodes(Node *p)//counting nodes with degree 0
{
  int x,y;
  if(p!=nullptr)
    x=count(p->lchild);
    y=count(p->rchild);
    if(p->lchild==nullptr && p->rchild==nullptr)
      return x+y+1;
    else
      return x+y;  
  return 0;
}
int Tree::nodewithLorandRchild(Node *p)//counting nodes with degree 1 or 2
{
  int x,y;
  if(p!=nullptr)
    x=count(p->lchild);
    y=count(p->rchild);
    if(p->lchild!=nullptr || p->rchild!=nullptr)
      return x+y+1;
    else
      return x+y;  
  return 0;
}
int Tree::nodewithLorRchild(Node *p)//only degree 1
{
  int x,y;
  if(p!=nullptr)
    x=count(p->lchild);
    y=count(p->rchild);
    //if(p->lchild!=nullptr ^ p->rchild!=nullptr) //another way of writing the same
    if((p->lchild!=nullptr && p->rchild==nullptr)||(p->lchild==nullptr && p->rchild))//xor operation
      return x+y+1;
    else
      return x+y;  
  return 0;
}
void Tree::preorderIter(Node *p)
{
  Stack s(100);
  while(p!=nullptr || !s.isEmpty())
  {
    if(p!=nullptr)
    {
      cout<<p->data<<" ";
      s.push(p);
      p=p->lchild;
    }
    else
    {
      p=s.stackTop();
      s.pop();
      p=p->rchild;
    }
  }
  cout<<endl;
}
void Tree::inorderIter(Node *p)
{
  Stack s(100);
  while(p!=nullptr || !s.isEmpty())
  { 
    if(p!=nullptr)
    {
      s.push(p);
      p=p->lchild;
    }
    else
    {
      p=s.pop();
      cout<<p->data<<" ";
      p=p->rchild;
    } 
  }
}
//This is tricky
void Tree::postorderIter(Node *p)
{
   Stack s(100);
   long int temp;
   while(p!=nullptr || !s.isEmpty())
   {
     if(p!=nullptr)
     {
       s.push(p);
       p=p->lchild;
     }
     else
     { 
       temp=(int)s.stackTop();
       p=s.stackTop();
       s.pop();
       if(temp>0)
       {
         s.push((Node*)-temp);
         p=((Node*)temp)->rchild;
       }
       else
       {
         cout<<((Node*)(-temp))->data<<" ";
         p=nullptr;
       }
     }
   }
  cout<<endl;
}
int main()
{ 
  Tree t;
  t.createTree();
  cout<<"Preorder traversal: ";
  t.preOrder();
  cout<<"Inorder traversal: ";
  t.inOrder();
  cout<<"Postorder traversal: ";
  t.postOrder();
  cout<<"Levelorder traversal: ";
  t.levelOrder();
  return 0;
}
