#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int tos = -1;

struct SLL
{
    int data;
    struct SLL *next;
};
struct SLL *top = NULL;

void push(int element)
{
    struct SLL *NewNode;
    NewNode = (struct SLL*)malloc(sizeof(struct SLL));
    NewNode->next = NULL;
    NewNode->data = element;
    if(top == NULL)// List is Empty
    {
        top = NewNode;
        tos = tos + 1;
    }
    else
    {
        NewNode->next = top;
        top = NewNode;
        tos = tos + 1;
    }
    printf("%d WAS PUSHED INTO STACK\n",top->data);
}
void pop()
{
    struct SLL *temp;
    if(top == NULL)
        printf("EMPTY STACK!\n");
    else if(top->next == NULL)
    {
        temp = top;
        printf("%d IS GOING TO BE POPPED\n",temp->data);
        top = NULL;
        free(temp);
        tos = tos - 1;
    }
    else
    {
        temp = top;
        top = top->next;
        printf("%d IS GOING TO BE POPPED\n",temp->data);
        free(temp);
        tos = tos - 1;
    }
}
void IsFull()
{
    if ( tos == MAX - 1) printf("STACK IS FULL!\n");
    else printf("NOT FULL!\n");
}
void IsEmpty()
{
    if ( tos == -1) printf("STACK IS EMPTY!\n");
    else printf("NOT EMPTY!\n");
}

int main()
{
    IsEmpty();
    push(10);
    push(11);
    push(12);
    push(14);
    push(13);
    IsFull();
    pop();


    return 0;
}
