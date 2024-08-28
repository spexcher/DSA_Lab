#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void display(struct Node *head)
{
    struct Node *current = head;
    printf("Forward ");
    struct Node *last = NULL;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        last = current;
        current = current->next;
    }
    printf("NULL\n");
    current = last;
    printf("Back ");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

void displayReverse(struct Node *head)
{
    struct Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    while (current != NULL)
    {
        printf("%d <-> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

int search(struct Node *head, int key)
{
    struct Node *current = head;
    int position = 0;
    while (current != NULL)
    {
        if (current->data == key)
        {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1;
}

void reverse(struct Node **head)
{
    struct Node *current = *head;
    struct Node *temp = NULL;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
    {
        *head = temp->prev;
    }
}

void insertAfter(struct Node **head, int key, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *current = *head;
    while (current != NULL)
    {
        if (current->data == key)
        {
            newNode->next = current->next;
            if (current->next != NULL)
            {
                current->next->prev = newNode;
            }
            current->next = newNode;
            newNode->prev = current;
            return;
        }
        current = current->next;
    }
    printf("%d not found in the list. Insertion failed.\n", key);
}

void insertBefore(struct Node **head, int key, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *current = *head;
    while (current != NULL)
    {
        if (current->data == key)
        {
            newNode->next = current;
            newNode->prev = current->prev;
            if (current->prev != NULL)
            {
                current->prev->next = newNode;
            }
            else
            {
                *head = newNode;
            }
            current->prev = newNode;
            return;
        }
        current = current->next;
    }
    printf("%d not found in the list. Insertion failed.\n", key);
}

void deleteByValue(struct Node **head, int key)
{
    struct Node *current = *head;
    while (current != NULL)
    {
        if (current->data == key)
        {
            if (current->prev != NULL)
            {
                current->prev->next = current->next;
            }
            else
            {
                *head = current->next;
            }
            if (current->next != NULL)
            {
                current->next->prev = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
    printf("%d not found in the list. Deletion failed.\n", key);
}

void insertBegin(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void deleteFirst(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty. Deletion failed.\n");
        return;
    }
    struct Node *temp = *head;
    *head = temp->next;
    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }
    free(temp);
}

void deleteLast(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty. Deletion failed.\n");
        return;
    }
    struct Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    if (current->prev != NULL)
    {
        current->prev->next = NULL;
    }
    else
    {
        *head = NULL;
    }
    free(current);
}

void deleteByPosition(struct Node **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty. Deletion failed.\n");
        return;
    }
    if (position == 0)
    {
        struct Node *temp = *head;
        *head = temp->next;
        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }
    struct Node *current = *head;
    int currentPosition = 0;
    while (current != NULL && currentPosition < position)
    {
        current = current->next;
        currentPosition++;
    }
    if (current == NULL)
    {
        printf("Position %d not found in the list. Deletion failed.\n", position);
        return;
    }
    if (current->prev != NULL)
    {
        current->prev->next = current->next;
    }
    else
    {
        *head = current->next;
    }
    if (current->next != NULL)
    {
        current->next->prev = current->prev;
    }
    free(current);
}

void deleteBefore(struct Node **head, int key)
{
    struct Node *current = *head;
    while (current != NULL)
    {
        if (current->data == key && current->prev != NULL)
        {
            struct Node *temp = current->prev;
            if (temp->prev != NULL)
            {
                temp->prev->next = current;
            }
            else
            {
                *head = current;
            }
            current->prev = temp->prev;
            free(temp);
            return;
        }
        current = current->next;
    }
    printf("No element before %d to delete. Deletion failed.\n", key);
}

void deleteAfter(struct Node **head, int key)
{
    struct Node *current = *head;
    while (current != NULL)
    {
        if (current->data == key && current->next != NULL)
        {
            struct Node *temp = current->next;
            if (temp->next != NULL)
            {
                temp->next->prev = current;
            }
            current->next = temp->next;
            free(temp);
            return;
        }
        current = current->next;
    }
    printf("No element after %d to delete. Deletion failed.\n", key);
}

void insertByPosition(struct Node **head, int position, int data)
{
    if (position < 0)
    {
        printf("Invalid position. Insertion failed.\n");
        return;
    }
    if (position == 0 || *head == NULL)
    {
        insertBegin(head, data);
        return;
    }
    struct Node *newNode = createNode(data);
    struct Node *current = *head;
    int currentPosition = 0;
    while (current != NULL && currentPosition < position)
    {
        current = current->next;
        currentPosition++;
    }
    if (current == NULL)
    {
        printf("Position %d not found in the list. Insertion failed.\n", position);
        return;
    }
    newNode->prev = current->prev;
    newNode->next = current;
    if (current->prev != NULL)
    {
        current->prev->next = newNode;
    }
    else
    {
        *head = newNode;
    }
    current->prev = newNode;
}

int main()
{
    struct Node *head = NULL;
    int choice, data, key, position;

    do
    {
        printf("Enter data to insert: ");
        scanf("%d", &data);
        insertEnd(&head, data);

        printf("Do you want to continue entering data? (1/0): ");
        scanf("%d", &choice);
    } while (choice != 0);

    while (1)
    {
        printf("\n1. Display\n");
        printf("2. Display in reverse\n");
        printf("3. Search\n");
        printf("4. Reverse the linked list\n");
        printf("5. Insert after a specific element\n");
        printf("6. Insert before a specific element\n");
        printf("7. Delete by element\n");
        printf("8. Insert at the beginning\n");
        printf("9. Delete the first element\n");
        printf("10. Delete the last element (if present)\n");
        printf("11. Delete by position\n");
        printf("12. Delete before a specific element\n");
        printf("13. Delete after a specific element\n");
        printf("14. Insert by position\n");
        printf("15. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Linked List: ");
            display(head);
            break;
        case 2:
            printf("Linked List (Reverse): ");
            displayReverse(head);
            break;
        case 3:
            printf("Enter element to search: ");
            scanf("%d", &key);
            position = search(head, key);
            if (position != -1)
            {
                printf("%d found at position %d\n", key, position + 1);
            }
            else
            {
                printf("%d not found in the list\n", key);
            }
            break;
        case 4:
            reverse(&head);
            printf("Linked List reversed successfully.\n");
            break;
        case 5:
            printf("Enter the element after which to insert: ");
            scanf("%d", &key);
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertAfter(&head, key, data);
            break;
        case 6:
            printf("Enter the element before which to insert: ");
            scanf("%d", &key);
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertBefore(&head, key, data);
            break;
        case 7:
            printf("Enter the element to delete: ");
            scanf("%d", &key);
            deleteByValue(&head, key);
            break;
        case 8:
            printf("Enter data to insert at the beginning: ");
            scanf("%d", &data);
            insertBegin(&head, data);
            break;
        case 9:
            deleteFirst(&head);
            break;
        case 10:
            deleteLast(&head);
            break;
        case 11:
            printf("Enter the position to delete: (Starts with 1)");
            scanf("%d", &position);
            deleteByPosition(&head, position - 1);
            break;
        case 12:
            printf("Enter the element before which to delete: ");
            scanf("%d", &key);
            deleteBefore(&head, key);
            break;
        case 13:
            printf("Enter the element after which to delete: ");
            scanf("%d", &key);
            deleteAfter(&head, key);
            break;
        case 14:
            printf("Enter the position to insert:(Starts with 1) ");
            scanf("%d", &position);
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertByPosition(&head, position - 1, data);
            break;
        case 15:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
