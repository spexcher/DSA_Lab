// ------------------------------------------------------------------------------------
// Author: spexcher
// Name: Gourab Modak
// email: spexcher@gmail.com
// Linktree: https://linktr.ee/spexcher/
// Github: https://github.com/spexcher/
// linkedin : https://www.linkedin.com/in/gourabmodak/
// ------------------------------------------------------------------------------------
#include <stdio.h>
int main()
{

    char str[500];
    printf("Enter the string\n");
    scanf("%[^\n]s", str);
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        count++;
    }
    char rev[500];
    int pp = 0;
    for (int i = count - 1; i >= 0; i--)
    {
        rev[pp] = str[i];
        pp++;
    }

    printf("The reverse of the string is    %s\n", rev);
    printf("The number of characters in the string is    %d\n", count);

    return 0;
}
