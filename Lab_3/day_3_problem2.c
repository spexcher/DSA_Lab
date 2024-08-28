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
// #include<graphics.h>
#include <stdio.h>
int main()
{
    FILE *f1 = fopen("a1.txt", "r");
    char character_array[200];
    FILE *f2 = fopen("a2.txt", "w");
    if (fgets(character_array, 200, f1) != NULL)
    {
        printf("%s\n", character_array);
        fputs(character_array, f2);
    }
    fclose(f1);
    fclose(f2);

    return 0;
}