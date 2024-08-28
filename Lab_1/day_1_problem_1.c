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
int main()
{

    int i, n;
    int t1 = 0, t2 = 1;
    int nextTerm = t1 + t2;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Enter the process of use:\n1.For loop\n2.While loop\n3.Do-while loop\n");
    int way;
    scanf("%d", &way);
    switch (way)
    {
    case 1:
        if (n == 1)
        {
            printf("Fibonacci Series: %d \n", t1);
            return 0;
        }
        else if (n == 2)
            printf("Fibonacci Series: %d %d \n", t1, t2);
        else
        {

            printf("Fibonacci Series: %d %d ", t1, t2);

            for (i = 3; i <= n; ++i)
            {
                printf("%d ", nextTerm);
                t1 = t2;
                t2 = nextTerm;
                nextTerm = t1 + t2;
            }
        }
        break;
    case 2:
        if (n == 1)
        {
            printf("Fibonacci Series: %d \n", t1);
            return 0;
        }
        else if (n == 2)
            printf("Fibonacci Series: %d %d \n", t1, t2);
        else
        {

            printf("Fibonacci Series: %d %d ", t1, t2);

            i = 3;
            while (i <= n)
            {
                printf("%d ", nextTerm);
                t1 = t2;
                t2 = nextTerm;
                nextTerm = t1 + t2;
                i++;
            }
        }
        printf("\n");
        break;
    case 3:
        if (n == 1)
        {
            printf("Fibonacci Series: %d \n", t1);
            return 0;
        }
        else if (n == 2)
            printf("Fibonacci Series: %d %d \n", t1, t2);
        else
        {

            printf("Fibonacci Series: %d %d ", t1, t2);

            i = 3;
            do
            {
                printf("%d ", nextTerm);
                t1 = t2;
                t2 = nextTerm;
                nextTerm = t1 + t2;
                i++;
            } while (i <= n);
        }
        printf("\n");

        break;

    default:
        break;
    }

    return 0;
}