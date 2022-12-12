#include "../push_swap.h"

void add_beg(int stack_data, node **head)
{
    node *ptr;
    node *tmp;
    ptr = malloc(sizeof(node));
    ptr -> data = stack_data;
    ptr -> next = NULL;
    if (*head == NULL)
    {
        *head = ptr;
        return;
    }
    tmp = *head;
    *head = ptr;
    ptr -> next = tmp;
}