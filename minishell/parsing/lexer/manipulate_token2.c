/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_token2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:16:47 by imrane            #+#    #+#             */
/*   Updated: 2023/03/24 12:08:21 by imrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int tokenize_space(char c, t_source *src, t_info_tok *info)
{
	(void)c;
	if (info -> tok_bufindex != -1)
	{
		info -> tok_bufindex++;
		info -> tok_buf[info -> tok_bufindex] = '\0';
		src -> curpos++;
		return (1);	
	}
	return (0);
}

int tokenize_dollars(char c, t_source *src, t_info_tok *info)
{
	// je dois k'ajouter au buff come un caractère normal
	//du coup en vrai g juste a l'ignorer
	(void)src;
	if (info -> tok_bufindex != -1)
	{
		info -> tok_bufindex++;
		info -> tok_buf[info -> tok_bufindex] = '\0';
		return (1);	
	}
	else
	{
		info -> tok_bufindex++;
		add_to_buf(c, info);
	}
	return (0);
}

int tokenize_pipe(char c, t_source *src, t_info_tok *info)
{
	(void)c;
	if (info -> tok_bufindex != -1)
	{
		info -> tok_bufindex++;
		info -> tok_buf[info -> tok_bufindex] = '\0';
		return (1);	
	}
	else
	{
		info -> tok_bufindex++;
		add_to_buf(c, info);
		src -> curpos++;
		return (1);
	}
	return (0);
}
int tokenize_single_quote(char c, t_source *src, t_info_tok *info)
{
	(void)c;
	if (info -> tok_bufindex != -1)
	{
		info -> tok_bufindex++;
		info -> tok_buf[info -> tok_bufindex] = '\0';
		return (1);	
	}
	else
	{
		info -> tok_bufindex++;
		add_to_buf(c, info);
		src -> curpos++;
		return (1);
	}
	return (0);
}
int tokenize_double_quote(char c, t_source *src, t_info_tok *info)
{
	(void)c;
	if (info -> tok_bufindex != -1)
	{
		info -> tok_bufindex++;
		info -> tok_buf[info -> tok_bufindex] = '\0';
		return (1);	
	}
	else
	{
		info -> tok_bufindex++;
		add_to_buf(c, info);
		src -> curpos++;
		return (1);
	}
	return (0);
}
void tokenize_end(char c, t_source *src, t_info_tok *info)
{
	(void)c;
	if (info -> tok_bufindex != -1)
	{
		info -> tok_bufindex++;
		info -> tok_buf[info -> tok_bufindex] = '\0';
	}
	src -> end_input = 1;
}

int tokenize_in_out(char c, t_source *src, t_info_tok *info)
{
	(void)c;
	if (info -> tok_bufindex != -1)
	{
		info -> tok_bufindex++;
		info -> tok_buf[info -> tok_bufindex] = '\0';
		return (1);	
	}
	else
	{
		info -> tok_bufindex++;
		add_to_buf(c, info);
		src -> curpos++;
		return (1);
	}
	return (0);
}