/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:02:58 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/16 22:47:55 by imoumini         ###   ########.fr       */
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
    int *tab;
    int nbr;
    i = 0;
    // check error tab
    if (check_empty_stack(argv[1]) == 1)
    {
        ft_printf("empty stack \n");
        exit (1);
    }
    if (check_ony_number(argv[1]) == 0)
    {
        ft_printf("not only number \n");
        exit(1);
    }
    
    // creer stack_a and tab
    str = ft_split(argv[1], ' ');
    nbr = nbr_tab(str);
    tab = create_tab_nbr(str);
    tri_tab(nbr, tab);
    ft_printf("-------------------\n");
    ft_printf("tab \n");
    while (i < nbr)
    {
        ft_printf("%i\n",tab[i]);
        i++;
    }
    i = 0;
    t_node *head_stack_a;
    t_node *save_head_a;
    t_node *save_head_b;
    t_node *ptr;
    head_stack_a = NULL;
    while (str[i])
    {
        add_beg(ft_atoi(str[i]), &head_stack_a);
        i++;
    }
    i = 0;
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
        while (str[i])
        {
            free(str[i]);
            i++;
        }
        free(tab);
        free(str);
        ft_printf("error : list has double\n");
        exit(1);
    }
    add_index_to_stack(&head_stack_a, tab, nbr);
    ft_printf("has to tri %i\n",has_to_tri(&head_stack_a));
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
    pb( &head_stack_a,  &head_stack_b);
    pb( &head_stack_a,  &head_stack_b);
    pb( &head_stack_a,  &head_stack_b);
    sa( &head_stack_a);
    sb( &head_stack_b);
    ss( &head_stack_a,  &head_stack_b);
    ra( &head_stack_a);
    rb( &head_stack_b);
    rr( &head_stack_a,  &head_stack_b);
    rra( &head_stack_a);
    rrb( &head_stack_b);
    rrr( &head_stack_a,  &head_stack_b);
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
    free(tab);
}