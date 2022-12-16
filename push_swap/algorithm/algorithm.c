/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:11:27 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/16 19:40:13 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// trouver un moyen de mettre les bon idex tsa au debut
	// je le trie en tant que tableau, j'i le bon ordre
	// mais du coup faut compter cb ya de chiffre
	// creer un autre tab de chiffre avec le nombre delement
		// utiliser le tab de split
	// lindex du chiffre = lindex a donner dans la linked list
	// genre dans un prmier temps je rempli
	// puis je comparele chiffe et je dit si chiffre = bah index aussi
	// le haut de la stack doit etre le plus petit

int nbr_tab(char **str)
{
	int		i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int *create_tab_nbr(char **str)
{
	int		nbr;
	int		*tab;
	int		i;
	i = 0;
	nbr = nbr_tab(str);
	tab = malloc(sizeof(int) * nbr);
	while (str[i])
	{
		tab[i] = ft_atoi(str[i]);
		i++;
	}
	return (tab);
}

 void tri_tab(int nbr, int *tab)
 {
	int i;
	int save;
	
	i = 0;
	while (i < nbr)
	{
		if (i + 1 < nbr && tab[i] > tab[i + 1])
		{
			save = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = save; 
			i = 0;
		}
		else
			i++;
	}
 }

//  void add_index_to_stack(t_node **head, i)

// faire fonction qui attribue les index
// faire fonction qui regqrde si ya besoin de trier ou pas
// faire fonction qui conte le nbr delemen de la liste 

// 2 nb
	// sa
// 3 nb
	// 6 cas (3 actions : ra rra sa)
	// si 'l'index du premier nb est le plus grand => ra
	// si l'index du deuxieme nb est plus grand => rra
	// si l'index du premier nb > lindex du deuxieme nb => sa
// plu de 3 nb
	// calculer la liste daction la moins longue