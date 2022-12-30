/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:11:27 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/30 17:16:18 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	nbr_tab(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	*create_tab_nbr(int nbr, t_node **head_stack_a)
{
	t_node	*ptr;;
	int		*tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(int) * nbr);
	ptr = *head_stack_a;
	while (ptr != NULL)
	{
		tab[i] = ptr -> data;
		i++;
		ptr = ptr -> next;
	}
	return (tab);
}

void	tri_tab(int nbr, int *tab)
{
	int	i;
	int	save;

	i = 0;
	while (i < nbr)
	{
		if (i + 1 < nbr && tab[i] > tab[i + 1])
		{
			save = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = save;
			i = 0;
		}
		else
			i++;
	}
}

void	check_data_in_stack(t_node **head, int nb, int i)
{
	t_node	*ptr;

	ptr = *head;
	// printf("HFIHUBFBUWf\n");
	while (ptr != NULL)
	{
		if (ptr -> data == nb)
			ptr -> index = i;
		ptr = ptr -> next;
	}
}

void	add_index_to_stack(t_node **head, int *tab, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		check_data_in_stack(head, tab[i], i);
		i++;
	}
}
