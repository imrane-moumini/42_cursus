/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:48:57 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/31 16:51:31 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void check_first_error(int argc, char *argv[])
{
     if (argc == 1)
    {
        ft_printf("Error \n");
        exit (1);
    }
    if (check_empty_stack(argv[1]) == 1)
    {
        ft_printf("Error\n");
        exit (1);
    }
    while (argc > 1)
    {
        if (check_ony_number(argv[argc - 1]) == 0)
        {
            ft_printf("Error \n");
            exit(1);
        }
        argc--;;
    }
    check_int_limit(argv);
}

void create_stack_a(int argc, t_node **head_stack_a, char *argv[])
{
	while ((argc) > 1)
    {
        //printf("argc-1: %s\n", argv[argc-1]);
        add_beg(ft_atoi(argv[argc-1]), head_stack_a);
        argc--;
    }
}

void ft_free(t_node *head_stack_a, t_node *head_stack_b, int *tab)
{
	t_node *save_head_a;
    t_node *save_head_b;
    save_head_a = head_stack_a;
    save_head_b = head_stack_b;
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
    free(tab);
}