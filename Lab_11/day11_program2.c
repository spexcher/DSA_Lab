// ------------------------------------------------------------------------------------
// Author: spexcher
// Name: Gourab Modak
// email: spexcher@gmail.com
// Linktree: https://linktr.ee/spexcher/
// Github: https://github.com/spexcher/
// linkedin : https://www.linkedin.com/in/gourabmodak/
// ------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

void towerOfHanoi(int n, char A, char B, char C)
{
    if (n == 0)
        return;
    towerOfHanoi(n - 1, A, C, B);
    printf("Move %d  disk %c to %c\n", n, A, B);
    towerOfHanoi(n - 1, C, B, A);
}

int main()
{
    int a;
    printf("Enter the number of disks");
    scanf("%d", &a);
    towerOfHanoi(a, 'A', 'B', 'C');

    return 0;
}
