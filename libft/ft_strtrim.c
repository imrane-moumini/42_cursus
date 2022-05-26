/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:38:33 by imoumini          #+#    #+#             */
/*   Updated: 2022/05/26 18:38:37 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>
int is_in_set(char a, char const  *set)
{
    int i;
    i = 0;
    while (set[i] != '\0')
    {
        if (a == set[i])
        {
            return (1);
        }
        i++;
    }
    return (0);
}
char    *ft_strtrim(char const *s1, char const *set)
{
    int     i;
    char    *p;
    int     lenght;

    i = 0;
    lenght = ft_strlen(s1);
    p = malloc(sizeof(char)*lenght + 1);
    if (p == NULL)
        return (NULL);
    while (s1[i] != '\0')
    {
        p[i] = set[i];
        if (is_in_set(p[i], set))
        {
            p[i] = 'x';
        }
        i++;
    }
    return (p);


}
int main(void)
{
    printf("%s", ft_strtrim("bob", "xox"));
}
