#include<iostream>
using namespace std;
class Node
{
    public:
    Node *lchild;
    int data;
    Node *rchild;
};
class Bst
{
 private:
 Node *root;

 public:
 Bst()
 {
    root=nullptr;
 }
 Node *getRoot()
 {
    return root;
 }
 void insert(int key);
 void inorder(Node *p);
 Node *search(int key);
 Node *RecursiveInsert(Node *p,int key);
};
Node *Bst::search(int key)
{
    Node *p=root;
    while(p!=nullptr)
    {
        if(p->data==key)
        {
            return p;
        }
        else if (p->data<key)
        {
            p=p->rchild;
        }
        else if(p->data>key)
        {
            p=p->lchild;
        }   
    }
    return nullptr;
}
void Bst::insert(int key)//create a tail pointer
{
  Node *t=root;
  Node *p,*r;
  //if the root is empty
  if(root==nullptr)
  {
      p=new Node;
      p->data=key;
      p->lchild=p->rchild=nullptr;
      root=p;
      return ;
  }
  while(t!=nullptr)
  {
      r=t;
      if(t->data==key)
      {
        return ;
      }
      else if(t->data>key)
      {
        t=t->lchild;
      }
      else if(t->data<key)
      {
        t=t->rchild;
      }    
  }
  p=new Node;
  p->data=key;
  p->lchild=p->rchild=nullptr;
  if(key>r->data){
    r->rchild=p;
  }
  else {
    r->lchild=p;
  }   
}
void Bst::inorder(Node *p)
{
    if(p)
    {
      inorder(p->lchild);
      cout<<p->data<<" ";
      inorder(p->rchild);        
    }
}
Node *Bst::RecursiveInsert(Node *p,int key)
{ 

  Node *t=nullptr;

  if(p==nullptr)
  {
    Node *t=new Node();
    t->data=key;
    t->lchild=t->rchild=nullptr;
    return t;
  }
  if(key<p->data)
  {
    p->lchild=RecursiveInsert(p->lchild,key);
  }
  else if(key>p->data)
  {
    p->rchild=RecursiveInsert(p->rchild,key);
  }
  else
    return p;
}
int main()
{
    Bst t1;
    t1.insert(10);
    t1.insert(20);
    t1.insert(40);
    t1.inorder(t1.getRoot());
    t1.search(20);
    return 0;
}