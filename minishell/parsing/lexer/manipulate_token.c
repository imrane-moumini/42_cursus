/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:23:13 by imrane            #+#    #+#             */
/*   Updated: 2023/02/27 21:40:51 by imrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	add_to_buf(char c, t_info_tok *info)
{
	char *tmp;
	
	if (info -> tok_bufindex >= info -> tok_bufsize)
	{
		tmp = ft_calloc((info -> tok_bufsize *2), sizeof(char));
		if (!tmp)
			return ;
		ft_strlcpy(tmp, info -> tok_buf, ft_strlen(info -> tok_buf));
		free(info -> tok_buf);
		info -> tok_buf = tmp;
		info -> tok_bufsize = info -> tok_bufsize * 2;
	}
	info -> tok_buf[info -> tok_bufindex] = c;
}

void	free_token(t_token *tok)
{
	if (tok)
	{
		if(tok->text)
        	free(tok->text);
    	free(tok);
		tok = NULL;
	}
}

t_token	*tokenize(t_source *src, t_info_tok *info)
{
	char c;
	t_token *tok;

	if (src -> end_input == 1)
		src -> exit = 1;
	tok = NULL;
	if(!src || !src->buffer || !src->bufsize)
        return NULL;
	if (!(info -> tok_buf))
	{
		info -> tok_bufsize = 1024;
		info -> tok_buf = ft_calloc(info -> tok_bufsize, sizeof(char));
		if (!(info -> tok_buf))
			return NULL;
	}
    info -> tok_buf[0] = '\0';
	c = src -> buffer[src -> curpos];
	while (c)
	{
		if (c == ' ' || c == '\t' || c == '\n')
		{
			if (info -> tok_bufindex != -1)
			{
				info -> tok_bufindex++;
				info -> tok_buf[info -> tok_bufindex] = '\0';
				src -> curpos++;
				break;	
			}
		}
		else
		{
			info -> tok_bufindex++;
			add_to_buf(c, info);
		}
		src -> curpos++;
		c = src -> buffer[src -> curpos];
	}
	if (c == '\0' || c == '\n')
	{
		info -> tok_bufindex++;
		info -> tok_buf[info -> tok_bufindex] = '\0';
		src -> end_input = 1;
	}
	tok = create_token(info -> tok_buf, src, info);
	info -> tok_bufindex = -1;
	return tok;
}

t_token *create_token(char *str, t_source *src, t_info_tok *info)
{
	t_token *tok;
	tok = malloc(sizeof(t_token));
	if (!tok)
		return NULL;
	tok->text_len = ft_strlen(str);
	tok->src = src;
	tok->text = malloc(sizeof(char) * ((tok -> text_len) + 1));
	ft_strlcpy(tok->text, info -> tok_buf, tok->text_len + 1);
	return (tok);
}

