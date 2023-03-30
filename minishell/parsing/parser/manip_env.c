/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:47:11 by imrane            #+#    #+#             */
/*   Updated: 2023/03/30 19:28:26 by imoumini         ###   ########.fr       */
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
	printf("c2.10.2.1\n");
	i = 0;
	if (!str1 || !str2)
		return (0);
	printf("c2.10.2.2\n");
	while (str1[i] != '\0')
	{
		printf("c2.10.2.3\n");
		if (str1[i] != str2[i])
			return (0);
		printf("c2.10.2.4\n");
		i++;
	}
	printf("c2.10.2.5\n");
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

void expand_job_multiple_dollar(t_node *ptr, int nbr)
{
	int i;
	char *str_nbr;
	char *save_before_dollar;
	char *save_after_dollar;
	char *new_str;
	
	i = 0;
	printf("c1.3.1\n");
	while (ptr -> txt[i] != '\0')
	{
		printf("c1.3.2\n");
		if (ptr ->txt[i] == '$')
		{
			printf("c1.3.3\n");
			save_before_dollar = before_dollar(ptr -> txt);
			printf("save_before_dollar is =>%s\n", save_before_dollar);
			printf("c1.3.4\n");
			str_nbr = add_nbr(nbr);
			printf("add_nbr is =>%s\n", str_nbr);
			printf("c1.3.5\n");
			save_after_dollar = after_multiple_dollar(ptr -> txt, nbr);
			printf("c1.3.6\n");
			printf("save_after_dollar is =>%s\n", save_after_dollar);
			new_str = ft_strjoin(save_before_dollar, str_nbr);
			printf("c1.3.7\n");
			printf("new_str is =>%s\n", new_str);
			new_str = ft_strjoin(new_str, save_after_dollar);
			printf("new_str is =>%s\n", new_str);
			printf("c1.3.8\n");
			free(ptr -> txt);
			ptr -> txt = new_str;
			return ;
		}
		i++;
	}
}

void expand_job(t_env *head, t_node *ptr)
{
	int i;
	char *save_var;
	char *save_before_dollar;
	char *save_after_dollar;
	char *new_str;
	
	i = 0;
	save_after_dollar = malloc(sizeof(char) * 2);
	save_after_dollar[0] = 'a';
	save_after_dollar[1] = '\0';
	while (ptr -> txt[i] != '\0')
	{
		if (ptr ->txt[i] == '$')
		{
			i++;
			free(save_after_dollar);
			save_before_dollar = before_dollar(ptr -> txt);
			save_var = catch_var(ptr->txt + i);
			save_after_dollar = after_dollar(ptr -> txt);
			new_str = ft_strjoin(save_before_dollar, return_matching_value(head, save_var));
			if (save_after_dollar)
				new_str = ft_strjoin(new_str, save_after_dollar);
			free(ptr -> txt);
			ptr -> txt = new_str;
			i--;
		}
		i++;
	}
}
int more_than_one_dollars_suite(t_node *ptr)
{
	int i;
	i = 0;
	printf("c1.2.1\n");
	while(ptr -> txt[i])
	{
		printf("c1.2.2\n");
		if(ptr->txt[i] == '$')
		{
			printf("c1.2.3\n");
			if (ptr->txt[i + 1])
			{
				printf("c1.2.4\n");
				if (ptr->txt[i+1] == '$')
					return (1);
			}
			printf("c1.2.5\n");
		}
		printf("c1.2.6\n");
		i++;
	}
	printf("c1.2.7\n");
	return (0);
}

// dis toi si ya plusieur daffiler tu fais comme ca
//si yen a tu le fais
// ou sinon je gere plusieurs puis jme dit ok je regarde si il reste des dollar
// si il reste je fais le truc de dabitude
// en fait il faut que je boucle jusquq sil y ait plus de dollar dans la string
char *after_multiple_dollar(char *str, int nbr)
{
	int i;
	int save;
	int count;
	char *after;
	// si en gros faut je coupe meme le dernier dollar si c pair
		// si c impair je laisse le dernier dollar pour faire lexpand
	count = 0;
	i =0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] && str[i + 1] == '$')
		{
			if (nbr % 2 == 0)
			{
				while (nbr)
				{
					i++;
					nbr--;
				}
				save = i;
			}
			else
			{
				while (nbr > 1)
				{
					i++;
					nbr--;
				}
				save = i;
			}
			break;
		}
		i++;
	}
	// la je suis pile a lendroit ou il faut que je decoupe, a lindex exact
	while (str[i] != '\0')
		i++;
	count = i -save;
	after = malloc(sizeof(char) * (count + 1));
	i =0;
	while (str[save] != '\0')
	{
		after[i] = str[save]; 
		i++;
		save++;
	}
	after[i] = '\0';
	return (after);
}
// apres tester aaa$$$$USER$USERnan
char *add_nbr(int nbr)
{
	char *str_nbr;
	int count;

	count = 2;
	
	//ca fonctionne bien il me manque juste le ^ dollars qui devient 3 chiffre
	while (nbr > 1)
	{
		if (count == 2)
		{
			str_nbr = malloc(sizeof(char) * 8);
			str_nbr[0] = '3';
			str_nbr[1] = '1';
			str_nbr[2] = '0';
			str_nbr[3] = '5';
			str_nbr[4] = '1';
			str_nbr[5] = '6';
			str_nbr[6] = '0';
			str_nbr[7] = '\0';
			count--;
			if (nbr == 2)
				return (str_nbr);
		}
		if (count == 0)
			str_nbr = ft_strjoin(str_nbr, str_nbr);
		if (count >= 0)
			count--;
		if (nbr > 0)
			nbr = nbr/2;
	}
	return (str_nbr);
}
int nbr_of_dollar_suite(t_node *ptr)
{
	int i;
	int count;
	i = 0;
	count = 0;

	while (ptr->txt[i] != '\0')
	{
		while (ptr->txt[i] == '$')
		{
			count++;
			i++;
			if (ptr->txt[i] != '$')
				return (count);
		}
		i++;
	}
	return (count);
}


void    expand_env(t_env *head, t_node *root)

{
	t_node *ptr;
	t_node *expand;

	if (!head || !root)
		return ;
	ptr = root -> first_child;
	//if (is_here_doc(root) == 1)
	//	return ;
	while (ptr)
	{
		printf("c1.1\n");
		expand = do_i_have_to_expand(ptr);
		printf("c1.2\n");
		//if (/*txt is juste un dollar sans rien apres on expand pas*/)
		while (more_than_one_dollars_suite(ptr) == 1)
		{
			printf("c1.3\n");
			expand_job_multiple_dollar(ptr, nbr_of_dollar_suite(ptr));
			printf("c1.4\n");
		}
		// la normalement il en reste 1 ou 0
		expand = do_i_have_to_expand(ptr);
		printf("c1.5\n");
		if (expand)
			expand_job(head, ptr);
		printf("c1.6\n");
		ptr = ptr -> next_sibling;
		printf("c1.7\n");
	}
}