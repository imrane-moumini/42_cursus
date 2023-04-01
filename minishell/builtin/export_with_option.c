/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_with_option.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:16:25 by imoumini          #+#    #+#             */
/*   Updated: 2023/04/01 18:54:08 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// export avec option fonctionne que quqnd c la seulele command (je gere)


// dans insert input env je regarde si g le droit dajouter la var ou non
// je met aussi a jour la var si jamais elle existe deja
// genre je parcours si je la voir je remplace juste la valeur
// si je la vos pas je lajoute a la fin

// ensuite je reragde si ya un pipe si un pipe je fais rien
// je passe en argument de insert_inout_env si ya un pipe ou non
// comme ca il affiche message derreur mais ou fat ou fait pas 

// appeler juste apres pars simple command dans main
int     is_env_var(t_env *mini_env, t_node *root)
{
	t_node *ptr;
	int nbr;
	if (!root)
		return (1);
	nbr =  how_much_pipe(root);
	ptr = root -> first_child;
	
	if (ptr)
	{
		if (ft_stcmp(ptr -> txt, "export") && (ptr -> next_sibling != NULL))
		{
			if (insert_input_env(mini_env, ptr, nbr) == 0)
				return (0);
		}
		ptr = ptr -> next_sibling;
	}
	// faut que le retour de ske g pas le droit je le recois la comme ca je vais pas dans
	// la suite
	return (1);
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

	while (str[i])
	{
		// choisir les bons messages d'erreur
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
		if (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z') && !(str[i] >= '0' && str[i] <= '9'))
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