#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

// abstract the input of the user
typedef struct source_s
{   
    char *buffer;       /* the input text */
    long bufsize;       /* size of the input text */
    long  curpos;       /* absolute char position in source */
} t_source;
char next_char(t_source *src);
void unget_char(t_source *src);
char peek_char(t_source *src);
void skip_white_spaces(t_source *src);

#endif