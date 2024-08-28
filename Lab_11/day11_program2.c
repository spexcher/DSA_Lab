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
--------------------------------------------------------------------
*/
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
