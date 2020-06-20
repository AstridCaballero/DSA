#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int num;
    struct node *next;    
}
node;

// prototype
void display_nodes(node *list);

int main(void)
{
    // to get some data
    int n;
    printf("Number of nodes: ");
    scanf("%i", &n);

    // Create empty list
    node *list = NULL;
    // Add first node
    int num;
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        return 1;
    }
    printf("Enter node 1:");
    scanf("%i", &num);
    new_node->num = num;
    new_node->next = NULL;
    list = new_node;

    // Add the remaining nodes
    int i;
    for (i = 1; i < n; i++)
    {
        new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return 1;
        }
        printf("enter node %i: ", i + 1);
        scanf("%i", &num);
        new_node->num = num;
        new_node->next = list;
        list = new_node;
    }
    printf("Data entered in the list:\n");
    display_nodes(list);  

    /*Remove Duplicates*/

    // check linked list and get the length
    int len = 0;    
    node *temp = list;
    while (temp != NULL)
    {
        len ++;
        temp = temp->next; 

    }
    
    printf("total nodes: %i\n", len);

    //create hash table
    int *table = malloc(len * sizeof(int));
    memset(table, 0, sizeof(int));
    // iterate over linked list to check number
   
    node *previous_node = NULL;
    node *current = list;
    while (current != NULL)
    {
        // get a hash or a key
        int hash = current->num % len;
        // check node ith
        if (table[hash] == 0)
        {
            // insert number in hash table
            table[hash] = current->num;
            // get before_node to point at the current node
            previous_node = current;            
        }
        else
        {
            // link the previous node to the node pointed at by the dupe.
           previous_node->next = current->next;
        }
        current = current->next;        
    }

    // print dedup linked list
    printf("Data in deduped list:\n");
    display_nodes(list);   
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
        printf("Data = %i\n", tmp->num);
    }
}