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
void middle_insert(int len, node *list);
void display_nodes(node *list);

int main(void)
{
    // Prepare variables
    int n;
    node *list;
    // Get data
    printf("Enter number of nodes(3 or more): ");
    scanf("%i", &n);
    // create list
    list = create_list(n);
    // insert in the middle
    middle_insert(n, list);
    // print
    display_nodes(list);
    // free list
    // I need to free what is behind me
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
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

    node *temp = list;
    // Add the rest of the nodes
    // new node goes to the end of the list
    int i;
    for (i = 2; i <= n; i++)
    {
        printf("Input data for node %i: ", i);        
        scanf("%i", &num);
        m = malloc(sizeof(node));
        m->number = num;
        m->next = NULL;
        temp->next = m;
        temp = temp->next;
    }
    return list;
}

void middle_insert(int len, node *list)
{
    // get the middle position
    int mid;
    mid = len / 2;
    
    // Move mid times along the list
    int i;
    node *current = list;
    for (i = 0; i < mid - 1; i++)
    {
        current = current->next;
    }
    // get the new node to insert in the middle
    int num;
    node *n = malloc(sizeof(node));
    if (n != NULL)
    {
        printf("Enter number for new node: ");
        scanf("%i", &num);
        n->number = num;
        n->next = current->next;
        current->next = n;
    }     
}

void display_nodes(node *list)
{
    node *temp;
    if (list == NULL)
    {
        printf("List is empty.");
    }
    for (temp = list; temp != NULL; temp = temp->next)
    {
        printf("Data = %i\n", temp->number);
    }
}