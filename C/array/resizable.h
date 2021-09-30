#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define EMPTY -1

int sizeOfArray();
int capacityOfArray();
void initializeEmptyArray(int *arr);
void appendInTheEnd(int **arr, int value);
bool isEmpty(int *arr);
int FindItemInIndex(int *arr, int index);
void insertAtIndex(int *arr, int index, int value);
bool checkBoundaries(int index);
int pop(int *arr);
void deleteAtIndex(int *arr, int index);             // need refactor
int removeItemMaintainingIndex(int *arr, int value); // need refactor
int findElementByValue(int *arr, int value);
void resizeArray(int **arr, size_t capacity);
