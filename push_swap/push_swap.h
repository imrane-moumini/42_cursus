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
#endif