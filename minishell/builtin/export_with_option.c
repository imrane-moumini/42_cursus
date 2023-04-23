/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_with_option.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:16:25 by imoumini          #+#    #+#             */
/*   Updated: 2023/04/23 15:48:05 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_exit_status;

int	is_env_var(t_env *mini_env, t_node *root)
{
	t_node	*ptr;
	int		nbr;

	if (!root)
		return (1);
	nbr = how_much_pipe(root);
	ptr = root -> first_child;
	if (ptr)
	{
		if (ft_stcmp(ptr -> txt, "export") && (ptr -> next != NULL))
		{
			if (insert_input_env(&mini_env, ptr, nbr) == 0)
				return (0);
		}
		ptr = ptr -> next;
	}
	return (1);
}

int	count_nbr_equal(char *str, char *env_input)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			count++;
		i++;
	}
	if (count == 0)
	{
		printf("c7\n");
		return (print_error_export(env_input), 1);
	}
	return (0);
}

int	pars_env_name(char *str, char *env_input)
{
	int	i;
	printf("str is :%s\n", str);
	i = 0;
	if (!str)
		return (1);
	if (!env_input)
		return (1);
	if (pars_env_name_nb_equ(str, env_input) == 1)
	{
		printf("c1\n");
		return (1);
	}
	if (pars_env_name_quote(str, env_input) == 1)
	{
		printf("c2\n");
		return (1);
	}
	while (str[i])
	{
		if (pars_env_name_f_if(str, env_input, i) == 1)
		{
			printf("c3\n");
			return (1);
		}
		if (pars_env_name_s_if(str, env_input, i) == 1)
		{
			printf("c4\n");
			return (1);
		}
		if (pars_env_name_t_if(str, env_input, i) == 1)
		{
			printf("c5\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	pars_env_value(char *str, char *env_input)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (!env_input)
		return (1);
	while (str[i])
	{
		if (str[i] == '\\')
		{
			printf("c6\n");
			return (print_error_export(env_input), 1);
		}
		i++;
	}
	return (0);
}
