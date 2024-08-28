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
