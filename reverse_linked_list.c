#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;   
}
node;

// Prototypes
node * create_list(int n);
void display_nodes(node *list);

int main(void)
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%i", &n);
    node *list = create_list(n);
    printf("Data entered in the list:\n");
    display_nodes(list);
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
    // Create empty list
    node *list = NULL;

    // Add first node
    int num;
    node *m = malloc(sizeof(node));
    if (m != NULL)
    {
        printf("input data for node 1: ");
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
        // reuse m variable but get a new address
        m = malloc(sizeof(node));
        m->number = num;
        m->next = list;
        list = m;
    }
    return list;
}

void display_nodes(node *list)
{
    node *tmp;
    if (list == NULL)
    {
        printf("List is empty.");
    }
    
    for (tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("Data = %i\n", tmp->number);
    }
}