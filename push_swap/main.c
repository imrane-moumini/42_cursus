/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:02:58 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/15 18:27:51 by imoumini         ###   ########.fr       */
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
    t_node *save_head_b;
    head_stack_a = NULL;

    // creer stack_a
    while (str[i])
    {
        add_beg(ft_atoi(str[i]), &head_stack_a);
        i++;
    }
    i = 0;
    // creer stack_b vide
    t_node *head_stack_b;
    head_stack_b = NULL;
    // affiche stack_a et b
    t_node *ptr;
    ptr = head_stack_a;
    ft_printf("---------------------------\n");
    ft_printf("stack a :\n");
    while (ptr != NULL)
    {
        ft_printf(" %i\n",ptr -> data);
        ptr = ptr -> next;
    }
    ptr = head_stack_b;
    ft_printf("stack b :\n");
    while (ptr != NULL)
    {
        ft_printf(" %i\n",ptr -> data);
        ptr = ptr -> next;
    }
     // test fonctions
    pb(&head_stack_a, &head_stack_b);
    pb(&head_stack_a, &head_stack_b);
    pb(&head_stack_a, &head_stack_b);
    pb(&head_stack_a, &head_stack_b);
    pa(&head_stack_a, &head_stack_b);
    ptr = head_stack_a;
    save_head_a = ptr;
    ft_printf("---------------------------\n");
    ft_printf("stack a after function :\n");
    while (ptr != NULL)
    {
        ft_printf(" %i\n",ptr -> data);
        ptr = ptr -> next;
    }
    ptr = head_stack_b;
    save_head_b = ptr;
    ft_printf("stack b after function :\n");
    while (ptr != NULL)
    {
        ft_printf(" %i\n",ptr -> data);
        ptr = ptr -> next;
    }
    // free
    while (save_head_a != NULL)
    {
        head_stack_a = save_head_a;
        save_head_a = save_head_a -> next;
        free(head_stack_a);
    }
    while (save_head_b != NULL)
    {
        head_stack_b = save_head_b;
        save_head_b = save_head_b -> next;
        free(head_stack_b);
    }
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}