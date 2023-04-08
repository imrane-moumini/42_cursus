/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_env9.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:45:52 by imoumini          #+#    #+#             */
/*   Updated: 2023/04/08 16:20:12 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"


void after_multiple_dollar_while(int nbr, int *i, int *save)
{
    		if (nbr % 2 == 0)
			{
				while (nbr)
				{
					*(i) = *(i) + 1;
					nbr--;
				}
				*(save) = *(i);
			}
			else
			{
				while (nbr > 1)
				{
					*(i) = *(i) + 1;
					nbr--;
				}
				*(save) = *(i);
			}
}
