#include<stdio.h>
#define Max 5

typedef struct 
{
    int data[Max];
    int TOS;
}StackAsADT;

int IsFull(StackAsADT s)
{
    if (s.TOS == Max-1)
    {
        printf("Stack is full.\n");
        return 1;
    } 
    else
    {
        printf("Stack is not full.\n");
        return 0;
    } 
}
int IsEmpty(StackAsADT s)
{
    if (s.TOS == -1)
    {
        printf("Stack is empty.\n");
        return 1;
    } 
    else
    {
        printf("Stack is full.\n");
        return 0;
    } 
}
void Push(StackAsADT *s, int element)
{
    if(s->TOS == Max-1) printf("The stack is already full.\n");
    else 
    {
        s->TOS = s->TOS + 1;
        s->data[s->TOS] = element;
        printf("%d is pushed to the stack.\n",element);
    }
}
int Pop(StackAsADT *s)
{
    int element;
    if(s->TOS == -1) printf("The stack is already empty.\n");
    else
    {
        element = s->data[s->TOS];
        s->TOS = s->TOS - 1;
        printf("%d is popped from stack.\n",element);
    }
    return element;
}

int main()
{
    StackAsADT s;
    s.TOS = -1;

    IsEmpty(s);
    Push(&s, 10);
    Push(&s, 11);
    Push(&s, 12);
    Push(&s, 13);
    Push(&s, 14);
    IsFull(s);
    printf("%d\n",s.TOS);
    Pop(&s);


    return 0;
}
