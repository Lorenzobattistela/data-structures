#include "linkedlist.h";

int main(void)
{
    Node *head = malloc(sizeof(Node));
    initEmptyList(head);
    head->data = 1;
    printList(head);
}

int removeFirstValueSeen(Node **head, int value)
{
    Node *current = *head;
    while (current->next->data != value)
    {
        current = current->next;
    }
    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
}

int reverseList(Node **head)
{
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    return 0;
}

int deleteAtIndex(Node **head, int index)
{
    Node *current = *head;
    if (index < 0 || index >= size(*head))
    {
        printf("Index out of bounds\n");
        return -1;
    }

    if (index == 0)
    {
        Node *temp = current->next;
        free(current);
        *head = temp;
        return 0;
    }

    for (int i = 0; i < index - 1; i++)
    {
        current = current->next;
    }
    Node *toBeDeleted = current->next;
    current->next = toBeDeleted->next;
    int data = toBeDeleted->data;
    free(toBeDeleted);
}

int insertAtIndex(Node **head, int index, int value)
{
    Node *current = *head;
    Node *newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (index < 0 || index >= size(*head))
    {
        printf("Index out of bounds\n");
        return -1;
    }

    for (int i = 0; i < index - 1; i++)
    {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return 0;
}

int getLastValue(Node **head)
{
    Node *current = *head;
    while (current != NULL)
    {
        current = current->next;
    }
    return current->data;
}

int getFirstItemValue(Node **head)
{
    return (*head)->data;
}

int popBack(Node **head)
{
    Node *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    int deletedData = temp->next->data;
    temp->next = NULL;
    return deletedData;
}

int pushBack(Node **head, int data)
{
    Node *newNode = malloc(sizeof(Node));
    Node *current = *head;
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return -1;
    }
    newNode->data = data;
    newNode->next = NULL;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    return 0;
}

void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int popFront(Node **head)
{
    Node *temp = *head;
    *head = temp->next;
    return temp->data;
}

int addToFront(Node **head, int data)
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return -1;
    }
    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;
    return 0;
}

int valueAtIndex(Node *head, int index)
{
    if (index < 0 || index >= size(head))
    {
        printf("Index out of bounds\n");
        return -1;
    }
    Node *current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current->data;
}

void initEmptyList(Node *head)
{
    head->next = NULL;
    head->data = EMPTY;
}

bool isEmpty(Node *head)
{
    if (head->next == NULL)
    {
        return true;
    }
    return false;
}

int size(Node *head)
{
    int count = 0;
    Node *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
