/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_env11.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 18:20:50 by imoumini          #+#    #+#             */
/*   Updated: 2023/04/15 18:30:32 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void expand_guillemets_first(char *str, int *index_dol, int *nbr_simple, int *index_simple)
{
	while (*(index_dol) >= 0)
	{
		if (str[*(index_dol)] == '\'')
		{
			*(nbr_simple) = *(nbr_simple) + 1;
			*(index_simple) = *(index_dol);
		}
		*(index_dol) = *(index_dol) - 1;
	}
}