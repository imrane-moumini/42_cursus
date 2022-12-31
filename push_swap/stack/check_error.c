/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:01:34 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/31 16:52:45 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_ony_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			if(str[i] != '-' && str[i] != '+')
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_empty_stack(char *str)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			counter++;
		i++;
	}
	if (counter == 0)
		return (1);
	return (0);
}

int	boucle_check_doublon_list(t_node *head, t_node *ptr_data, t_node *adress)
{
	t_node	*ptr;
	t_node	*save_head;
	int		doublon;

	ptr = head;
	save_head = head;
	doublon = ptr_data -> data;
	while (ptr != NULL && ptr_data != NULL)
	{
		while (ptr != NULL)
		{
			if (doublon == ptr -> data && adress != ptr)
				return (1);
			ptr = ptr -> next;
		}
		ptr_data = ptr_data -> next;
		if (ptr_data != NULL)
		{
			doublon = ptr_data -> data;
			adress = ptr_data;
		}
		ptr = save_head;
	}
	return (0);
}

int	check_doublon_list(t_node *head)
{
	t_node	*ptr;
	t_node	*ptr_data;
	t_node	*data_adress;

	ptr = head;
	ptr_data = head;
	data_adress = ptr_data;
	if (ptr == NULL)
		return (0);
	if (ptr -> next == NULL)
		return (0);
	if (boucle_check_doublon_list(head, ptr_data, data_adress) == 1)
		return (1);
	return (0);
}

long    ft_atoi_long(char *str)
{
    long    i;
    int     sign;
    long    nb;

    i = 0;
    sign = 1;
    nb = 0;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
    {
        i++;
    }
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = sign -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        nb = nb * 10 + str[i] - 48;
        i++;
    }
    return (sign * nb);
}

void    check_int_limit(char **argv)
{
    long    content;
    int        i;

    i = 1;
    while (argv[i])
    {
        content = ft_atoi_long(argv[i]);
        if (content < -2147483648 || content > 2147483647)
        {
			ft_printf("Error\n");
			exit(1);
		}
        i++;
    }
}