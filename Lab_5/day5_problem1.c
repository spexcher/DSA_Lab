// ------------------------------------------------------------------------------------
// Author: spexcher
// Name: Gourab Modak
// email: spexcher@gmail.com
// Linktree: https://linktr.ee/spexcher/
// Github: https://github.com/spexcher/
// linkedin : https://www.linkedin.com/in/gourabmodak/
// ------------------------------------------------------------------------------------
#include <stdio.h>

#define MAX_SIZE (int)1e7

int createArray(int arr[], int size)
{
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    return size;
}

void displayArray(int arr[], int size)
{
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int linearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int isSortedAscending(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return 0;
        }
    }
    return 1;
}

int isSortedDescending(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            return 0;
        }
    }
    return 1;
}

int binarySearchDescending(int arr[], int size, int target)
{
    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int target)
{
    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int insertElement(int arr[], int *size, int position, int element)
{
    if (*size >= MAX_SIZE)
    {
        printf("Array is full. Cannot insert.\n");
        return *size;
    }

    if (position < 0 || position > *size)
    {
        printf("Invalid position for insertion.\n");
        return *size;
    }

    for (int i = *size; i > position; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;

    return *size;
}

int deleteByPosition(int arr[], int *size, int position)
{
    if (*size <= 0 || position < 0 || position >= *size)
    {
        printf("Invalid position for deletion.\n");
        return *size;
    }

    for (int i = position; i < *size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*size)--;

    return *size;
}

int deleteByItem(int arr[], int *size, int item)
{
    int position = linearSearch(arr, *size, item);
    if (position == -1)
    {
        printf("Element not found in the array.\n");
        return *size;
    }

    for (int i = position; i < *size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*size)--;

    return *size;
}

int main()
{
    int arr[MAX_SIZE];
    int size = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    size = createArray(arr, size);

    int choice, target, position, element, item;

    while (1)
    {
        printf("\nArray Operations:\n");
        printf("1. Display\n2. Linear Search\n3. Binary Search\n");
        printf("4. Insertion\n5. Deletion by Position\n6. Deletion by Item\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayArray(arr, size);
            break;
        case 2:
            printf("Enter the target element: ");
            scanf("%d", &target);
            position = linearSearch(arr, size, target);
            if (position != -1)
            {
                printf("Element %d found at index %d.\n", target, position);
            }
            else
            {
                printf("Element not found in the array.\n");
            }
            break;
        case 3:
            printf("Enter the target element: ");
            scanf("%d", &target);
            if (isSortedAscending(arr, size))
            {
                position = binarySearch(arr, size, target);
                if (position != -1)
                {
                    printf("Element %d found at index %d.\n", target, position);
                }
                else
                {
                    printf("Element not found in the array.\n");
                }
            }
            else if (isSortedDescending(arr, size))
            {
                position = binarySearchDescending(arr, size, target);
                if (position != -1)
                {
                    printf("Element %d found at index %d.\n", target, position);
                }
                else
                {
                    printf("Element not found in the array.\n");
                }
            }
            else
            {
                printf("Array is not sorted. Binary search cannot be performed.\n");
            }
            break;
        case 4:
            printf("Enter the position for insertion: ");
            scanf("%d", &position);
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            size = insertElement(arr, &size, position, element);
            break;
        case 5:
            printf("Enter the position for deletion: ");
            scanf("%d", &position);
            size = deleteByPosition(arr, &size, position - 1);
            break;
        case 6:
            printf("Enter the item to delete: ");
            scanf("%d", &item);
            size = deleteByItem(arr, &size, item);
            break;
        case 7:
            printf("Exiting the program.\n");
            return 0;
        default:
            printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}
