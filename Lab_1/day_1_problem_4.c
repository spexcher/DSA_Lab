// ------------------------------------------------------------------------------------
// Author: spexcher
// Name: Gourab Modak
// email: spexcher@gmail.com
// Linktree: https://linktr.ee/spexcher/
// Github: https://github.com/spexcher/
// linkedin : https://www.linkedin.com/in/gourabmodak/
// ------------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int count = 0;
void permutation(char *a, int l, int r)
{
    if (l == r)
    {
        printf("%s\n", a);
        count++;
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(&a[l], &a[i]);
            permutation(a, l + 1, r);
            swap(&a[l], &a[i]);
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of characters\n");
    scanf("%d", &n);
    char str[n + 1];
    printf("Enter the string\n");
    scanf("%s", str);
    int counter = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        counter++;
    }
    if (counter != n)
    {
        printf("Please enter the correct number of characters as the length you entered and rerun the program\n");
        return 0;
    }
    printf("\n\nThe possible permutations are as follows\n");
    permutation(str, 0, n - 1);
    printf("The total number of possible combinations is %d\n", count);
    return 0;
}
