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

#define MAX_SIZE 10000

struct Stack
{
    int data[MAX_SIZE];
    int top;
};

void initialize(struct Stack *stack)
{
    stack->top = -1;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

int isFull(struct Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Stack is full. Cannot push element %d.\n", value);
        return;
    }
    stack->data[++stack->top] = value;
    printf("Pushed %d onto the stack.\n", value);
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty. Cannot pop.\n");
        exit(1);
    }
    int value = stack->data[stack->top--];
    return value;
}

void display(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents: ");
    for (int i = 0; i <= stack->top; i++)
    {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main()
{
    struct Stack stack;
    initialize(&stack);

    int choice, value;

    int creationdata;
    printf("Welcome! to stack visualizer\n");
    int special = 0;
    do
    {
        printf("Enter value to push into stack: ");
        scanf("%d", &creationdata);
        push(&stack, creationdata);
        printf("Enter 1 to continue entering values and 0 to stop entering values");
        scanf("%d", &special);

    } while (special != 0);

    while (1)
    {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(&stack, value);
            break;
        case 2:
            if (!isEmpty(&stack))
            {
                printf("Popped value: %d\n", pop(&stack));
            }
            break;
        case 3:
            display(&stack);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
