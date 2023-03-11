#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <signal.h>
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
	int		end_input;
	int		exit;
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

/* structure of a node in first AST*/
typedef struct node_s
{
    char *txt;        /* value of this node */
    int    children;            /* number of child nodes */
    struct node_s *first_child; /* first child node */
    struct node_s *next_sibling;
	struct node_s *prev_sibling;
} t_node;

/*node of a command*/
typedef struct com_node
{
    char *txt;
    struct com_node *next_sibling;
} t_com;

/*node of a redirection*/
typedef struct redir_node
{
    char *txt;
    int heredoc;
    int in_file;
    int out_file;
    int append_file;
    int redir_file;
    struct com_node *next_sibling;
} t_redir;
/* structure of env linked list*/
typedef struct env_s
{
    char *txt;
    char* var_name;
    char *var_value;
	struct env_s *next;
} t_env;


/* manipulate the input*/
char	next_char(t_source *src); // return the next char et avance de 1 car dans linput (update pos)
void	unget_char(t_source *src); // recule de 1 car dans linput
char	peek_char(t_source *src); // return le next char sans update pos 
void	skip_white_spaces(t_source *src);
t_source	**init_src(t_source **src, char *input); // init input struct

/* manipulate the token*/
t_info_tok **init_global_info_token(t_info_tok **info);
t_token	*tokenize(t_source *src, t_info_tok *info);
int tokenize_space(char c, t_source *src, t_info_tok *info);
int tokenize_dollars(char c, t_source *src, t_info_tok *info);
int tokenize_pipe(char c, t_source *src, t_info_tok *info);
void tokenize_end(char c, t_source *src, t_info_tok *info);
int tokenize_in_out(char c, t_source *src, t_info_tok *info);
int tokenize_single_quote(char c, t_source *src, t_info_tok *info);
int tokenize_double_quote(char c, t_source *src, t_info_tok *info);
void	free_token(t_token *tok);
void	add_to_buf(char c, t_info_tok *info);
t_token	*create_token(char *str , t_source *src, t_info_tok *info);

/* parsing*/
t_node *parse_simple_command(char *input, t_source **src, t_info_tok **info);
t_node	*new_node(t_token *tok);
t_node	*add_node_to_ast(t_node *root, t_node *node);
void    print_ast(t_node *node);

/*env*/
t_env   *copy_env(char *original[]);
t_env   *add_node_env(t_env *head);
t_env   *new_node_env(void);
void    print_env(t_env *head);
void    is_env_var(t_env *mini_env, t_node *root);
void    insert_input_env(t_env *head, t_node *root);
void    expand_env(t_env *head, t_node *root);
char    *ft_strcpy(char *str);
char    *ft_strcpy_env(char *str);
void    create_var_name(t_env *node);
void    create_var_value(t_env *node);
int		ft_stcmp(char *str1, char *str2);
char	*extract_name(char *str);
char	*extract_value(char *str);
t_env	*last_env_node(t_env *head);
t_node	*do_i_have_to_expand(t_node *root);
char	*return_matching_value(t_env *head, char *str);
void	cut_dollar_sign(char *str);
int     is_nbr(char c);
int is_here_doc(t_node *node);

/*signaux*/
void	ft_sigint(int sigint, siginfo_t *pid, void *idontknow);

/*builtin exit*/
void ft_exit(t_env **mini_env,t_node **root, t_source **src, t_info_tok **info);

/*free*/
void free_info_buf(t_info_tok *info);
void free_src(t_source **src);
void free_tok(t_token **tok);
void free_info(t_info_tok **info);
void free_ast(t_node **root);
void free_env(t_env **mini_env);
void ft_free(t_env **mini_env, t_node **root, t_source **src, t_info_tok **info);

/*in and out redirection*/
int ft_in_file_first_check(t_node *ptr);
int in_file_second_check(t_node *ptr);
int ft_in_file(t_node *head);

/*pipe*/
int ft_pipe_first_check(t_node *ptr);
int ft_pipe_check(t_node *head);
int how_much_pipe(t_node *root);
/*error*/
int error_pars(t_node *head);
int nbr_in_export(t_node *head);

/*guillemets*/
int single_quote_closed(t_node *head);
int quote_closed(t_node *head);
int double_quote_closed(t_node *head);
int is_there_quotes(t_node *root);
int is_there_single_quotes(t_node *root);
int is_there_double_quotes(t_node *root);
int is_there_both(t_node *root);

/*ast command*/
t_com **create_ast_command(t_node *root);

/*manipulate node command*/
t_com *create_com_node();
/*manipulate node redir*/
#endif

// je suis << bob 