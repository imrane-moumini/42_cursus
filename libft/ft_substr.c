/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:14:48 by imoumini          #+#    #+#             */
/*   Updated: 2022/05/24 20:14:57 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>
#include <mcheck.h>
#include <string.h>

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char        *p;
    size_t      i;
    size_t      max_index;

    i = 0;
    p = malloc(sizeof(char)*len + 1);
    if (p == NULL)
    {
        return (NULL);
    }
    max_index = ft_strlen(s) - 1;
    while ((i < len) && (start <= max_index) && (s[start + i] != '\0') )
    {
        p[i] = s[start + i];
        i++;
    }
    p[i] = '\0';
    return ((p));

}
int main(void)
{
    	char * s = ft_substr("tripouille", 0, 42000);
    printf("%s",ft_substr("tripouille", 0, 42000));
    printf("%d",mcheck(s, strlen("tripouille") + 1));
}
