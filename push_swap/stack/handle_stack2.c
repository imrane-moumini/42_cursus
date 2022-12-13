#include "../push_swap.h"

node *ft_before_last_node(node *head)
{
    if (head == NULL)
        return (head);
    if (head -> next == NULL)
        return (NULL);
    while (head -> next -> next != NULL)
    {
        head = head -> next;
    }
    return (head);
}
void ft_reverse_rotate(node **head, node *last_node, node *before_last_node)
{
    node *ptr;
    node *tmp;
    ptr = *head; 
    if (ptr == NULL)
        return;
    if (ptr -> next == NULL)
        return;
    else
    {
        tmp = ptr -> next;
        *head = last_node;
        last_node -> next = tmp;
        before_last_node -> next = ptr;
        ptr -> next = NULL;
        tmp = NULL;
        ptr = NULL; 
    }
}