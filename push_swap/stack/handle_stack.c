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

void del_first_node(node **head)
{
    node *ptr;
    node *tmp;
    ptr = *head; 
    if (ptr == NULL)
        return;
    if (ptr -> next == NULL)
    {
        free(ptr);
        *head = NULL;
        ptr = NULL;
        return;
    }
    else
    {
        tmp = ptr -> next;
        *head = tmp;
        free(ptr);
        ptr = NULL;
        tmp = NULL;
    }

}

void ft_swap(node **head)
{
    node *ptr;
    int nbr;
    ptr = *head;
    
    if (ptr == NULL)
        return;
    if (ptr -> next == NULL)
        return;
    else
    {
        nbr = ptr -> next -> data;
        ptr -> next -> data = ptr -> data;
        ptr -> data = nbr;
        ptr = NULL; 
    }
}

node *ft_last_node(node *head)
{
    if (head == NULL)
        return (head);
    if (head -> next == NULL)
        return (head);
    while (head -> next != NULL)
    {
        head = head -> next;
    }
    return (head);
}

void ft_rotate(node **head, node *last_node)
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
        *head = tmp;
        last_node -> next = ptr;
        ptr -> next = NULL;
        tmp = NULL;
        ptr = NULL;
    }
}


