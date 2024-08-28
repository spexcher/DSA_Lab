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

#define MAX_SIZE 5

struct QueueNode
{
    int data;
    struct QueueNode *next;
};

struct StaticQueue
{
    int front, rear;
    int data[MAX_SIZE];
};

struct DynamicQueue
{
    struct QueueNode *front;
    struct QueueNode *rear;
};

struct CircularQueue
{
    int front, rear;
    int data[MAX_SIZE];
};

void initStaticQueue(struct StaticQueue *queue)
{
    queue->front = queue->rear = -1;
}

int isStaticQueueEmpty(struct StaticQueue *queue)
{
    return (queue->front == -1);
}

int isStaticQueueFull(struct StaticQueue *queue)
{
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

void insertStaticQueue(struct StaticQueue *queue, int value)
{
    if (isStaticQueueFull(queue))
    {
        printf("Static Queue is full. Cannot insert.\n");
        return;
    }
    if (isStaticQueueEmpty(queue))
        queue->front = queue->rear = 0;
    else
        queue->rear = (queue->rear + 1) % MAX_SIZE;

    queue->data[queue->rear] = value;
}

void deleteStaticQueue(struct StaticQueue *queue)
{
    if (isStaticQueueEmpty(queue))
    {
        printf("Static Queue is empty. Cannot delete.\n");
        return;
    }

    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % MAX_SIZE;
}

void displayStaticQueue(struct StaticQueue *queue)
{
    if (isStaticQueueEmpty(queue))
    {
        printf("Static Queue is empty.\n");
        return;
    }

    int i;
    for (i = queue->front; i != queue->rear; i = (i + 1) % MAX_SIZE)
        printf("%d <- ", queue->data[i]);
    printf("%d\n", queue->data[i]);
}

void initDynamicQueue(struct DynamicQueue *queue)
{
    queue->front = queue->rear = NULL;
}

int isDynamicQueueEmpty(struct DynamicQueue *queue)
{
    return (queue->front == NULL);
}

void insertDynamicQueue(struct DynamicQueue *queue, int value)
{
    struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    newNode->data = value;
    newNode->next = NULL;

    if (isDynamicQueueEmpty(queue))
    {
        queue->front = queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

void deleteDynamicQueue(struct DynamicQueue *queue)
{
    if (isDynamicQueueEmpty(queue))
    {
        printf("Dynamic Queue is empty. Cannot delete.\n");
        return;
    }

    struct QueueNode *temp = queue->front;

    queue->front = queue->front->next;
    free(temp);
}

void displayDynamicQueue(struct DynamicQueue *queue)
{
    if (isDynamicQueueEmpty(queue))
    {
        printf("Dynamic Queue is empty.\n");
        return;
    }

    struct QueueNode *current = queue->front;
    while (current != NULL)
    {
        printf("%d <- ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void initCircularQueue(struct CircularQueue *queue)
{
    queue->front = queue->rear = -1;
}

int isCircularQueueEmpty(struct CircularQueue *queue)
{
    return (queue->front == -1);
}

int isCircularQueueFull(struct CircularQueue *queue)
{
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

void insertCircularQueue(struct CircularQueue *queue, int value)
{
    if (isCircularQueueFull(queue))
    {
        printf("Circular Queue is full. Cannot insert.\n");
        return;
    }
    if (isCircularQueueEmpty(queue))
        queue->front = queue->rear = 0;
    else
        queue->rear = (queue->rear + 1) % MAX_SIZE;

    queue->data[queue->rear] = value;
}

void deleteCircularQueue(struct CircularQueue *queue)
{
    if (isCircularQueueEmpty(queue))
    {
        printf("Circular Queue is empty. Cannot delete.\n");
        return;
    }

    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % MAX_SIZE;
}

void displayCircularQueue(struct CircularQueue *queue)
{
    if (isCircularQueueEmpty(queue))
    {
        printf("Circular Queue is empty.\n");
        return;
    }

    int i = queue->front;
    while (1)
    {
        printf("%d <- ", queue->data[i]);
        if (i == queue->rear)
            break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main()
{
    struct StaticQueue staticQueue;
    struct DynamicQueue dynamicQueue;
    struct CircularQueue circularQueue;

    initStaticQueue(&staticQueue);
    initDynamicQueue(&dynamicQueue);
    initCircularQueue(&circularQueue);

    int choice, innerchoice, value, specialchoice, data;

    printf("\nQueue Operations Menu:\n");
    printf("1. Static Queue\n");
    printf("2. Dynamic Queue\n");
    printf("3. Circular Queue\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        do
        {
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertStaticQueue(&staticQueue, data);

            printf("Do you want to continue entering data? (1/0): ");
            scanf("%d", &specialchoice);
        } while (specialchoice != 0);

        do
        {
            printf("\nStatic Queue Operations:\n");
            printf("1. Insert\n");
            printf("2. Delete\n");
            printf("3. Display\n");
            printf("4. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &innerchoice);

            switch (innerchoice)
            {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertStaticQueue(&staticQueue, value);
                break;
            case 2:
                deleteStaticQueue(&staticQueue);
                break;
            case 3:
                displayStaticQueue(&staticQueue);
                break;
            case 4:
                printf("Thank You for using our program we wish you have a great day.\n");
                break;
            default:
                printf("Invalid choice. Please Rerun the program with appropritate choices. \n Wish you have a great day.\n\n");
                break;
            }
        } while (innerchoice <= 3 && innerchoice >= 1);

        break;

    case 2:
        do
        {
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertDynamicQueue(&dynamicQueue, data);

            printf("Do you want to continue entering data? (1/0): ");
            scanf("%d", &specialchoice);
        } while (specialchoice != 0);

        do
        {
            printf("\nDynamic Queue Operations:\n");
            printf("1. Insert\n");
            printf("2. Delete\n");
            printf("3. Display\n");
            printf("4. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &innerchoice);

            switch (innerchoice)
            {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertDynamicQueue(&dynamicQueue, value);
                break;
            case 2:
                deleteDynamicQueue(&dynamicQueue);
                break;
            case 3:
                displayDynamicQueue(&dynamicQueue);
                break;
            case 4:
                printf("Thank You for using our program we wish you have a great day.\n");
                break;
            default:
                printf("Invalid choice. Please Rerun the program with appropritate choices. \n Wish you have a great day");
                break;
            }
        } while (innerchoice <= 3 && innerchoice >= 1);
        break;

    case 3:
        do
        {
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertCircularQueue(&circularQueue, data);

            printf("Do you want to continue entering data? (1/0): ");
            scanf("%d", &specialchoice);
        } while (specialchoice != 0);

        do
        {
            printf("\nCircular Queue Operations:\n");
            printf("1. Insert\n");
            printf("2. Delete\n");
            printf("3. Display\n");
            printf("4. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &innerchoice);

            switch (innerchoice)
            {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertCircularQueue(&circularQueue, value);
                break;
            case 2:
                deleteCircularQueue(&circularQueue);
                break;
            case 3:
                displayCircularQueue(&circularQueue);
                break;
            case 4:
                printf("Thank You for using our program we wish you have a great day.\n");
                break;
            default:
                printf("Invalid choice. Please Rerun the program with appropritate choices. \n Wish you have a great day");
                break;
            }
        } while (innerchoice <= 3 && innerchoice >= 1);
        break;

    case 4:
        printf("Thank You for using our program we wish you have a great day.\n");
        exit(0);
    default:
        printf("Invalid choice. Please Rerun the program with appropritate choices. \n Wish you have a great day");
        break;
    }

    return 0;
}
