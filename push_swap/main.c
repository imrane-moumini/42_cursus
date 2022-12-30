/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:02:58 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/30 17:58:24 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int argc, char *argv[])
{

    //char **str;
    int i;
    int save_argc;
    int *tab;
    int nbr;
    i = 0;
    // check error tab

    if (argc == 1)
    {
        ft_printf("empty stack \n");
        exit (1);
    }
    if (check_empty_stack(argv[1]) == 1)
    {
        ft_printf("im here\n");
        ft_printf("empty stack \n");
        exit (1);
    }
    save_argc = argc;
    while (argc > 1)
    {
        if (check_ony_number(argv[argc - 1]) == 0)
        {
            ft_printf("not only number \n");
            exit(1);
        }
        argc--;;
    }
    argc = save_argc;
    // creer stack_a and tab
    //str = ft_split(argv[1], ' ');
    
    //i = 1;
    t_node *head_stack_a;
    t_node *save_head_a;
    t_node *save_head_b;
    t_node *ptr;
    head_stack_a = NULL;
    while ((argc) > 1)
    {
        printf("argc-1: %s\n", argv[argc-1]);
        add_beg(ft_atoi(argv[argc-1]), &head_stack_a);
        argc--;
    }
    printf("c1\n");
    nbr = nbr_element_in_stack(head_stack_a);
    tab = create_tab_nbr(nbr, &head_stack_a);
    tri_tab(nbr, tab);
    printf("c2\n");
    ft_printf("-------------------\n");
    ft_printf("tab \n");
    while (i < nbr)
    {
        ft_printf("%i\n",tab[i]);
        i++;
    }
    printf("c3\n");
    //i = 0;
    // check stack a
    if (check_doublon_list(head_stack_a))
    {
        ptr = head_stack_a;
        save_head_a = ptr;
        while (save_head_a != NULL)
        {
            head_stack_a = save_head_a;
            save_head_a = save_head_a -> next;
            free(head_stack_a);
        }
        // while (str[i])
        // {
        //     free(str[i]);
        //     i++;
        // }
        free(tab);
        // free(str);
        ft_printf("error : list has double\n");
        exit(1);
    }
    add_index_to_stack(&head_stack_a, tab, nbr);
    // creer stack_b vide
    t_node *head_stack_b;
    head_stack_b = NULL;
    // affiche stack_a et b
    ptr = head_stack_a;
    ft_printf("---------------------------\n");
    ft_printf("stack a :\n");
    while (ptr != NULL)
    {
        ft_printf(" nb : %i, index: %i\n",ptr -> data, ptr -> index);
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
    if (has_to_tri(&head_stack_a) == 1)
        ft_tri(&head_stack_a, &head_stack_b, nbr);
	else
		ft_printf("stack deja trie\n");
	//rra(&head_stack_a);
    ft_printf("---------------------------\n");
    ft_printf("stack a after function :\n");
    ptr = head_stack_a;
    save_head_a = ptr;
    while (ptr != NULL)
    {
        ft_printf(" data : %i, index : %i, pos : %i\n",ptr -> data, ptr -> index, ptr -> pos);
        ptr = ptr -> next;
    }
    ptr = head_stack_b;
    save_head_b = ptr;
    ft_printf("stack b after function :\n");
    while (ptr != NULL)
    {
        ft_printf(" data : %i, index : %i, pos : %i, target_pos : %i, cost_a : %i, cost_b : %i, final_cost : %i\n",ptr -> data, ptr -> index, ptr -> pos, ptr -> target_pos, ptr -> cost_a, ptr -> cost_b, ptr -> total_cost);
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
    // while (str[i])
    // {
    //     free(str[i]);
    //     i++;
    // }
    // free(str);
    free(tab);
}