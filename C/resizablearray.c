#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define EMPTY -1

int size = 0;
size_t capacity = 4;

int sizeOfArray();
int capacityOfArray();
void initializeEmptyArray(int *arr);
void appendInTheEnd(int *arr, int value, int **array);
bool isEmpty(int *arr);
int FindItemInIndex(int *arr, int index);
void insertAtIndex(int *arr, int index, int value);
bool checkBoundaries(int index);
int pop(int *arr);
void deleteAtIndex(int *arr, int index);
int removeItemMaintainingIndex(int *arr, int value);
int findElementByValue(int *arr, int value);
void resizeArray(int **arr, size_t capacity);
void append(int *arr, int value);

int main(void)
{
    int *arr = malloc(capacity * sizeof(int));
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    size = 4;

    appendInTheEnd(arr, 5, &arr);
    for (int i = 0; i < capacity; i++)
    {
        printf("%d ", arr[i]);
    }
}

void appendInTheEnd(int *arr, int value, int **array)
{
    if (size == capacity)
    {
        resizeArray(array, capacity);
        capacity *= 2;
        append(arr, value);
    }
}

void append(int *arr, int value)
{
    arr[size] = value;
    size++;
}

void resizeArray(int **arr, size_t capacity)
{
    int *newArr = malloc(2 * capacity * sizeof(int));
    for (int i = capacity; i < 2 * capacity; i++)
    {
        newArr[i] = EMPTY;
    }
    memcpy(newArr, *arr, capacity * sizeof(int));
    memset(newArr + capacity, EMPTY, capacity);
    free(*arr);
    *arr = newArr;
}

int findElementByValue(int *arr, int value)
{
    for (int i = 0; i < capacity - 1; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
}

int removeItemMaintainingIndex(int *arr, int value)
{
    for (int i = 0; i < capacity - 1; i++)
    {
        if (arr[i] == value)
        {
            arr[i] = EMPTY;
            return arr[i];
        }
    }
}

void deleteAtIndex(int *arr, int index)
{
    if (checkBoundaries(index) == true)
    {
        for (int i = index; i < capacity - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[capacity - 1] = EMPTY;
    }
}

int pop(int *arr)
{
    for (int i = capacity - 1; i >= 0; i--)
    {
        if (arr[i] != EMPTY)
        {
            int value = arr[i];
            arr[i] = EMPTY;
            return value;
        }
    }
}

void insertAtIndex(int *arr, int index, int value)
{
    if (checkBoundaries(index) == true && checkBoundaries(index + 1) == true)
    {
        for (int i = capacity - 1; i > index; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
    }
}

bool checkBoundaries(int index)
{
    if (index < 0 || index > capacity - 1)
    {
        printf("Index out of bounds");
        return false;
    }
    return true;
}

int FindItemInIndex(int *arr, int index)
{
    if (checkBoundaries(index) == true)
    {
        return arr[index];
    }
    return -1;
}

bool isEmpty(int *arr)
{
    if (size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void initializeEmptyArray(int *arr)
{
    for (int i = 0; i < capacity; i++)
    {
        arr[i] = EMPTY;
    }
}

int capacityOfArray()
{
    return capacity;
}

int sizeOfArray()
{
    return size;
}