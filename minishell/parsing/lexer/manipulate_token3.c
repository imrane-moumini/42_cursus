/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_token3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:42:55 by imoumini          #+#    #+#             */
/*   Updated: 2023/04/08 18:54:08 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
int tokenize_while(t_source *src, t_info_tok *info, char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
	{
		if (tokenize_space(c, src, info) == 1)
			return (1);
	}
	else if (c == '|')
	{
		if (tokenize_pipe(c, src, info) == 1)
			return (1);
	}
	else if (c == '<' || c == '>')
	{
		if (tokenize_in_out(c, src, info) == 1)
			return (1);	
	}
	else
	{
		info -> tok_bufindex++;
		add_to_buf(c, info);
	}
	return (0);
}

void init_buf_size(t_info_tok *info)
{
	info -> tok_bufsize = 1024;
	info -> tok_buf = ft_calloc(info -> tok_bufsize, sizeof(char));
}