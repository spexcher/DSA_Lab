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
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Function to check if a character is an operator
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to return the precedence of an operator
int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    return 0;
}

// Function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[])
{
    int i, j;
    char stack[MAX_SIZE];
    int top = -1; // Stack top pointer

    for (i = 0, j = 0; infix[i] != '\0'; i++)
    {
        char character_under_proposition = infix[i];

        if (isalnum(character_under_proposition))
        {
            postfix[j++] = character_under_proposition;
        }
        else if (character_under_proposition == '(')
        {
            stack[++top] = character_under_proposition;
        }
        else if (character_under_proposition == ')')
        {
            while (top >= 0 && stack[top] != '(')
            {
                postfix[j] = stack[top];
                j++;
                top--;
            }
            if (top >= 0 && stack[top] == '(')
            {
                top--; // Pop the '(' from the stack
            }
        }
        else if (isOperator(character_under_proposition))
        {
            while (top >= 0 && precedence(stack[top]) >= precedence(character_under_proposition))
            {
                postfix[j] = stack[top];
                j++;
                top--;
            }
            stack[++top] = character_under_proposition;
        }
    }

    // Pop any remaining operators from the stack
    while (top >= 0)
    {
        postfix[j] = stack[top];
        j++;
        top--;
    }

    postfix[j] = '\0';
}

int main()
{
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
