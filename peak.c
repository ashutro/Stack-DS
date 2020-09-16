/*
    #Stack element position:
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
    st->top  = -1;
    st->S =(int *)malloc(size*sizeof(int));
}
void push(struct stack *st, int data)
{
    if(st->top == st->size-1)
    {
        printf("StackOverFlow");
        return;
    }
    else
    {
        st->S[++st->top] = data;
    }
}
void display(struct stack st)
{
    int i;
    for(i = st.top; i>=0;--i)
    {
        printf("%d  ",st.S[i]);
    }
}
int peek(struct stack st, int index)
{
    int x = -1;
    if(st.top-index+1 < 0)
        printf("Index Invalid\n");
    else
    {
        x = st.S[st.top - index+1];
        return x;
    }
    
    
        
}
int main()
{
    int i, data,index;
    struct stack st;
    printf("Enter the size of stack: ");
    scanf("%d",&st.size);
    createStack(&st,st.size);
    for(i = 1 ; i <= st.size; i++)
    {
        printf("Enter the data %d: ",i);
        scanf("%d",&data);
        push(&st,data);
    }
    display(st);
    printf("\n");
    printf("Enter the index: ");
    scanf("%d",&index);
    printf("Peak of Element: %d",peek(st,index));
    return 0;
}
