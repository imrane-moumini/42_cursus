#ifndef PUSH_SWAP
#define PUSH_SWAP
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct stack_node {
    int data;
    struct stack_node *next;
} node;


void add_beg(int stack_data, node **head);
void del_first_node(node **head);
void ft_swap(node **head);
node *ft_last_node(node *head);
void ft_rotate(node **head, node *last_node);
node *ft_before_last_node(node *head);
void ft_reverse_rotate(node **head, node *last_node, node *before_last_node);
#endif