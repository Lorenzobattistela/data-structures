#include "queue.h"

#define LENGTH 6

int queue[6];

int main(void)
{
    create();
    enque(1);
    printQueue();
}

void create()
{
    for (int i = 0; i < LENGTH; i++)
    {
        queue[i] = 0;
    }
}

bool isEmpty()
{
    if (queue[LENGTH - 1] == 0)
    {
        printf("Queue is empty\n");
        return true;
    }
    return false;
}

void enque(int x)
{
    if (isEmpty() == true)
    {
        queue[LENGTH - 1] = x;
    }
    for (int i = LENGTH - 1; i >= 0; i--)
    {
        if (queue[0] != 0)
        {
            printf("Queue is full\n");
            break;
        }
        queue[i - 1] = queue[i];
    }
}

void printQueue()
{
    for (int i = 0; i < LENGTH; i++)
    {
        printf("%d ", queue[i]);
    }
}
