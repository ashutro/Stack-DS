/*
    #Stack is Full:
*/
#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    int *S;
};
void createStack(struct stack *st, int size)
{
    //Creating stack in heap memory by using the malloc funtion:
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}
void push(struct stack *st, int data) // here we take 'st' as "Call by reference" :
{   
    //checking the condition for stack overflow: by comparing the top isEqual to the stackSize -1:
    if(st->top == st->size-1)
    {
        printf("stack OverFlow:");
        return;
    }
    else
    {   // with (++ prifix ) first we increse the top then we take the data in the stack:
        st->S[++st->top] = data;
    }
}
// iterative display funtion:
void display(struct stack st) // here we take 'st' as "Call by value" :
{
    int i;
    for(i = st.top; i >= 0; --i)
    {
        printf("%d ",st.S[i]);
    }
}
int isFull(struct stack st)
{
    return st.top == st.size-1;
}
int main()
{
    int i, data;
    struct stack st;
    printf("Enter the size of stack: ");
    scanf("%d",&st.size);
    createStack(&st,st.size);
        push(&st,10);
        push(&st,20);
    display(st);
    printf("\n");
    printf("Is Full: %d",isFull(st));
    return 0;
}
