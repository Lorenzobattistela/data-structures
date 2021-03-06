#include "resizable.h"
size_t capacity = 4;
int size = 0;
int main(void)
{
    int *arr = malloc(capacity * sizeof(int));
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    size = 4;

    if (sizeOfArray() != 4)
    {
        printf("Size does not match");
        return -1;
    }
    if (capacityOfArray() != 4)
    {
        printf("Capacity does not match");
        return -1;
    }
    if (isEmpty(arr) != false)
    {
        printf("Array is not empty");
        return -1;
    }
    if (FindItemInIndex(arr, 0) != 1)
    {
        printf("Item at index 0 is not being found correctly");
        return -1;
    }
    if (checkBoundaries(0) != true)
    {
        printf("Checking boundaries failed");
        return -1;
    }

    if (findElementByValue(arr, 1) != 0)
    {
        printf("Element find failed");
        return -1;
    }

    deleteAtIndex(arr, 0);
    for (int i = 0; i < capacity; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n%i", size);
}

void appendInTheEnd(int **arr, int value)
{
    if (size == capacity)
    {
        resizeArray(arr, capacity);
        capacity *= 2;
    }
    (*arr)[size++] = value;
}

void resizeArray(int **arr, size_t capacity)
{
    int *newArr = malloc(2 * capacity * sizeof(int));
    for (int i = capacity; i < 2 * capacity; i++)
    {
        newArr[i] = EMPTY;
    }
    memcpy(newArr, *arr, capacity * sizeof(int));
    memset(newArr + capacity, EMPTY, capacity * sizeof(int));
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
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            arr[i] = EMPTY;
            size--;
        }
    }
}

void deleteAtIndex(int *arr, int index)
{
    if (checkBoundaries(index) == true)
    {
        for (int i = index; i < capacity; i++)
        {
            if (i == index)
            {
                arr[i] = EMPTY;
                size--;
            }
        }
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