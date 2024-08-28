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

#include <stdio.h>
#include <stdlib.h>

// Create Node
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int max(int a, int b);

// Calculate height
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Create a node
struct Node *newNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

// Right rotate
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotate
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
struct Node *insertNode(struct Node *node, int key)
{
    if (node == NULL)
        return (newNode(key));

    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
void printCurrentLevel(struct Node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->key);
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
void printLevelOrder(struct Node *root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
void printPreOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}
void printInOrder(struct Node *root)
{
    if (root != NULL)
    {
        printInOrder(root->left);
        printf("%d ", root->key);
        printInOrder(root->right);
    }
}
void printPostOrder(struct Node *root)
{
    if (root != NULL)
    {
        printPostOrder(root->left);
        printPostOrder(root->right);
        printf("%d ", root->key);
    }
}
int search(struct Node *root, int value)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root && root->key == value)
    {
        return 1;
    }
    else if (value < root->key)
    {
        search(root->left, value);
    }
    else if (value > root->key)
    {
        search(root->right, value);
    }
    return 0;
}
int main()
{
    struct Node *root = NULL;
    int choice, specialchoice, value;
    do
    {
        printf("Enter data to insert: ");
        scanf("%d", &value);
        root = insertNode(root, value);

        printf("Do you want to continue entering data? (1/0): ");
        scanf("%d", &specialchoice);
    } while (specialchoice != 0);

    while (1)
    {
        printf("\nAVL Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. In-order Traversal\n");
        printf("3. Pre-order Traversal\n");
        printf("4. Post-order Traversal\n");
        printf("5. Level-order Traversal\n");
        printf("6. Search\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insertNode(root, value);
            break;
        case 2:
            printf("In-order Traversal: ");
            printInOrder(root);
            printf("\n");
            break;
        case 3:
            printf("Pre-order Traversal: ");
            printPreOrder(root);
            printf("\n");
            break;
        case 4:
            printf("Post-order Traversal: ");
            printPostOrder(root);
            printf("\n");
            break;
        case 5:
            printf("Level-order Traversal: ");
            printLevelOrder(root);
            printf("\n");
            break;
        case 6:
            printf("Enter value to search: ");
            scanf("%d", &value);
            if (search(root, value))
            {
                printf("Value found in the tree.\n");
            }
            else
            {
                printf("Value not found in the tree.\n");
            }
            break;
        case 7:
            printf("Thank You for using our program we wish you have a great day.\n");
            exit(0);
        default:
            printf("Invalid choice. Please Rerun the program with appropritate choices. \n Wish you have a great day");
        }
    }

    return 0;
}