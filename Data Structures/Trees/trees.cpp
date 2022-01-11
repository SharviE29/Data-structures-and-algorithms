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
      preOrder(p->lchild);
      cout<<p->data<<" ";
      preOrder(p->rchild);
  }
  //cout<<endl;
}
void Tree::postOrder(Node *p)
{
  if(p)
  {
      preOrder(p->lchild);
      preOrder(p->rchild);
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
