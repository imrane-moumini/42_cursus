/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:03:14 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/16 23:01:49 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack_node {
	int					data;
	int					index;
	int					pos;
	int					target_pos;
	int					cost_a;
	int					cost_b;
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
int		check_doublon_list(t_node *head);
int		check_ony_number(char *str);
int		check_empty_stack(char *str);
int *create_tab_nbr(char **str);
int nbr_tab(char **str);
void tri_tab(int nbr, int *tab);
void check_data_in_stack(t_node **head, int nb, int i);
void add_index_to_stack(t_node **head, int *tab, int max);
int has_to_tri(t_node **head);
void ft_tri(t_node **head_stack_a, t_node **head_stack_b, int nbr);
#endif