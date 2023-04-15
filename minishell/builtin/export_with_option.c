/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_with_option.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:16:25 by imoumini          #+#    #+#             */
/*   Updated: 2023/04/15 15:37:59 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int     is_env_var(t_env *mini_env, t_node *root)
{
	t_node *ptr;
	int nbr;
	if (!root)
		return (1);
	nbr =  how_much_pipe(root);
	printf("nbr of pipe is %i\n", nbr);
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
	// faut que le retour de ske g pas le droit je le recois la comme ca je vais pas dans
	// la suite
	return (1);
}

int count_nbr_equal(char *str, char *env_input)
{
	int i;
	int count;
	
	printf("%s\n", env_input);
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
		ft_printf("export : '%s' is not a valid identifier\n", env_input);
		return (1);
	}
	return (0);
}
int pars_env_name(char *str, char *env_input)
{
	int i;
	i = 0;
	if (!str)
		return (1);
	if (!env_input)
		return (1);
	if (is_nbr(str[0]) == 1)
	{
		ft_printf("export : '%s' is not a valid identifier\n", env_input);
		return (1);
	}
	
	if (str[0] == '=')
	{
		if (str[1] == '\0')
		{
			ft_printf("export : '%s' is not a valid identifier\n", env_input);
			return (1);
		}
	}
	
	if (str[0] == '"')
	{
		if (str[1])
		{
			if (str[1] == '"')
			{
				if (str[2] == '\0')
				{
					ft_printf("export : '%s' is not a valid identifier\n", env_input);
					return (1);
				}
			}
		}
	}
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '@' || str[i] == '+' || str[i] == '\\' || str[i] == '(' || str[i] == ')')
		{
			ft_printf("export : '%s' is not a valid identifier\n", env_input);
			return (1);
		}
		if (str[i] == '*' || str[i] == '{' || str[i] == '}' || str[i] == '-' )
		{
			ft_printf("export : '%s' is not a valid identifier\n", env_input);
			return (1);
		}	
		if (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z') && !(str[i] >= '0' && str[i] <= '9') && !(str[i] == '\"') && !(str[i] == '\''))
		{
			ft_printf("export : '%s' is not a valid identifier\n", env_input);
			return (1);
		}	
		i++;
	}
	return (0);
}

int pars_env_value(char *str, char *env_input)
{
	int i;
	i = 0;

	if (!str)
		return (0);
	if (!env_input)
		return (1);
	while (str[i])
	{
		if ( str[i] == '\\')
		{
			ft_printf("export : '%s' is not a valid identifier\n", env_input);
			return (1);
		}
		i++;
	}
	return (0);
}