// ------------------------------------------------------------------------------------
// Author: spexcher
// Name: Gourab Modak
// email: spexcher@gmail.com
// Linktree: https://linktr.ee/spexcher/
// Github: https://github.com/spexcher/
// linkedin : https://www.linkedin.com/in/gourabmodak/
// ------------------------------------------------------------------------------------
// #include<graphics.h>
#include <stdio.h>
int main()
{
    FILE *f1 = fopen("a1.txt", "r");
    char cc[200];
    FILE *f2 = fopen("a2.txt", "w");
    if (fgets(cc, 200, f1) != NULL)
    {
        printf("%s\n", cc);
        fputs(cc, f2);
    }
    fclose(f1);
    fclose(f2);

    return 0;
}
