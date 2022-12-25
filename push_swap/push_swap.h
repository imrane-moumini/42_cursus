/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:03:14 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/25 20:33:25 by imoumini         ###   ########.fr       */
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
	int					total_cost;
	int					index_sup;
	int					pos_diff;
	struct s_stack_node	*next;
}	t_node;

typedef struct s_calculate {
	int		node_pos;
	int		node_index_diff;
	int		index_greater;
	int		mini_index;
} t_calculate;

void	add_beg(int stack_data, t_node **head);
void	del_first_node(t_node **head);
void	ft_swap(t_node **head);
t_node	*ft_last_node(t_node *head);
void	ft_rotate(t_node **head, t_node *last_node);
t_node	*ft_before_last_node(t_node *head);
void	ft_reverse_rotate(t_node **head);
void	sa(t_node **head_stack_a, t_node **head_stack_b);
void	sb(t_node **head_stack_a, t_node **head_stack_b);
void	ss(t_node **head_stack_a, t_node **head_stack_b);
void	ra(t_node **head_stack_a, t_node **head_stack_b);
void	rb(t_node **head_stack_a, t_node **head_stack_b);
void	rr(t_node **head_stack_a, t_node **head_stack_b);
void	rra(t_node **head_stack_a, t_node **head_stack_b);
void	rrb(t_node **head_stack_a, t_node **head_stack_b);
void	rrr(t_node **head_stack_a, t_node **head_stack_b);
void	pb(t_node **head_stack_a, t_node **head_stack_b);
void	pa(t_node **head_stack_a, t_node **head_stack_b);
int		check_doublon_list(t_node *head);
int		check_ony_number(char *str);
int		check_empty_stack(char *str);
int		*create_tab_nbr(char **str);
int		nbr_tab(char **str);
void	tri_tab(int nbr, int *tab);
void	check_data_in_stack(t_node **head, int nb, int i);
void	add_index_to_stack(t_node **head, int *tab, int max);
int		has_to_tri(t_node **head);
void	ft_tri(t_node **head_stack_a, t_node **head_stack_b, int nbr);
int		which_three_index_is_max(t_node **head_stack_a);
void	ft_tri_three(t_node **head_stack_a);
void	have_to_do_sa(t_node **head_stack_a);
int		is_stack_empty(t_node **head_stack_a);
int		nbr_element_in_stack(t_node *head);
void	ft_tri_more_than_three(t_node **head_stack_a, t_node **head_stack_b, int nbr);
void	send_element_to_b_unless_three(t_node **head_stack_a, t_node **head_stack_b, int mediane);
int 	is_index_smaller_than_mediane(t_node **head_stack_a, int mediane);
void ft_calculate_pos(t_node **head_stack_a, t_node **head_stack_b);
void ft_calculate_target_pos(t_node **head_stack_a, t_node **head_stack_b);
void ft_calculate_positions(t_node **head_stack_a, t_node **head_stack_b);
void	add_beg_pb(t_node **head_stack_a, t_node **head_stack_b);
void	add_beg_pa(t_node **head_stack_a, t_node **head_stack_b);
void first_passage(t_node *ptr_a, t_node *ptr_b, t_calculate *cal);
void b_index_not_greater(t_node *ptr_a, t_node *ptr_b, t_calculate *cal);
void ft_calculate_cost(t_node **head_stack_a, t_node **head_stack_b);
void ft_pile_b_calculate(t_node *ptr);
void ft_pile_a_calculate(t_node *ptr_a, t_node *ptr_b);
void ft_final_cost_calculate(t_node *ptr_b);
#endif