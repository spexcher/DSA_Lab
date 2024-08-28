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
#include <stdbool.h>

#define MAX_SIZE 1000000

bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '&' || ch == '|');
}

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^' || ch == '&' || ch == '|')
        return 3;
    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    int i, j;
    char stack[MAX_SIZE];
    int top = -1;

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
                top--;
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

    while (top >= 0)
    {
        postfix[j] = stack[top];
        j++;
        top--;
    }

    postfix[j] = '\0';
}

int operate_with_sign(int first_operator, int second_operator, char operator)
{
    int result;
    switch (operator)
    {
    case '+':
        return first_operator + second_operator;
    case '-':
        return first_operator - second_operator;
    case '*':
        return first_operator * second_operator;
    case '/':
        if (second_operator != 0)
        {
            return first_operator / second_operator;
        }
        else
        {
            printf("Why are you trying to divide by zero \n Please rerun the program with a proper input\n");
            exit(1);
        }
    case '^':
        result = 1;
        for (int i = 0; i < second_operator; i++)
        {
            result *= first_operator;
        }
        return result;
    default:
        return 0;
    }
}

int evaluatePostfix(char postfix[])
{
    int stack[MAX_SIZE];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char sign = postfix[i];

        if (isdigit(sign))
        {
            stack[++top] = sign - '0';
        }
        else if (isOperator(sign))
        {
            int second_operator = stack[top--];
            int first_operator = stack[top--];
            int result = operate_with_sign(first_operator, second_operator, sign);
            stack[++top] = result;
        }
    }

    return stack[top];
}
int evaluatePostfixmulti(char postfix[])
{
    int stack[MAX_SIZE];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char token = postfix[i];

        if (isdigit(token))
        {
            int operand = 0;
            while (isdigit(postfix[i]))
            {
                operand = operand * 10 + (postfix[i] - '0');
                i++;
            }
            i--; // Decrement i to account for the extra increment in the loop
            stack[++top] = operand;
        }
        else if (isOperator(token))
        {
            int operand2 = stack[top--];
            int operand1 = stack[top--];
            int result = operate_with_sign(operand1, operand2, token);
            stack[++top] = result;
        }
    }

    return stack[top];
}

int main()
{
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter an infix expression: of max size %d\n", MAX_SIZE);
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result of evaluation: %d\n", result);

    return 0;
}