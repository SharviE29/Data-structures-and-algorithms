#include<stdio.h>
#include<stdlib.h>
using namespace std;
/*
Stacks using arrays
There are three requirements for creating any stack using an array.
1. Size of the stack
2. The top pointer
3. The array in which the elements will be stored
*/
struct Stack
{
    int size;
    int top;
    int *S;
    //here the array will be created dynamically and size of the array will be taked from the user
};
//using call by reference
void create(struct Stack *st)
{
    printf("Enter the size of the stack :");
    scanf("%d", &st->size);
    st->top=-1;//initialising top to -1.
    //creating an array dynamically for storing the elements
    st->S=(int *)malloc(st->size*sizeof(int));
}
//using call by value as the original stack wont be modified
void display(struct Stack st)
{
    int i;
    for(i=st.top;i>=0;i--)
    {
       printf("%d",st.S[i]);
    }
    printf("\n");
}
//here , calling by address
//to add an element to the stack
void push(struct Stack *st,int x)
{
    //checking condition for stack overflow
    if(st->top==st->size-1)
    {
        printf("Stack Overflow !!! \n");
    }
    else
    {    
        //increment the top index
        st->top++;
         // store the value at that index
        st->S[st->top]=x;
    }
}
//return type is int for returning the value deleted
//to remove/delete an element to the stack
int pop(struct Stack *st)
{ 
    int x=-1;
    if(st->top==-1)
    {
        printf("Stack underflow !!! \n");
    }
    else
    {
       x=st->S[st->top];
       st->top--;
    }
    return x;
}
//to return the value at the index from the top of the stack
int peek(struct Stack st,int index)
{
    int x=-1;
    if(st.top-index+1<0)
    {
        printf("Invalid index !!!");
    }
    x=st.S[st.top-index+1];
    return x;
}
//to check if the stack is empty
int isEmpty(struct Stack st)
{
    if(st.top==-1)
    {
        return 1;
    }
    else
    {
        return 0;   
    } 
}
//to check if the stack is full
int isFull(struct Stack st)
{
    if(st.top==st.size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//to return the topmost element in the stack
int stackTop(struct Stack st)
{
    /*
    if(!isEmpty(st))
    {
        return st.S[st.top];
    }
    else
    {
        return -1;
    }
    */
    if(st.top==-1)
    {
        return -1;
    }
    else
    {
       return st.S[st.Top];
    }
}
int main()
{
    struct Stack st;//creating an object
    create(&st);
    push(&st,10);
    push(&st,40);
    push(&st,20);
    push(&st,60);
    printf("%d \n",peek(st,2));
    //printf("%d \n",pop(&st));
    display(st);
    return 0;
}