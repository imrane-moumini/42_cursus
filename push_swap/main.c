/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:02:58 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/15 17:33:39 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    t_node *head_stack_a;
    t_node *save_head_a;
    head_stack_a = NULL;

    // creer stack_a
    while (str[i])
    {
        add_beg(ft_atoi(str[i]), &head_stack_a);
        i++;
    }
    i = 0;
    // creer stack_b
    
    // affiche stack_a
    t_node *ptr;
    ptr = head_stack_a;
    ft_printf("---------------------------\n");
    while (ptr != NULL)
    {
        ft_printf(" %i\n",ptr -> data);
        ptr = ptr -> next;
    }

     // test fonctions
    rra(&head_stack_a);
    ptr = head_stack_a;
    save_head_a = ptr;
    ft_printf("---------------------------\n");
    while (ptr != NULL)
    {
        ft_printf(" %i\n",ptr -> data);
        ptr = ptr -> next;
    }
    
    // free stack_a
    while (save_head_a != NULL)
    {
        head_stack_a = save_head_a;
        save_head_a = save_head_a -> next;
        free(head_stack_a);
    }
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
    // free stack_b
}