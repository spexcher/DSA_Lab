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
int main()
{

    int n;
    printf("Enter 1 for prime number checking\n");
    printf("Enter 2 for armstrong number checking\n");
    printf("Enter 3 for entering three numbers and print their maximum\n");
    scanf("%d", &n);

    int q;
    int count;
    int a, b, c;
    int maximum = a;
    switch (n)
    {
    case 1:
        printf("Enter a number \n");
        scanf("%d", &q);
        count = 0;
        for (int i = 2; i * i <= q; i++)
        {
            if (q % i == 0)
                count++;
        }
        if (count > 0)
        {
            printf("%d is not a prime number\n", q);
        }
        else
            printf("%d is a prime number\n", q);

        break;
    case 2:
        printf("Enter a number \n");
        scanf("%d", &q);
        int l = q;
        count = 0;
        while (l > 0)
        {
            count++;
            l /= 10;
        }
        l = q;

        long long ans = 0;
        while (l > 0)
        {
            int p = 1;
            for (int i = 0; i < count; i++)
            {
                p *= (l % 10);
            }
            ans += p;
            l /= 10;
        }

        if (ans == q)
        {
            printf("%d is an armstrong number\n", q);
        }
        else
            printf("%d is not an armstrong number\n", q);

        break;
    case 3:
        printf("Enter 3 numbers \n");
        scanf("%d %d %d", &a, &b, &c);
        if (a > b)
        {
            if (a > c)
                maximum = a;
            else
                maximum = c;
        }
        else
        {
            if (b > c)
                maximum = b;
            else
                maximum = c;
        }
        printf("Maximum of %d %d %d is %d\n", a, b, c, maximum);
    default:
        break;
    }

    return 0;
}
