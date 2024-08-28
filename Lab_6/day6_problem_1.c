// ------------------------------------------------------------------------------------
// Author: spexcher
// Name: Gourab Modak
// email: spexcher@gmail.com
// Linktree: https://linktr.ee/spexcher/
// Github: https://github.com/spexcher/
// linkedin : https://www.linkedin.com/in/gourabmodak/
// ------------------------------------------------------------------------------------
#include <stdio.h>
#include <time.h>
clock_t startTime;
clock_t endTime;
FILE *fptr;

double getCurrentTime()
{
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
void createArray(int arr[], int n)
{
    fprintf(fptr, "Enter %d elements:\n", n);
    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}



void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)

    {
        fprintf(fptr, "Pass: %d\n", i);
        printf("Pass: %d\n", i);
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void modifiedBubbleSort(int arr[], int n)
{
    int swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped++;
            }
        }
        if (swapped == 0)
        {
            break;
        }
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int main()
{
    fptr = fopen("Output.txt", "a");
    if (fptr == NULL)
    {
        fprintf(fptr, "Error!");
        printf("Error!");
        return 1;
    }
    int n;
    double honolulu;

    fprintf(fptr, "Enter the number of elements in the array: ");
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    createArray(arr, n);

    fprintf(fptr, "\nOriginal array:\n");
    printf("\nOriginal array:\n");
    displayArray(arr, n);
    fprintf(fptr, "\nWhat is the sorting procedure you would like to use:\n");
    printf("\nWhat is the sorting procedure you would like to use:\n");
    fprintf(fptr, "\n1 Selection Sort\n2 Bubble Sort\n3 Modified Bubble Sort\n4 Insertion Sort\n5 Merge Sort\n");
    printf("\n1 Selection Sort\n2 Bubble Sort\n3 Modified Bubble Sort\n4 Insertion Sort\n5 Merge Sort\n");

    int choice;
    scanf("%d", &choice);
    switch (choice)
    {

    case 1:
        startTime = clock();
        selectionSort(arr, n);
        fprintf(fptr, "\nArray after Selection Sort:\n");

        printf("\nArray after Selection Sort:\n");
        honolulu = getCurrentTime();
        fprintf(fptr, "time = %.5lf\n", honolulu);
        printf("time = %.5lf\n", honolulu);
        displayArray(arr, n);
        break;
    case 2:
        startTime = clock();
        bubbleSort(arr, n);

        fprintf(fptr, "\nArray after Bubble Sort:\n");
        printf("\nArray after Bubble Sort:\n");
        honolulu = getCurrentTime();
        fprintf(fptr, "time = %.5lf\n", honolulu);
        printf("time = %.5lf\n", honolulu);
        displayArray(arr, n);
        break;
    case 3:
        startTime = clock();

        modifiedBubbleSort(arr, n);

        fprintf(fptr, "\nArray after Modified Bubble Sort:\n");
        printf("\nArray after Modified Bubble Sort:\n");
        honolulu = getCurrentTime();
        fprintf(fptr, "time = %.5lf\n", honolulu);
        printf("time = %.5lf\n", honolulu);
        displayArray(arr, n);
        break;
    case 4:
        startTime = clock();

        insertionSort(arr, n);

        fprintf(fptr, "\nArray after Insertion Sort:\n");
        printf("\nArray after Insertion Sort:\n");
        honolulu = getCurrentTime();
        fprintf(fptr, "time = %.5lf\n", honolulu);
        printf("time = %.5lf\n", honolulu);
        displayArray(arr, n);
        break;
    case 5:
        startTime = clock();

        mergeSort(arr, 0, n - 1);

        fprintf(fptr, "\nArray after Merge Sort:\n");
        printf("\nArray after Merge Sort:\n");
        honolulu = getCurrentTime();
        fprintf(fptr, "time = %.5lf\n", honolulu);
        printf("time = %.5lf\n", honolulu);
        displayArray(arr, n);
        break;

    default:
        break;
    }
    return 0;
}
