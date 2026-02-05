#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct Queue
{
    int front;
    int rear;
    int data[MAX];
};

struct Queue queue = {0, -1};

int isFull()
{
    if (queue.rear == MAX - 1)
    {
        return printf("Queue is Full!\n");
    }
    else
    {
        return printf("Queue is Not Full!\n");
    }
}

int isEmpty()
{
    if (queue.front > queue.rear)
    {
        return printf("Queue is Empty!\n");
    }
    else
    {
        return printf("Queue is Not Empty!\n");
    }
}

void Enqueue(struct Queue *queue, int value)
{
    if (queue->rear == MAX - 1)
    {
        printf("Queue is full !\n");
    }
    else
    {
        queue->rear++;
        queue->data[queue->rear] = value;
        printf("%d is is enqueued\n", value);
    }
}

void Dequeue(struct Queue *queue)
{
    int element;
    if (queue->front > queue->rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        element = queue->data[queue->front];
        queue->front++;
        printf("%d is dequeued\n", element);
    }
}
int main()
{
    Enqueue(&queue, 10);
    Enqueue(&queue, 20);
    Enqueue(&queue, 20);
    Enqueue(&queue, 30);
    Enqueue(&queue, 40);
    isFull();
    Dequeue(&queue);
    Dequeue(&queue);
    Enqueue(&queue, 30);
    Enqueue(&queue, 30);
    Enqueue(&queue, 30);
    return 0;
}