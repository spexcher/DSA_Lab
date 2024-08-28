/*----------------------------------------------------------------
AUTHOR: spexcher
Name: Gourab Modak
email: gm2623@cse.jgec.ac.in
Institution: Jalpaiguri Government Engineering College (B. Tech UG CSE 4 year)
Github: https://github.com/gauravthedeveloper/
linkedin : https://www.linkedin.com/in/gourabmodak/
codeforces : https://codeforces.com/profile/sectumsempra07/
codechef : https://www.codechef.com/users/sectumsempra07/
leetcode : https://leetcode.com/sectumsempra07/
----------------------------------------------------------------
*/
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