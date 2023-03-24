/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:47:11 by imrane            #+#    #+#             */
/*   Updated: 2023/03/24 18:02:51 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char    *ft_strcpy(char *str)
{
	int i;
	int length;
	char *ptr;
	
	if (!str)
		return (NULL);
	i = 0;
	length = ft_strlen(str);
	ptr = malloc((sizeof(char) *length) + 1);
	if (!ptr)
		return (NULL);
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
char    *ft_strcpy_env(char *str)
{
	int i;
	int length;
	char *ptr;
	
	if (!str)
		return (NULL);
	i = 0;
	length = ft_strlen(str);
	ptr = malloc((sizeof(char) *length) + 1);
	if (!ptr)
		return (NULL);
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

t_env	*new_node_env(void)
{
	t_env *node;
	
	node = malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	node -> next = NULL;
	node -> txt = NULL;
	node -> var_name = NULL;
	node -> var_value = NULL;
	return (node);
}
t_env   *add_node_env(t_env *head)
{
	t_env *ptr;
	if (!head)
		return (NULL);
	ptr = head;
	if (head -> next == NULL)
	{
		head -> next = new_node_env();
		return (head);
	}
	else
	{
		while (ptr -> next != NULL)
			ptr = ptr -> next;
		ptr -> next = new_node_env();
	}
	return (head);
}

void    create_var_value(t_env *node)
{
	int i;
	int equal;

	if (!node)
		return ;
	if (node -> txt == NULL)
		return ;
	equal = 0;
	while(node -> txt[equal] != '=')
		equal++;
	i = equal;
	while (node -> txt[i] != '\0')
		i++;
	node -> var_value = malloc((sizeof(char) *(i - equal)) + 1);
	if (node -> var_value == NULL)
		return ;
	i = 0;
	equal++;
	while(node -> txt[equal] != '\0')
	{
		node -> var_value[i] = node -> txt[equal];
		i++;
		equal++;
	}
	node ->var_value[i] = '\0';
}

void    create_var_name(t_env *node)
{
	int i;
	
	if (!node)
		return ;
	if (node -> txt == NULL)
		return ;
	i = 0;
	while(node -> txt[i] != '=')
		i++;
	node -> var_name = malloc((sizeof(char))*i + 1);
	if (node -> var_name == NULL)
		return ;
	i = 0;
	while(node -> txt[i] != '=')
	{
		node -> var_name[i] = node -> txt[i];
		i++;
	}
	node ->var_name[i] = '\0';
}

t_env   *copy_env(char *original[])
{
    int i;
	t_env *mini_env;
	t_env	*ptr;

	i = 0;
	if (!original || original[0] == NULL)
		return (NULL);
	mini_env = malloc(sizeof(t_env));
	if (mini_env == NULL)
		return (NULL);
	mini_env -> next = NULL;
	while (original[i])
		i++;
	while(i > 1)
	{
		mini_env = add_node_env(mini_env);
		i--;
	}
	i--;
	ptr = mini_env;
	while (original[i] && ptr != NULL)
	{
		ptr -> txt = ft_strcpy(original[i]);
		ptr = ptr -> next;
		i++;
	}
	ptr = mini_env;
	while(ptr != NULL)
	{
		create_var_name(ptr);
		create_var_value(ptr);
		ptr = ptr -> next;
	}
	return (mini_env);
}

void    print_env(t_env *head)
{
	t_env *ptr;
	if (!head)
		return ;
	ptr = head;
	while (ptr != NULL)
	{
		ft_printf("%s\n", ptr -> txt);
		//printf("var name :%s\n", ptr -> var_name);
		//printf("var value :%s\n", ptr -> var_value);
		ptr = ptr -> next;
	}
}
int		ft_stcmp(char *str1, char *str2)
{
	int i;

	i = 0;
	if (!str1 || !str2)
		return (0);
	while (str1[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

int     is_nbr(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
void     is_env_var(t_env *mini_env, t_node *root)
{
	t_node *ptr;
	if (!root)
		return ;
	ptr = root -> first_child;
	if (ptr)
	{
		if (ft_stcmp(ptr -> txt, "export") && (ptr -> next_sibling != NULL))
			insert_input_env(mini_env, root);
		ptr = ptr -> next_sibling;
	}
}
char	*extract_name(char *str)
{
	int i;
	char *ptr;
	
	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '=')
		i++;
	ptr = malloc((sizeof(char) *i) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i] != '=')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
char	*extract_value(char *str)
{
	int i;
	int equal;
	char *ptr;
	
	i = 0;
	equal = 0;
	if (!str)
		return (NULL);
	while (str[i] != '=')
		i++;
	equal = i;
	while(str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
		i++;
	ptr = malloc( (sizeof(char)) *(i - equal) + 1);
	if (!ptr)
		return (NULL);
	equal++;
	i = 0;
	while (str[equal] != '\0' && str[equal] != ' ' && str[equal] != '\t')
	{
		ptr[i] = str[equal];
		i++;
		equal++;
	}
	ptr[i] = '\0';
	return (ptr);
}

t_env	*last_env_node(t_env *head)
{
	t_env *ptr;
	
	ptr = head;
	if (!ptr)
		return (NULL);
	while (ptr -> next != NULL)
		ptr = ptr -> next;
	return (ptr);
}
void    insert_input_env(t_env *head, t_node *root)
{
	char *var_env_name;
	char *var_env_value;
	char *env_input;
	t_env	*last_node;

	if (!head || !root)
		return ;
	if ((root -> first_child == NULL))
		return ;
	if ((root -> first_child -> next_sibling == NULL))
		return ;
	env_input = ft_strcpy_env(root -> first_child -> next_sibling -> txt);
	var_env_name = extract_name(root -> first_child -> next_sibling -> txt);
	var_env_value = extract_value(root -> first_child -> next_sibling -> txt);
	add_node_env(head);
	last_node = last_env_node(head);
	last_node -> var_name = var_env_name;
	last_node -> var_value = var_env_value;
	last_node -> txt = env_input;
}
t_node		*do_i_have_to_expand(t_node *node)
{
	t_node *ptr;
	int i;

	i = 0;
	// ok ici je dois changer la logique pour expand 
	// meme a linterieur dun mot
	// en gros la je recois token par token
	// je regarde si ya un dollars et je remplace
	// sauf que normalment si ya 2 fois dollars dans le même toke
	// je dois expand si ca correspond a un truc
	// si ca correspond a rien je renvoi du vide
	if (!node)
		return (NULL);
	ptr = node;
	if (ptr != NULL)
	{
		while (ptr -> txt[i] != '\0')
		{
			if (ptr -> txt[i] == '$')
				return (ptr);
			i++;
		}
	}
	return (NULL);
}
char	*return_matching_value(t_env *head, char *str)
{
	t_env *ptr;

	ptr = head;
	if (!ptr || !str)
		return (NULL);
	while (ptr != NULL)
	{
		if (ft_stcmp(str, ptr -> txt) == 1)
			return (ptr -> var_value);
		ptr = ptr -> next;
	}
	return (NULL);
}

void	cut_dollar_sign(char *str)
{
	int i;
	int length;

	i = 0;
	length = ft_strlen(str);
	while (str[i + 1])
	{
		str[i] = str[i + 1];
		i++;
	}
	length = length -1;
	str[length] = '\0';
}

char *catch_var(char *str)
{
	// je lui envoi un car apres le dollar
	// si ya rien apres le dollar je renvoi vide
	if (!str)
		return (NULL);
	int i;
	int length;
	char *var;
	
	length = 0;
	i = 0;
	while (str[length] != '\0' && str[length] != '$')
		length++;
	var = malloc(sizeof(char) * (length + 1));
	while(str[i] != '\0' && str[i] != '$')
	{
		var[i] = str[i];
		i++;
	}
	var[i] = '\0';
	return (var);
}

char *before_dollar(char *str)
{
	int i;
	int length;
	char *before;

	
	i = 0;
	length = 0;
	while (str[length] != '$')
		length++;
	before = malloc(sizeof(char) * (length + 1));
	
	while(str[i] != '$')
	{
		before[i] = str[i];
		i++;
	}
	before[i] = '\0';
	return (before);
}

char *after_dollar(char *str)
{
	int i;
	int j;
	int length;
	int save;
	char *after;

	
	i = 0;
	j = 0;
	length = 0;
	while (str[j] != '\0')
	{
		if (str[j] == '$')
			break;
		j++;
	}
	if (str[j] == '\0')
		return (NULL);
	j++;
	while (str[j] != '\0')
	{
		if (str[j] == '$')
			break;
		j++;
	}
	if (str[j] == '\0')
		return (NULL);
	save = j;
	while (str[j])
	{
		j++;
		length++;
	}
	after = malloc(sizeof(char) * (length + 1));
	
	while(str[save] != '\0')
	{
		after[i] = str[save];
		i++;
		save++;
	}
	after[i] = '\0';
	return (after);
}
void expand_job(t_env *head, t_node *ptr)
{
	int i;
	char *save_var;
	char *save_before_dollar;
	char *save_after_dollar;
	char *new_str;
	
	printf("c1.6.1\n");
	i = 0;
	save_after_dollar = malloc(sizeof(char) * 2);
	save_after_dollar[0] = 'a';
	save_after_dollar[1] = '\0';
	printf("c1.6.2\n");
	while (ptr -> txt[i] != '\0')
	{
		printf("c1.6.3\n");
		if (ptr ->txt[i] == '$')
		{
			printf("str is %s\n", ptr -> txt+i);
			i++;
			//while (save_after_dollar)
			//{
				// ok g une boucle inf pasque jajoute tjr la variable a la fin du coup il recommece sans cesse
				// c mon save after dollar qui est faux
				// en fait c le fait que jajouter $user a mon ter final qui fait ca
				printf("c1.6.4\n");
				free(save_after_dollar);
				save_before_dollar = before_dollar(ptr -> txt);
				printf("save before dollar is =>%s\n",save_before_dollar);
				printf("c1.6.5\n");
				save_var = catch_var(ptr->txt + i);
				printf("save var is =>%s\n",save_var);
				printf("c1.6.6\n");
				save_after_dollar = after_dollar(ptr -> txt);
				printf("save after dollar is =>%s\n",save_after_dollar);
				printf("c1.6.7\n");
				new_str = ft_strjoin(save_before_dollar, return_matching_value(head, save_var));
				printf("new str is =>%s\n", new_str);
				printf("c1.6.8\n");
				if (save_after_dollar)
					new_str = ft_strjoin(new_str, save_after_dollar);
				printf("c1.6.9\n");
				printf("new str is =>%s\n", new_str);
				free(ptr -> txt);
				ptr -> txt = new_str;
				printf("c1.6.10\n");
				printf("ptr is =>%s\n", ptr -> txt);
				i--;
			//}
		}
		i++;
	}
}

void    expand_env(t_env *head, t_node *root)
{
	t_node *ptr;
	t_node *expand;

	// ok ici je dois changer la logique pour expand 
	// meme a linterieur dun mot
	// la jenvoi token par token a do i have to expand
	// ensuite je coupe le dollar signe dans le token et rempalce
	// en fait c ici que je dois faire le rempalcement
	// en haut je regarde juste dans toute la sring si ya dollar signe
	printf("c1.1\n");
	if (!head || !root)
		return ;
	printf("c1.2\n");
	ptr = root -> first_child;
	printf("c1.3\n");
	if (is_here_doc(root) == 1)
		return ;
	printf("c1.4\n");
	while (ptr)
	{
		printf("c1.5\n");
		expand = do_i_have_to_expand(ptr);
		printf("c1.6\n");
		if (expand)
			expand_job(head, ptr);
		printf("c1.7\n");
		ptr = ptr -> next_sibling;
		printf("c1.8\n");
	}
}