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
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
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
    }
}

void display(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void displayRecursive(struct Node *head)
{
    if (head == NULL)
    {
        printf("NULL\n");
        return;
    }
    printf("%d -> ", head->data);
    displayRecursive(head->next);
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

void reversePrintRecursive(struct Node *head)
{
    if (head == NULL)
    {
        return;
    }
    reversePrintRecursive(head->next);
    printf("%d -> ", head->data);
}

void reverse(struct Node **head)
{
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
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
            current->next = newNode;
            return;
        }
        current = current->next;
    }
    printf("%d not found in the list. Insertion failed.\n", key);
}

void insertBefore(struct Node **head, int key, int data)
{
    struct Node *newNode = createNode(data);
    if (*head != NULL && (*head)->data == key)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node *current = *head;
    while (current != NULL && current->next != NULL)
    {
        if (current->next->data == key)
        {
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
    printf("%d not found in the list. Insertion failed.\n", key);
}

void deleteByValue(struct Node **head, int key)
{
    struct Node *current = *head;
    struct Node *prev = NULL;

    while (current != NULL && current->data != key)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("%d not found in the list. Deletion failed.\n", key);
        return;
    }

    if (prev == NULL)
    {
        *head = current->next;
    }
    else
    {
        prev->next = current->next;
    }

    free(current);
}

void insertBegin(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *head;
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
    free(temp);
}

void deleteLast(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty. Deletion failed.\n");
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node *current = *head;
    struct Node *prev = NULL;
    while (current->next != NULL)
    {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
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
        free(temp);
        return;
    }
    struct Node *current = *head;
    struct Node *prev = NULL;
    int currentPosition = 0;
    while (current != NULL && currentPosition < position)
    {
        prev = current;
        current = current->next;
        currentPosition++;
    }
    if (current == NULL)
    {
        printf("Position %d not found in the list. Deletion failed.\n", position);
        return;
    }
    prev->next = current->next;
    free(current);
}

void deleteBefore(struct Node **head, int key)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        printf("List does not have enough elements to delete before %d. Deletion failed.\n", key);
        return;
    }
    if ((*head)->data == key)
    {
        printf("No element before %d to delete. Deletion failed.\n", key);
        return;
    }
    if ((*head)->next->data == key)
    {
        struct Node *temp = *head;
        *head = temp->next;
        free(temp);
        return;
    }
    struct Node *current = *head;
    struct Node *prev = NULL;
    while (current != NULL && current->next != NULL)
    {
        if (current->next->data == key)
        {
            struct Node *temp = current->next;
            current->next = temp->next;
            free(temp);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("%d not found in the list. Deletion failed.\n", key);
}

void deleteAfter(struct Node **head, int key)
{
    struct Node *current = *head;
    while (current != NULL)
    {
        if (current->data == key && current->next != NULL)
        {
            struct Node *temp = current->next;
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
    struct Node *prev = NULL;
    int currentPosition = 0;
    while (current != NULL && currentPosition < position)
    {
        prev = current;
        current = current->next;
        currentPosition++;
    }
    prev->next = newNode;
    newNode->next = current;
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
        printf("2. Display using recursive function\n");
        printf("3. Search\n");
        printf("4. Reverse print\n");
        printf("5. Reverse the linked list\n");
        printf("6. Insert after a specific element\n");
        printf("7. Insert before a specific element\n");
        printf("8. Delete by element\n");
        printf("9. Insert at the beginning\n");
        printf("10. Delete the first element\n");
        printf("11. Delete the last element (if present)\n");
        printf("12. Delete by position\n");
        printf("13. Delete before a specific element\n");
        printf("14. Delete after a specific element\n");
        printf("15. Insert by position\n");
        printf("16. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Linked List: ");
            display(head);
            break;
        case 2:
            printf("Linked List (recursive): ");
            displayRecursive(head);
            break;
        case 3:
            printf("Enter element to search: ");
            scanf("%d", &key);
            position = search(head, key);
            if (position != -1)
            {
                printf("%d found at position %d\n", key, position);
            }
            else
            {
                printf("%d not found in the list\n", key);
            }
            break;
        case 4:
            printf("Reverse print: ");
            reversePrintRecursive(head);
            printf("NULL\n");
            break;
        case 5:
            reverse(&head);
            printf("Linked List reversed successfully.\n");
            break;
        case 6:
            printf("Enter the element after which to insert: ");
            scanf("%d", &key);
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertAfter(&head, key, data);
            break;
        case 7:
            printf("Enter the element before which to insert: ");
            scanf("%d", &key);
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertBefore(&head, key, data);
            break;
        case 8:
            printf("Enter the element to delete: ");
            scanf("%d", &key);
            deleteByValue(&head, key);
            break;
        case 9:
            printf("Enter data to insert at the beginning: ");
            scanf("%d", &data);
            insertBegin(&head, data);
            break;
        case 10:
            deleteFirst(&head);
            break;
        case 11:
            deleteLast(&head);
            break;
        case 12:
            printf("Enter the position to delete: ");
            scanf("%d", &position);
            deleteByPosition(&head, position);
            break;
        case 13:
            printf("Enter the element before which to delete: ");
            scanf("%d", &key);
            deleteBefore(&head, key);
            break;
        case 14:
            printf("Enter the element after which to delete: ");
            scanf("%d", &key);
            deleteAfter(&head, key);
            break;
        case 15:
            printf("Enter the position to insert: ");
            scanf("%d", &position);
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertByPosition(&head, position, data);
            break;
        case 16:
            printf("Thank you for using this program . We wish you have a nice day");
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
