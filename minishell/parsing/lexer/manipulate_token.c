/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:23:13 by imrane            #+#    #+#             */
/*   Updated: 2023/04/09 18:18:33 by imoumini         ###   ########.fr       */
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
		init_buf_size(info);
    info -> tok_buf[0] = '\0';
	c = src -> buffer[src -> curpos];
	while (c)
	{
		printf("b1\n");
		printf("c is %c\n", c);
		if (tokenize_while(src, info, c)== 1)
		{
			printf("b2\n");
			//printf("JAVANCE\n");
			//src -> curpos++;
			break;
		}
		if (c != '"' && c != '\'')
		{
			printf("b3\n");
			printf("JAVANCE\n");
			src -> curpos++;
		}
		c = src -> buffer[src -> curpos];
		printf("b4\n");
	}
	if (c == '\0' || c == '\n')
	{
		printf("b5\n");
		tokenize_end(c, src, info);
	}
	if (is_just_tok_quotes(info -> tok_buf) == 1)
		tok = create_token(info -> tok_buf, src, info);
	printf("CREATE TOKEN\n");
	if (tok)
		printf("TOK is =>%s\n", tok ->text);
	printf("b6\n");
	info -> tok_bufindex = -1;
	printf("b7\n");
	return (tok);
}
// en fait le pb c que

t_token *create_token(char *str, t_source *src, t_info_tok *info)
{
	t_token *tok;
	if (info -> tok_bufindex == -1)
		return (NULL);
	tok = malloc(sizeof(t_token));
	if (!tok)
		return NULL;
	tok->text_len = ft_strlen(str);
	tok->src = src;
	tok->text = malloc(sizeof(char) * ((tok -> text_len) + 1));
	ft_strlcpy(tok->text, info -> tok_buf, tok->text_len + 1);
	return (tok);
}

