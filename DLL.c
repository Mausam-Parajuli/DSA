#include<stdio.h>
#include<stdlib.h>

struct DLL
{
    int data;
    struct DLL *prev;
    struct DLL *next;
};
struct DLL *first, *last = NULL;

void insertAtBeginning(int element)
{
    struct DLL *NewNode;
    NewNode = (struct DLL*)malloc(sizeof(struct DLL));
    NewNode->data = element;
    NewNode->prev = NULL;
    NewNode->prev = NULL;
    if(first == NULL)
        first = last = NewNode;
    else
    {
        first->prev = NewNode;
        NewNode->next = first;
        first = NewNode;
    }
    printf("%d WAS INSERTED AT THE BEGINNING\n",first->data);
}

void insertAtEnd(int element)
{
    struct DLL *NewNode;
    NewNode = (struct DLL*)malloc(sizeof(struct DLL));
    NewNode->data = element;
    NewNode->prev = NULL;
    NewNode->prev = NULL;
    if(first == NULL)
        first = last = NewNode;
    else
    {
        last->next = NewNode;
        NewNode->prev = last;
        last = NewNode;
        NewNode->next = NULL;
    }
    printf("%d WAS INSERTED AT THE END\n",last->data);
}

void insertAtPosition(int element, int pos)
{
    int i;
    struct DLL *NewNode, *temp, *tempp;
    NewNode = (struct DLL*)malloc(sizeof(struct DLL));
    NewNode->data = element;
    NewNode->prev = NULL;
    NewNode->next = NULL;
    if(first == NULL)
        printf("List is Empty\n");
    else
    {
        temp = first;
        for(i=1; i<pos-1; i++)
            temp = temp->next;
        tempp = temp->next;
        NewNode->next = tempp;
        NewNode->prev = temp;
        tempp->prev = NewNode;
        temp->next = NewNode;
    }
    printf("%d was inserted in %d position.\n",NewNode->data,pos);
}

void deleteFromBegining()
{
    struct DLL *temp;
    if(first == NULL)
        printf("EMPTY LIST!\n");
    else if(first->next == NULL)
    {
        temp = first;
        printf("%d IS GOING TO BE DELETED\n",temp->data);
        first = last = NULL;
        free(temp);
    }
    else
    {
        temp = first;
        first = first->next;
        first->prev = NULL;
        printf("%d IS GOING TO BE DELETED\n",temp->data);
        free(temp);
    }
}

void deleteFromEnd()
{
    struct DLL *temp;
    if(first == NULL)
        printf("EMPTY LIST!\n");
    else if(first->next == NULL)
    {
        temp = first;
        printf("%d IS GOING TO BE DELETED\n",temp->data);
        first = last = NULL;
        free(temp);
    }
    else
    {
        temp = last;
        printf("%d IS GOING TO BE DELETED\n",temp->data);
        last = last->prev;
        last->next = NULL;
        free(temp);
    }
}

void deleteFromPosition(int pos)
{
    struct DLL *temp, *tempp;
    int i;
    if(first == NULL || pos<=0)
        printf("INVALID DELETION!\n");
    else if(first->next ==  NULL || pos == 1)
    {
        deleteFromBegining();
    }
    else
    {
        temp = first;
        for(i=1;i<pos-1;i++)
            temp = temp->next;
        if(temp->next == last)
            deleteFromEnd();
        else
        {
            tempp = temp->next;
            tempp->prev = temp;
            temp->next = tempp->next;
            printf("%d IS GOING TO BE DELETED\n",tempp->data);
            free(tempp);
        }
    }
}

void display()
{
    struct DLL *temp;
    if(first == NULL)
        printf("EMPTY LIST!\n");
    else
    {
        temp = first;
        while(temp != NULL)
        {
            printf("%d -> ",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void search(int key)
{
    struct DLL *temp;
    int flag = 0,i=1;
    if(first == NULL)
        printf("EMPTY LIST!\n");
    else
    {
        temp = first;
        while(temp != NULL)
        {
            if(temp->data == key)
            {
                printf("Element %d Found in position %d\n",key,i);
                flag = 1;
            }
            temp = temp->next;
            i++;
        }
        if(flag == 0)
            printf("SEARCH UNSUCCESSFUL!\n");
    }
}

int main()
{
    insertAtBeginning(100);
    insertAtBeginning(200);
    insertAtEnd(300);
    insertAtEnd(400);
    insertAtBeginning(500);
    display();
    insertAtPosition(600,3);
    insertAtPosition(700,4);
    display();
    deleteFromBegining();
    display();
    deleteFromEnd();
    display();
    deleteFromPosition(4);
    display();
    search(200);
    display();

    return 0;
}