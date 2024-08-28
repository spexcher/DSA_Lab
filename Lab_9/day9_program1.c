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

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node *insertAtBeginning(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = head->next;
    head->next = newNode;
    return head;
}

void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *current = head;
    do
    {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

struct Node *deleteNode(struct Node *head, int key)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return head;
    }
    struct Node *current = head;
    struct Node *prev = NULL;

    while (current->data != key)
    {
        if (current->next == head)
        {
            printf("Node with key %d not found in the list.\n", key);
            return head;
        }
        prev = current;
        current = current->next;
    }

    if (current->next == head)
    {
        free(current);
        return NULL;
    }

    if (current == head)
    {
        prev = head;
        while (prev->next != head)
        {
            prev = prev->next;
        }
        head = head->next;
        prev->next = head;
        free(current);
    }
    else
    {
        prev->next = current->next;
        free(current);
    }

    return head;
}

int search(struct Node *head, int key)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return 0;
    }
    struct Node *current = head;
    int position = 1;
    do
    {
        if (current->data == key)
        {
            printf("Node with key %d found at position %d.\n", key, position);
            return 1;
        }
        current = current->next;
        position++;
    } while (current != head);
    printf("Node with key %d not found in the list.\n", key);
    return 0;
}

struct Node *insertAfter(struct Node *head, int key, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        printf("List is empty.\n");
        return head;
    }
    struct Node *current = head;
    do
    {
        if (current->data == key)
        {
            newNode->next = current->next;
            current->next = newNode;
            return head;
        }
        current = current->next;
    } while (current != head);
    printf("Node with key %d not found in the list. Insertion failed.\n", key);
    free(newNode);
    return head;
}

struct Node *insertBefore(struct Node *head, int key, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        printf("List is empty.\n");
        return head;
    }
    struct Node *current = head;
    struct Node *prev = NULL;
    do
    {
        if (current->data == key)
        {
            if (current == head)
            {
                prev = head;
                while (prev->next != head)
                {
                    prev = prev->next;
                }
                head = newNode;
                newNode->next = current;
                prev->next = newNode;
            }
            else
            {
                newNode->next = current;
                prev->next = newNode;
            }
            return head;
        }
        prev = current;
        current = current->next;
    } while (current != head);
    printf("Node with key %d not found in the list. Insertion failed.\n", key);
    free(newNode);
    return head;
}

struct Node *deleteBefore(struct Node *head, int key)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return head;
    }
    struct Node *current = head;
    struct Node *prev = NULL;
    struct Node *prevPrev = NULL;

    do
    {
        if (current->data == key)
        {
            if (prev == NULL)
            {
                printf("No node found before the node with key %d.\n", key);
                return head;
            }

            if (prev == head)
            {
                prevPrev = head;
                while (prevPrev->next != head)
                {
                    prevPrev = prevPrev->next;
                }
                head = current;
                prevPrev->next = head;
            }
            else
            {
                prevPrev->next = current;
            }

            free(prev);
            return head;
        }
        prevPrev = prev;
        prev = current;
        current = current->next;
    } while (current != head);

    printf("Node with key %d not found in the list. Deletion failed.\n", key);
    return head;
}

struct Node *deleteAfter(struct Node *head, int key)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return head;
    }
    struct Node *current = head;
    struct Node *prev = NULL;

    do
    {
        if (current->data == key)
        {
            if (current->next == head)
            {
                printf("No node found after the node with key %d.\n", key);
                return head;
            }
            struct Node *nodeToDelete = current->next;
            current->next = nodeToDelete->next;
            free(nodeToDelete);
            return head;
        }
        prev = current;
        current = current->next;
    } while (current != head);

    printf("Node with key %d not found in the list. Deletion failed.\n", key);
    return head;
}
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    struct Node *current = head;
    while (current->next != head)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = head;
    return head;
}
int main()
{
    struct Node *head = NULL;
    int choice, data, key;
    int creationdata;
    printf("Welcome! to circular linked list visualizer\n");
    int special;
    do
    {
        printf("Enter the data you want to insert into the list");
        scanf("%d", &creationdata);
        head = insertAtBeginning(head, creationdata);
        printf("Enter 1 to continue entering values and 0 to stop entering values");
        scanf("%d", &special);

    } while (special != 0);

    do
    {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert After\n");
        printf("3. Insert Before\n");
        printf("4. Delete\n");
        printf("5. Delete After\n");
        printf("6. Delete Before\n");
        printf("7. Display\n");
        printf("8. Search\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert at the beginning: ");
            scanf("%d", &data);
            head = insertAtBeginning(head, data);
            break;
        case 2:
            printf("Enter key after which to insert: ");
            scanf("%d", &key);
            printf("Enter data to insert: ");
            scanf("%d", &data);
            head = insertAfter(head, key, data);
            break;
        case 3:
            printf("Enter key before which to insert: ");
            scanf("%d", &key);
            printf("Enter data to insert: ");
            scanf("%d", &data);
            head = insertBefore(head, key, data);
            break;
        case 4:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            head = deleteNode(head, key);
            break;
        case 5:
            printf("Enter key after which to delete: ");
            scanf("%d", &key);
            head = deleteAfter(head, key);
            break;
        case 6:
            printf("Enter key before which to delete: ");
            scanf("%d", &key);
            head = deleteBefore(head, key);
            break;
        case 7:
            display(head);
            break;
        case 8:
            printf("Enter key to search: ");
            scanf("%d", &key);
            search(head, key);
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (1);

    return 0;
}
