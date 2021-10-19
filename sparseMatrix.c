#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct Element
{
    int i;
    int j;
    int x;
};
struct Sparse(struct Sparse *s)
{
    int m;//stores number of rows
    int n;//stores number of columns
    int num;//stores the number of elements
    struct Element *ele;//creating a dynamic array that will store the array of elements
};
void Create(struct Sparse *s)
{
    cout<<"Enter the dimensions: "<<endl;
    scanf("%d,%d",&s->m,&s->n);
    cout<<"Number of non zero elements:"<<endl;
    scanf("%d",&s->num);
    s->ele=(struct Element *)malloc(s->num*sizeof(struct Element));
    cout<<"Enter all non zero elements:"<<endl;
    for(int i=0;i<s->num;i++)
    {
        scanf("%d,%d,%d",&s->ele[i].i,&s->ele[i].j,&s->ele[i].x);// takes all non zero elements
    }
}
void Display(struct Sparse s)//displaying the actual sparse matrix
{
    int i,j,k=0;
    for(int i=0;i<s.m;i++)
    {
        for(j=0;j<s.n;j++)
        {
            if(i==s.ele[k].i && j==s.ele[k].j)
            {
                cout<<s.ele[k++].x;
            }
            else cout<<"0"<<endl;
        }
        cout<<endl;
    }
}
int main()
{
    struct Sparse s;
    Create(&s);
    Display(s);
    return 0;
}
