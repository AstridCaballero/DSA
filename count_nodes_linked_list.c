#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}node;

//Prototypes
node * create_list(int n);
int count_nodes(node *list);

int main(void)
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%i", &n);
    // Get nodes and store them in a linked list
    node *list = create_list(n);
    int nodes = count_nodes(list);
    printf("Total number of nodes = %i\n", nodes);
    // free list
    // I need to free what is behind
    while (list != NULL)
    {
        node *temp = list->next;
        free (list);
        list = temp;
    }
    return 0;
}

node * create_list(int n)
{
    // create empty list
    node *list = NULL;

    // Add first node
    int num;
    node *m = malloc(sizeof(node));
    if (m != NULL)
    {
        printf("Input data for node 1: ");
        scanf("%i", &num);
        m->number = num;
        m->next = NULL;
        list = m;
    }

    // Add the rest of the nodes
    // New node goes to the beginning of the list
    int i;
    for (i = 2; i <= n; i++)
    {
        printf("Input data for node %i: ", i);
        // reuse num variable
        scanf("%i", &num);
        // reuse m variable but get new address
        m = malloc(sizeof(node));
        m->number = num;
        m->next = list;
        list = m;
    }
    return list;
}

int count_nodes(node *list)
{
    int counter = 0;
    node *tmp;
    if (list == NULL)
    {
        printf("List is empty.");
    }
    for (tmp = list; tmp != NULL; tmp = tmp->next)
    {
        counter++;
    }
    return counter;
}