/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:26:48 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/27 17:01:55 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// etape 6

// index min == 0
// fucntion max index
int	find_index_max(t_node **head_stack_a)
{
	int max;
	t_node *ptr;
	
	max = 0;
	if (head_stack_a == NULL)
		return (0);
	if (*head_stack_a == NULL)
		return (0);
	ptr = *head_stack_a;
	max = ptr -> index;
	while (ptr != NULL)
	{
		if (max < ptr -> index)
			max = ptr -> index;
		ptr = ptr -> next;
	}
	return (max);
}

void mark_min_and_max_index(t_node **head_stack_a, int max)
{
	t_node *ptr;
	if (head_stack_a == NULL)
		return ;
	if (*head_stack_a == NULL)
		return ;
	ptr = *head_stack_a;
	while (ptr != NULL)
	{
		if (ptr -> index == 0)
			ptr -> min_index = 1;
		if (ptr -> index == max)
			ptr -> max_index = 1;
		ptr = ptr -> next;
	}
}

int is_index_zero_on_top(t_node **head_stack_a)
{
	t_node *ptr;
	
	if (head_stack_a == NULL)
		return (0);
	if (*head_stack_a == NULL)
		return (0);
	ptr = *head_stack_a;
	if (ptr -> index == 0)
		return (1);
	else
		return (0);
}

int is_index_max_on_bottom(t_node **head_stack_a, int max)
{
	t_node *ptr;
	
	if (head_stack_a == NULL)
		return (0);
	if (*head_stack_a == NULL)
		return (0);
	ptr = *head_stack_a;
	while (ptr -> next != NULL)
		ptr = ptr -> next;
	if (ptr -> index == max)
		return (1);
	else
		return (0);
}

void ft_calculate_coup_to_min(t_node **head_stack_a,t_node *ptr)
{
	int nbr;
	int lenght;
	
	nbr = nbr_element_in_stack(*head_stack_a)/2;
	lenght = nbr_element_in_stack(*head_stack_a);
	if (nbr % 2 == 1)
		nbr = nbr + 1;
	if (ptr -> pos == 1)
	{
		ptr -> cost_a = 0;
		return ;
	}
	if (ptr -> pos <= nbr)
		ptr -> cost_a = lenght - ptr -> target_pos;
	if (ptr -> pos > nbr)
		ptr -> cost_a = ((lenght - ptr -> target_pos) + 1) * -1;
}

void ft_execute_instruction_min(t_node **head_stack_a, t_node **head_stack_b,t_node *ptr)
{
	int i;

	i = 0;
	if (ptr -> cost_a > 0)
	{
		while (i < ptr -> cost_a && ptr -> cost_a != 0)
		{
			ra(head_stack_a, head_stack_b);
			i++;
		}
	}
	else
	{
		ptr -> cost_a = ptr -> cost_a * -1;
		while (i < ptr -> cost_a && ptr -> cost_a != 0)
		{
			rra(head_stack_a, head_stack_b);
			i++;
		}
	}
}
// limite mettre une boucle pour voir si tout est bon
// regarder lindez qui est le plus petit et le mettre tout en haut
    // regarder la position pour voir si je fais ra ou rra
    // faire le calcul pour avoir cb jen fait
void	put_min_index_top(t_node **head_stack_a)
{
	int max;
	t_node *ptr;
	
	if (head_stack_a == NULL)
		return ;
	if (*head_stack_a == NULL)
		return ;
	ptr = *head_stack_a;
	max = find_index_max(head_stack_a);
	mark_min_and_max_index(head_stack_a, max);
	ft_calculate_pos(head_stack_a, NULL);
	if (is_index_zero_on_top(head_stack_a) == 0)
	{
		while (ptr != NULL)
		{
			if (ptr -> index == 0)
			{
				ft_calculate_coup_to_min(head_stack_a, ptr);
				ft_execute_instruction_min(head_stack_a,NULL,ptr);
			}
			ptr = ptr -> next;
		}
	}
	
}
// regarder lindex qui est le plus grand et le mettre tout en bas
    //reflechir au resonement a linverse pour etre tout en ba
// regardder si ca a permis de trier