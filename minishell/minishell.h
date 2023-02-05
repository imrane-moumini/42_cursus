#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"
// structure de l'input de l'user
typedef struct source_s
{   
    char	*buffer;       /* the input text */
    long	bufsize;       /* size of the input text */
    long	curpos;       /* index position in source */
} t_source;

// structure of a token
typedef struct token_s
{
    t_source	*src;       /* source of input */
    int			text_len;            /* length of token text */
    char		*text;             /* token text */
} t_token;

// structure d'information global pour créer un token
typedef struct info_tok_s
{
	char *tok_buf; /* pointer vers le buffer qui contient le token*/
	int   tok_bufsize; /*nbr of bytes of the token*/
	int   tok_bufindex; // l'index où on doit ajouter le prochain car dans le buff
} t_info_tok;
/* manipulate the input*/
char	next_char(t_source *src); // return the next char et avance de 1 car dans linput (update pos)
void	unget_char(t_source *src); // recule de 1 car dans linput
char	peek_char(t_source *src); // return le next char sans update pos 
void	skip_white_spaces(t_source *src);
void	init_src(t_source *src, char *input); // init input struct

/* manipulate the token*/
void init_global_info_token(t_info_tok *info);
t_token	*tokenize(t_source *src, t_info_tok *info);
void	free_token(t_token *tok);
void	add_to_buf(char c, t_info_tok *info);
t_token	*create_token(char *str , t_source *src, t_info_tok *info);

#endif