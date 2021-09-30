#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define EMPTY -1;

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int size(Node *head);
bool isEmpty(Node *head);
void initEmptyList(Node *head);
int valueAtIndex(Node *head, int index);
int addToFront(Node **head, int data);
void printList(Node *head);
int popFront(Node **head);
int pushBack(Node **head, int data);
int popBack(Node **head);
int getFirstItemValue(Node **head);
int insertAtIndex(Node **head, int index, int value);
int deleteAtIndex(Node **head, int index);
int reverseList(Node **head);
int removeFirstValueSeen(Node **head, int value);
