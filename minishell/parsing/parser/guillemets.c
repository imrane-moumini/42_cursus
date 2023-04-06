/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guillemets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:17:11 by imrane            #+#    #+#             */
/*   Updated: 2023/04/06 15:44:00 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int single_quote_closed(t_node *head)
{
	t_node *ptr;
    int count;
    
    count = 0;
    if (!head)
        return (2);
    ptr = head -> first_child;
    while (ptr)
    {
        if (ft_stcmp(ptr -> txt, "'") == 1)
            count++;
        ptr = ptr -> next_sibling;
    }
    if (count % 2 != 0)
    {
        ft_printf("error : single quote are not closed\n");
        return (0);
    }
    return (1);
}

int double_quote_closed(t_node *head)
{
	t_node *ptr;
    int count;
    
    count = 0;
    if (!head)
        return (2);
    ptr = head -> first_child;
    while (ptr)
    {
        if (ft_stcmp(ptr -> txt, "\"") == 1)
            count++;
        ptr = ptr -> next_sibling;
    }
    if (count % 2 != 0)
    {
        ft_printf("error : double quote are not closed\n");
        return (0);
    }
    return (1);
}
int quote_closed(t_node *head)
{
    if (single_quote_closed(head) == 0)
		return (0);
	if (double_quote_closed(head) == 0)
		return (0);
    return (1);
}



int is_there_quotes(t_node *root)
{
    t_node *ptr;
    
    if (!root)
        return (2);
    ptr = root -> first_child;
    while (ptr)
    {
        if (ft_stcmp(ptr -> txt, "\"") == 1 || ft_stcmp(ptr -> txt, "'") == 1)
            return (1);
        ptr = ptr -> next_sibling;
    }
    return (0);
}
int is_there_single_quotes(t_node *root)
{
    t_node *ptr;
    
    if (!root)
        return (2);
    ptr = root -> first_child;
    while (ptr)
    {
        if (ft_stcmp(ptr -> txt, "'") == 1)
            return (1);
        ptr = ptr -> next_sibling;
    }
    return (0);
}
int is_there_double_quotes(t_node *root)
{
    t_node *ptr;
    
    if (!root)
        return (2);
    ptr = root -> first_child;
    while (ptr)
    {
        if (ft_stcmp(ptr -> txt, "\"") == 1)
            return (1);
        ptr = ptr -> next_sibling;
    }
    return (0);
}
int is_there_both(t_node *root)
{
    t_node *ptr;
    int simple;
    int double_quotes;

    simple = 0;
    double_quotes = 0;
    if (!root)
        return (2);
    ptr = root -> first_child;
    while (ptr)
    {
        if (ft_stcmp(ptr -> txt, "\"") == 1)
            simple++;
        if (ft_stcmp(ptr -> txt, "'") == 1)
            double_quotes++;
        ptr = ptr -> next_sibling;
    }
    if (simple > 0 && double_quotes > 0)
        return (1);
    return (0);
}

