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

/* structure of a node in AST*/
typedef struct node_s
{
    char *txt;        /* value of this node */
    int    children;            /* number of child nodes */
    struct node_s *first_child; /* first child node */
    struct node_s *next_sibling;
	struct node_s *prev_sibling;
} t_node;


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
t_token *parse_simple_command(t_token *tok);

/* parsing*/
t_node *parse_simple_command(char *input, t_source *src, t_info_tok *info);
t_node *new_node(void);
void	init_node(t_node *node, t_token *tok);
void	add_node(t_node *root, t_node *node);
#endif