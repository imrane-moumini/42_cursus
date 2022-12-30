/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:14:20 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/30 18:44:57 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// etape 3
void ft_calculate_positions(t_node **head_stack_a, t_node **head_stack_b)
{
    ft_calculate_pos(head_stack_a, head_stack_b);
    ft_calculate_target_pos(head_stack_a, head_stack_b);
}

// etape 4
void ft_calculate_cost(t_node **head_stack_a, t_node **head_stack_b)
{
	t_node *ptr_b;
	
	if (head_stack_a == NULL || head_stack_b == NULL)
		return ;
	ptr_b = *head_stack_b;
	while (ptr_b != NULL)
	{
		ft_pile_b_calculate(head_stack_b,ptr_b);
		ft_pile_a_calculate(head_stack_a,ptr_b);
		ft_final_cost_calculate(ptr_b);
		ptr_b = ptr_b -> next;
	}
	//ft_printf("in calculate cost \n");
	//ft_printf_stack(head_stack_a, head_stack_b); 
	
}

void ft_pile_b_calculate(t_node **head_stack_b, t_node *ptr)
{
	int nbr;
	int lenght;
	
	nbr = nbr_element_in_stack(*head_stack_b)/2;
	lenght = nbr_element_in_stack(*head_stack_b);
	if (nbr % 2 == 1)
		nbr = nbr + 1;

	if (ptr -> pos == 1)
	{
		ptr -> cost_b = 0;
		return ;
	}
	if (ptr -> pos <= nbr)
	{
		ptr -> cost_b = ptr -> pos - 1;
	}
	if (ptr -> pos > nbr)
		ptr -> cost_b = ((lenght - ptr -> pos) + 1) * -1;
}

void ft_pile_a_calculate(t_node **head_stack_a,t_node *ptr_b)
{
	int nbr;
	int lenght;
	
	nbr = nbr_element_in_stack(*head_stack_a)/2;
	lenght = nbr_element_in_stack(*head_stack_a);
	if (nbr % 2 == 1)
		nbr = nbr + 1;
	if (ptr_b -> target_pos == 1)
	{
		ptr_b -> cost_a = 0;
		return ;
	}
	if (ptr_b -> target_pos <= nbr)
		ptr_b -> cost_a = ptr_b -> target_pos - 1;
	if (ptr_b -> target_pos > nbr)
		ptr_b -> cost_a = ((lenght - ptr_b->target_pos) + 1) * -1;
}

void ft_final_cost_calculate(t_node *ptr_b)
{
	if (ptr_b -> cost_b < 0 && ptr_b -> cost_a < 0)
	{
		ptr_b -> total_cost = ((ptr_b -> cost_b) * -1) + ((ptr_b -> cost_a) * -1);
		return ;
	}
	if (ptr_b -> cost_b < 0 || ptr_b -> cost_a < 0)
	{
		if (ptr_b -> cost_b < 0)
		{
			ptr_b -> total_cost = ((ptr_b -> cost_b) * -1) + ((ptr_b -> cost_a));
			return ;
		}
		else
		{
			ptr_b -> total_cost = ((ptr_b -> cost_b)) + ((ptr_b -> cost_a) * -1);
			return ;
		}
	}
	ptr_b -> total_cost = ((ptr_b -> cost_b)) + ((ptr_b -> cost_a));
}