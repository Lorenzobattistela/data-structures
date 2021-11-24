#include <stdio.h>
#include <stdlib.h>
#define maxsize 5
void insert();
void delete ();
void display();
int front = -1, rear = -1;
int queue[maxsize];
void main()
{
    display();
    insert();
    insert();
    display();
    delete ();
    display();
}
void insert()
{
    int item;
    printf("\nEnter the element\n");
    scanf("\n%d", &item);
    if (rear == maxsize - 1)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = rear + 1;
    }
    queue[rear] = item;
    printf("\nValue inserted ");
}
void delete ()
{
    int item;
    if (front == -1 || front > rear)
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    else
    {
        item = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = front + 1;
        }
        printf("\nvalue deleted ");
    }
}

void display()
{
    int i;
    if (rear == -1)
    {
        printf("\nEmpty queue\n");
    }
    else
    {
        printf("\nprinting values .....\n");
        for (i = front; i <= rear; i++)
        {
            printf("\n%d\n", queue[i]);
        }
    }
}