/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:50:27 by imrane            #+#    #+#             */
/*   Updated: 2023/03/09 21:32:10 by imrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int error_pars(t_node *head)
{
    if (!head)
    {
		return(2);
	}
    if (ft_in_file(head) == 0)
    {
		return(0);
	}
	if (ft_pipe_check(head) == 0)
    {
		return(0);
	}
    return (1);
}