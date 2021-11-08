//////////////////////////////////////////////////////////////////////////////////////
/// INCLUDES

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
////////////////////////////////////////////////////////////////////////////////
// DATA STRUCTURES
/**
 * Defining the structure of the node which contains 'data' (type : integer),
 * two pointers 'next' and 'pre' (type : struct node).
 */

struct node
{
    int data;
    struct node *next;
    struct node *pre;
} * head, *tail, *tmp;

////////////////////////////////////////////////////////////////////////////////
// FORWARD DECLARATIONS

bool isEmpty();
void create();
int deque();
int peek();
int size();
void printQueue();
void insert(int queue[], int max, int front, int rear, int item)
