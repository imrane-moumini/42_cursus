/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:28:54 by imoumini          #+#    #+#             */
/*   Updated: 2022/05/27 19:28:58 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int number_of_tab(char const *s, char c)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
        {
            count++;
        }
        i++;
    }
    return (count);
} 

int size_of_a_tab(char const *s, char c)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (s[i] != '\0')
    {
        if (s[i] != c)
        {
            count++;
        }
        if (s[i] == c)
        {
            return(count);
        }
        i++;
    }
    return (count);
}
char    **ft_split(char const *s, char c)
{
    int i;
    
    i = 0;

}
int main(void)
{
    printf("%s", ft_split("je suis bg", ' '));
}
