#include <stdio.h>
#include <stdlib.h>

// 'struct node' is the formal name
typedef struct node
{
    int number;
    // pointer to a node structure. Stores the address of next node
    struct node *next;
}
node;
// 'node' is the alias name
int main(void)
{
    // create an empty list called 'list'
    node *list = NULL;

    // if I want to store a node I need to have space for the number 
    // and the address to the next node so sizeof(node) will take care of that
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    // Add first number
    // set a node to the value 2, we can use (*n) which means "go there", go to the address stored in n
    // and then acces the 'number' field and set it equal to 2 as per the below:
    // (*n).number = 2;
    // but the below sintax is better
    n->number = 2;
    n->next = NULL;
    // get the address of 'n' stored in list
    list = n;

    // Add second number
    // reuse the n pointer but now will get a new address by calling malloc
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 3;
    n->next = NULL;
    // Go to the address stored in 'list', once in there go to 'next' and stored there the value of 'n'
    list->next = n;

    // Add a third number
    // reuse 'n' and store in 'n' a new address
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 5;
    n->next = NULL;
    // Go to the address stored in 'list', once in there go to the address in 'next', once in there go to next
    // and store there the value of 'n' 
    list->next->next = n;

    // print list
    node *tmp;    
    for (tmp = list; tmp != NULL; tmp = tmp->next) // tmp points at the same 'list' is pointing
                                                    //do this until tmp is NULL
                                                    // update tmp with the address of next node
    {
        printf("%i\n", tmp->number);
    }

    // free list
    // I need to free what is behind me
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
}

    // // if I want to add another node but at the beginning of the list then 
    // //I need to create a temp variable that will point to the same node than 'list'
    // node *temp = list;
    // // then I can follow the bread crumps looking at the value of 'next', if the value is not 'null'
    // // it means there is another node, so temp has to go there
    // while (temp->next != NULL)
    // {
    //     temp = temp->next;
    // }

