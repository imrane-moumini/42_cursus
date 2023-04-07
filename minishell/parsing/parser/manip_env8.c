/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_env8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:45:39 by imoumini          #+#    #+#             */
/*   Updated: 2023/04/07 17:06:23 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void fill_last_node(t_env *last_node, char *var_env_name, char *var_env_value, char *env_input)
{
    last_node -> var_name = var_env_name;
	last_node -> var_value = var_env_value;
	last_node -> txt = env_input;
}