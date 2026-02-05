#include <stdio.h>
#include <stdlib.h>

struct SLL
{
    int data;
    struct SLL *next;
};
struct SLL *first, *last = NULL;

void insertAtBeg(int element)
{
    struct SLL *NewNode;
    NewNode = (struct SLL*)malloc(sizeof(struct SLL));
    NewNode->next = NULL;
    NewNode->data = element;
    if(first == NULL)// List is Empty
        first = last = NewNode;
    else
    {
        NewNode->next = first;
        first = NewNode;
    }
    printf("%d WAS INSERTED AT THE BEGINNING\n",first->data);
}
void insertAtEnd(int element)
{
    struct SLL *NewNode;
    NewNode = (struct SLL*)malloc(sizeof(struct SLL));
    NewNode->next = NULL;
    NewNode->data = element;
    if(first == NULL)// List is Empty
        first = last = NewNode;
    else
    {
        last->next = NewNode;
        last = NewNode;
    }
    printf("%d WAS INSERTED AT THE END\n",last->data);
}
void insertAtPoint(int element,int pos)
{
    int i;
    struct SLL *NewNode,*temp;
    NewNode = malloc(sizeof(struct SLL));
    NewNode->data = element;
    NewNode->next = NULL;
    if(first==NULL)
        printf("List is empty.\n");
    else{
        temp = first;
        for(i=1;i<pos-1;i++){
            temp = temp->next;
        }
        NewNode->next = temp->next;
        temp->next = NewNode;
        printf("%d was inserted in %d position.\n",NewNode->data,pos);
    }

}
void deletionFromBeg()
{
    struct SLL *temp;
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
        printf("%d IS GOING TO BE DELETED\n",temp->data);
        free(temp);
    }
}
void deletionFromEnd()
{
    struct SLL *temp;
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
        while(temp->next != last)
        {
            temp = temp->next;
        }
        last = temp;
        temp = temp->next;
        printf("%d IS GOING TO BE DELETED\n",temp->data);
        free(temp);
        last->next = NULL;
    }
}
void display()
{
    struct SLL *temp;
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
void deletionFromPosition(int pos)
{
    struct SLL *temp, *tempp;
    int i;
    if(first == NULL || pos<=0)
        printf("INVALID DELETION!\n");
    else if(first->next ==  NULL || pos == 1)
    {
        deletionFromBeg();
    }
    else
    {
        temp = first;
        for(i=1;i<pos-1;i++)
            temp = temp->next;
        if(temp->next == last)
            deletionFromEnd();
        else
        {
            tempp = temp->next;
            temp->next = tempp->next;
            printf("%d IS GOING TO BE DELETED\n",tempp->data);
            free(tempp);
        }
    }

}
void search(int key)
{
    struct SLL *temp;
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
    insertAtBeg(100);
    insertAtBeg(200);
    insertAtEnd(300);
    insertAtEnd(400);
    insertAtBeg(500);
    display();
    insertAtPoint(600,3);
    insertAtPoint(700,4);
    display();
    deletionFromBeg();
    display();
    deletionFromEnd();
    display();
    deletionFromPosition(4);
    display();
    search(300);
    display();
    
    return 0;
}