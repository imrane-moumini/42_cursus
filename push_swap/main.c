#include "push_swap.h"


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return (1);
    }
    char **str;
    int i;
    i = 0;
    str = ft_split(argv[1], ' ');
    // crer la premiere stack
    node *head_stack_a;
    head_stack_a = NULL;
    while (str[i])
    {
        add_beg(ft_atoi(str[i]), &head_stack_a);
        i++;
    }
    node *ptr;
    ptr = head_stack_a;
    ft_printf("---------------------------\n");
    while (ptr != NULL)
    {
        ft_printf("in stack is %i\n",ptr -> data);
        ptr = ptr -> next;

    }
    
}