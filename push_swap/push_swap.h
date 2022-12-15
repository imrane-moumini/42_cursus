/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:03:14 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/15 18:26:55 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack_node {
	int					data;
	struct s_stack_node	*next;
}	t_node;

void	add_beg(int stack_data, t_node **head);
void	del_first_node(t_node **head);
void	ft_swap(t_node **head);
t_node	*ft_last_node(t_node *head);
void	ft_rotate(t_node **head, t_node *last_node);
t_node	*ft_before_last_node(t_node *head);
void	ft_reverse_rotate(t_node **head);
void	sa(t_node **head_stack_a);
void	sb(t_node **head_stack_b);
void	ss(t_node **head_stack_a, t_node **head_stack_b);
void	ra(t_node **head_stack_a);
void	rb(t_node **head_stack_b);
void	rr(t_node **head_stack_a, t_node **head_stack_b);
void	rra(t_node **head_stack_a);
void	rrb(t_node **head_stack_b);
void	rrr(t_node **head_stack_a, t_node **head_stack_b);
void	pb(t_node **head_stack_a, t_node **head_stack_b);
void	pa(t_node **head_stack_a, t_node **head_stack_b);
#endif