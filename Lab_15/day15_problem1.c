
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef VECTOR_H
#define VECTOR_H

#define VECTOR_INIT_CAPACITY 100

#define VECTOR_INIT(vec) \
    vector vec;          \
    vector_init(&vec)
#define VECTOR_ADD(vec, item) vector_add(&vec, (void *)item)
#define VECTOR_SET(vec, id, item) vector_set(&vec, id, (void *)item)
#define VECTOR_GET(vec, type, id) (type) vector_get(&vec, id)
#define VECTOR_DELETE(vec, id) vector_delete(&vec, id)
#define VECTOR_TOTAL(vec) vector_total(&vec)
#define VECTOR_FREE(vec) vector_free(&vec)

typedef struct vector
{
    void **items;
    int capacity;
    int total;
} vector;

void vector_init(vector *);
int vector_total(vector *);
static void vector_resize(vector *, int);
void vector_add(vector *, void *);
void vector_set(vector *, int, void *);
void *vector_get(vector *, int);
void vector_delete(vector *, int);
void vector_free(vector *);

#endif

void vector_init(vector *v)
{
    v->capacity = VECTOR_INIT_CAPACITY;
    v->total = 0;
    v->items = malloc(sizeof(void *) * v->capacity);
}

int vector_total(vector *v)
{
    return v->total;
}

static void vector_resize(vector *v, int capacity)
{
#ifdef DEBUG_ON
    printf("vector_resize: %d to %d\n", v->capacity, capacity);
#endif

    void **items = realloc(v->items, sizeof(void *) * capacity);
    if (items)
    {
        v->items = items;
        v->capacity = capacity;
    }
}

void vector_add(vector *v, void *item)
{
    if (v->capacity == v->total)
        vector_resize(v, v->capacity * 2);
    v->items[v->total++] = item;
}

void vector_set(vector *v, int index, void *item)
{
    if (index >= 0 && index < v->total)
        v->items[index] = item;
}

void *vector_get(vector *v, int index)
{
    if (index >= 0 && index < v->total)
        return v->items[index];
    return NULL;
}

void vector_delete(vector *v, int index)
{
    if (index < 0 || index >= v->total)
        return;

    v->items[index] = NULL;
    int i;
    for (i = 0; i < v->total - 1; i++)
    {
        v->items[i] = v->items[i + 1];
        v->items[i + 1] = NULL;
    }

    v->total--;

    if (v->total > 0 && v->total == v->capacity / 4)
        vector_resize(v, v->capacity / 2);
}

void vector_free(vector *v)
{
    free(v->items);
}

int main(void)
{
    int i;

    vector v;
    vector av[67];
    vector_init(&v);
    for (int i = 0; i < 67; i++)
    {
        vector_init(&av[i]);
    }
    vector al[67];
    for (int i = 0; i < 67; i++)
    {
        vector_init(&al[i]);
    }
    int n;
    printf("Enter the number of nodes\n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix representing the graph: ");
    int x;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &x);
            vector_add(&av[i], x);
        }
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            printf("%d ", vector_get(&av[i], j));
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vector_get(&av[i], j) != 0)
                vector_add(&al[i], j);
        }
        // printf("\n");
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d th node is connected to-> ", i);
        for (int j = 0; j < vector_total(&al[i]); j++)
        {
            printf("%d ", vector_get(&al[i], j));
        }
        printf("\n");
    }
    printf("\n");
    printf("DFS...\n");
    bool visited[n];
    int stack_ptr = 0;
    int stack[n];
    for (int i = 0; i < n; i++)
    {
        stack_ptr = 0;
        stack[0] = i;
        while (stack_ptr != -1)
        {
            int curr = stack[stack_ptr];
            stack_ptr--;

            if (visited[curr] == false)
                printf("%d ", curr);
            visited[curr] = true;

            for (int j = 0; j < vector_total(&al[curr]); j++)
            {
                if (visited[j] == false)
                    stack[++stack_ptr] = vector_get(&al[curr], j);
            }
        }
    }
    // bool visited2[n];
    // int qptr_ptrf = 0;
    // int queue[4 * n];
    // for (int i = 0; i < n; i++)
    // {
    //     qptr_ptrf  = 0;
    //     queue[0] = i;
    //     while (stack_ptr != -1)
    //     {
    //         int curr = stack[stack_ptr];
    //         stack_ptr--;

    //         if (visited[curr] == false)
    //             printf("%d ", curr);
    //         visited[curr] = true;

    //         for (int j = 0; j < vector_total(&al[curr]); j++)
    //         {
    //             if (visited[j] == false)
    //                 stack[++stack_ptr] = vector_get(&al[curr], j);
    //         }
    //     }
    // }

    // vector_add(&av[2], 67);
    // printf("%d ", vector_get(&av[2], 0));

    // vector_add(&v, 1);
    // vector_add(&v, 2);
    // vector_add(&v, 3);
    // vector_add(&v, 4);

    // for (i = 0; i < vector_total(&v); i++)
    //     printf("%d ", vector_get(&v, i));
    // printf("\n");

    // vector_delete(&v, 3);
    // vector_delete(&v, 2);
    // vector_delete(&v, 1);

    // // vector_set(&v, 0, "Hello");
    // // vector_add(&v, "World");

    // for (i = 0; i < vector_total(&v); i++)
    //     printf("%d ", vector_get(&v, i));
    // printf("\n");

    // vector_free(&v);
}
