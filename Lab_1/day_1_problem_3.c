// ------------------------------------------------------------------------------------
// Author: spexcher
// Name: Gourab Modak
// email: spexcher@gmail.com
// Linktree: https://linktr.ee/spexcher/
// Github: https://github.com/spexcher/
// linkedin : https://www.linkedin.com/in/gourabmodak/
// ------------------------------------------------------------------------------------
#include <stdio.h>
#include <math.h>
void findpositions(int *arr, int search, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == search)
        {
            printf("found at position %d\n", i + 1);
            return;
        }
    }
    printf("Not found\n");
}
int main()
{
    int n;
    printf("Enter the number of elements\n");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search\n");
    int search;
    scanf("%d", &search);
    printf("All the elements are as follows:\n");
    for (int i = 0; i < n; i++)

        printf("%d ", arr[i]);
    printf("\n");
    findpositions(arr, search, n);

    return 0;
}
