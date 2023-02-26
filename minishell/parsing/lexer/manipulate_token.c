/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:23:13 by imrane            #+#    #+#             */
/*   Updated: 2023/02/26 18:14:12 by imrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	add_to_buf(char c, t_info_tok *info)
{
	char *tmp;
	
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
	printf("buff is in tokenize before loop =>%s\n", src -> buffer);
	printf("curpos in tokenize before loop =>%li\n", src -> curpos);
	//printf ("c3.5.1\n");
	if (src -> end_input == 1)
		src -> exit = 1;
	//printf ("c3.5.2\n");
	tok = NULL;
	//printf ("c3.5.3\n");
	if(!src || !src->buffer || !src->bufsize)
        return NULL;
	//printf ("c3.5.4\n");
	if (!(info -> tok_buf))
	{
		//printf ("c3.5.5\n");
		info -> tok_bufsize = 1024;
		//printf ("c3.5.6\n");
		info -> tok_buf = malloc(info -> tok_bufsize);
		//printf ("c3.5.7\n");
		if (!(info -> tok_buf))
			return NULL;
		//printf ("c3.5.8\n");
	}
    info -> tok_buf[0] = '\0';
	//printf ("c3.5.9\n");
	//printf("buffer is =>%s\n",src -> buffer);
	//printf("curpos is =>%li\n", src -> curpos);
	//printf("c with curpos is =>%c\n", src -> buffer[src -> curpos]);
	c = src -> buffer[src -> curpos];
	printf("buff is in tokenize before loop c=>%s\n", src -> buffer);
	printf("curpos in tokenize before loop c =>%li\n", src -> curpos);

	//printf ("c3.5.10\n");
	while (c)
	{
		//printf("c is =>%c\n", c);
		//printf ("c3.5.11\n");
		printf("buff is in tokenize in loop =>%s\n", src -> buffer);
		printf("curpos in tokenize in loop =>%li\n", src -> curpos);
		printf("c before if is =>%c\n", c);
		if (c == ' ' || c == '\t' || c == '\n')
		{
			printf ("c3.5.12\n");
			if (info -> tok_bufindex != -1)
			{
				printf ("c3.5.13\n");
				info -> tok_bufindex++;
				printf ("c3.5.14\n");
				info -> tok_buf[info -> tok_bufindex] = '\0';
				src -> curpos++;
				printf ("c3.5.15\n");
				break;	
			}
		}
		else
		{
			printf ("c3.5.16\n");
			info -> tok_bufindex++;
			printf ("c3.5.17\n");
			add_to_buf(c, info);
			printf ("c3.5.18\n");
		}
		src -> curpos++;
		printf ("c3.5.19\n");
		c = src -> buffer[src -> curpos];
		printf ("c3.5.20\n");
	}
	if (c == '\0' || c == '\n')
	{
		printf ("c3.5.21\n");
		info -> tok_bufindex++;
		printf ("c3.5.22\n");
		info -> tok_buf[info -> tok_bufindex] = '\0';
		printf ("c3.5.23\n");
		src -> end_input = 1;
		printf ("c3.5.24\n");
	}
	tok = create_token(info -> tok_buf, src, info);
	printf("buff is in tokenize in loop after create=>%s\n", src -> buffer);
	printf("curpos in tokenize in loop after create=>%li\n", src -> curpos);
	// tema pk le chiffre change 
	// tema pk src plus le droit
	//exit (1);
	//printf ("c3.5.25\n");
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

