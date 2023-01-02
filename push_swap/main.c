/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:02:58 by imoumini          #+#    #+#             */
/*   Updated: 2023/01/02 21:01:44 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		*tab;
	int		nbr;
	t_node	*head_stack_a;
	t_node	*head_stack_b;

	head_stack_a = NULL;
	head_stack_b = NULL;
	if (argc == 1 || argc == 2)
		exit (1);
	check_first_error(argc, argv);
	create_stack_a(argc, &head_stack_a, argv);
	nbr = nbr_element_in_stack(head_stack_a);
	tab = create_tab_nbr(nbr, &head_stack_a);
	tri_tab(nbr, tab);
	if (check_doublon_list(head_stack_a))
	{
		ft_free(head_stack_a, head_stack_b, tab);
		return (write(2, "Error\n", 6), 1);
	}
	add_index_to_stack(&head_stack_a, tab, nbr);
	if (has_to_tri(&head_stack_a) == 1)
		ft_tri(&head_stack_a, &head_stack_b, nbr);
	ft_free(head_stack_a, head_stack_b, tab);
}
