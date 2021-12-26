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
       return st.S[st.top];
    }
}
int main()
{
    struct Stack st;//creating an object
    int choice={0};
    while(choice!=-1)
    {
        printf("**********MENU*********** \n");
        printf("1.Create a stack \n");
        printf("2.Pushing an element \n");
        printf("3.Deleting an element \n");
        printf("4.To check the peek value\n");
        printf("5.To check if the stack is empty\n");
        printf("6.To check if the stack is empty \n");
        printf("7.To return the value at the top of the stack \n");
        printf("8. To display the stack \n");
        printf("-1. Exit \n");
        printf("Enter your choice : \n");
        scanf("%d", choice);
        switch(choice)
        {
            case 1:
            {
                create(&st);
                break;
            }
            case 2:
            {  
               int element;
               printf("Enter an element to push \n");
               scanf("%d",element);
               push(&st,element);
               break;
            }
            case 3:
            {
                pop(&st);
                break;
            }
            case 4:
            {   
                int index;
                printf("Check the peek value at index : ");
                scanf("%d",index);
                peek(st,index);
                break;
            }
            case 5:
            {
                isEmpty(st);
                break;
            }
            case 6:
            {
                isFull(st);
                break;
            }
            case 7:
            {
                stackTop(st);
                break;
            }
            case 8:
            {
                display(st);
                break;
            }
            case -1:
            {
                choice=-1;
                break;
            }
        }
        
        
    }
    // create(&st);
    // push(&st,10);
    // push(&st,40);
    // push(&st,20);
    // push(&st,60);
    // printf("%d \n",peek(st,2));
    // //printf("%d \n",pop(&st));
    // display(st);
    return 0;
}