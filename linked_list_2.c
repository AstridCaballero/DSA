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
    printf("Input the number of nodes: ");
    scanf("%i", &n);
    node *list = create_list(n);
    printf("Data entered in the list : \n");
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
    // Create a temp variable and store 'list' there. 'temp' will allow to access the latest node
    node *temp = list;

    // Add the rest of the nodes
    // new node goes to the end of the list
    int i;
    for (i = 2; i <= n; i++)
    {
        printf("Input data for node %i: ", i);
        // reuse num variable
        scanf("%i", &num);
        // reuse m but get new address
        m = malloc(sizeof(node));
        m->number = num;
        m->next = NULL;
        // Use 'temp' to access the previous node and store the address of the new node
        temp->next = m;
        // update the value of temp to store the address of the latest node
        temp = temp->next; 
    }    
    return list;        
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