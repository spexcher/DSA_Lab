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