/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:23:13 by imrane            #+#    #+#             */
/*   Updated: 2023/02/04 22:03:51 by imrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
void	add_to_buf(char c, t_info_tok *info)
{
	char *tmp;
	
	info -> tok_buf[info -> tok_bufindex] = c;
	info -> tok_bufindex++;
	if (info -> tok_bufindex >= info -> tok_bufsize)
	{
		tmp = malloc(sizeof(char) * (info -> tok_bufsize *2));
		if (!tmp)
			return ;
		ft_strlcpy(tmp, info -> tok_buf, info -> tok_bufsize);
		free(info -> tok_buf);
		info -> tok_buf = tmp;
		info -> tok_bufsize = info -> tok_bufsize * 2;
		
	}
}