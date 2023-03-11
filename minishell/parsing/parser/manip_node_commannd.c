/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_node_commannd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:18:31 by imrane            #+#    #+#             */
/*   Updated: 2023/03/11 22:27:30 by imrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_com *create_com_node()
{
	t_com *ptr;
	ptr = malloc(sizeof(t_com));
	ptr -> txt = NULL;
	ptr -> next_sibling = NULL;
}