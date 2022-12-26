/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:14:20 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/26 17:45:30 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// etape 3
void ft_calculate_positions(t_node **head_stack_a, t_node **head_stack_b)
{
    ft_calculate_pos(head_stack_a, head_stack_b);
    ft_calculate_target_pos(head_stack_a, head_stack_b);
}

// etape 4
void ft_calculate_cost(t_node **head_stack_a, t_node **head_stack_b)
{
    // cout = nombre de coups pour mettre lelemt de la pile B vers le bon endroit de la A
    // 2 couts a calculer pour chaque element de la pile B : a l'aide de "rotate" et "reverse rotate"
        // nbr de cout pour metre lelement de la pile B au sommet de la pile B
        // nbr de cout pour deplacer lelement de la position cible de la pile A vers le sommet de la pile A

    // choisir entre rotate et reverse rotate ("ra", "rra", "rb", "rrb")
        // mesurer la taille de la pile et diviser par 2
            // si position est plus petit que la moitier (donc au dessus) faut faire des rb
            // si psotion plus grand que la moitier (donc en dessous) faut faire des rrb
    // il ny a pas de sa ss ou sb dans cet algo 

	// en gros pour chaque element tu vas calculer les 2 couts a l'aide des rotates et reverse rotate puis enregistrer les 2 coups
	// les coups sont unique a chaque element
	// le cout du reverse rotating doit etre negatif et celui du rotate positif
		// comme ca dans la suite dexecution on regardera le signe pour savoir si on rotate ou reverse rotate
		// si les signes des couts A et B sont les meme ont peut economiser des couts avec dess rr ou rrr
	// pour connaitre le cout total il suffit daditiioner la somme des nombres absolus et ca par pile
	// si deja sommet = 0
	// le cout total sera laddition des couts des 2 piles
	// ensuite tu regardes tous les couts toaux de la liste et fait les couts pour lelement avec le cout total le moins eleve 

	// comment savoir le nombre de ra ou de rra pour arriver au sommet ?
	// je sais choisir entre ra et rra mais je ne sais pas comment savoir cb il men faut
	// qund je choisi ra c ra juquau bout et quand je choisi rra c rra jusquau bout
	// pour connaitre le nbr de ra c taille de la stack- position de lelement
	// pour connaitre le nbr de rra c taille de la stack - position de lement + 1

	t_node *ptr_b;
	ptr_b = *head_stack_b;
	while (ptr_b != NULL)
	{
		ft_pile_b_calculate(head_stack_b,ptr_b);
		ft_pile_a_calculate(head_stack_a,ptr_b);
		ft_final_cost_calculate(ptr_b);
		ptr_b = ptr_b -> next;
	}
	
}
// comprendre pk  pas le bon cos alors que normalement g le bon calcul
// rra = lelemnt en ba de la pile au sommet
// ra = lelement au sommet de la pile en bas
void ft_pile_b_calculate(t_node **head_stack_b, t_node *ptr)
{
	int nbr;
	int lenght;
	
	nbr = nbr_element_in_stack(*head_stack_b)/2;
	lenght = nbr_element_in_stack(*head_stack_b);
	if (nbr % 2 == 1)
		nbr = nbr + 1;
	// choisir entre ra ou rra
		// ra est preferable a rra du coup je prefere le prendre en compte dans le egal
	// calculer
	if (ptr -> pos == 1)
	{
		ptr -> cost_b = 0;
		return ;
	}
	if (ptr -> pos <= nbr)
	{
		ptr -> cost_b = lenght - ptr -> pos;
	}
	if (ptr -> pos > nbr)
		ptr -> cost_b = ((lenght - ptr -> pos) + 1) * -1;
}

void ft_pile_a_calculate(t_node **head_stack_a,t_node *ptr_b)
{
	int nbr;
	int lenght;
	
	nbr = nbr_element_in_stack(*head_stack_a)/2;
	lenght = nbr_element_in_stack(*head_stack_a);
	if (nbr % 2 == 1)
		nbr = nbr + 1;
	// choisir entre ra ou rra
		// ra est preferable a rra du coup je prefere le prendre en compte dans le egal
	// calculer
	if (ptr_b -> target_pos == 1)
	{
		ptr_b -> cost_a = 0;
		return ;
	}
	if (ptr_b -> target_pos <= nbr)
		ptr_b -> cost_a = lenght - ptr_b -> target_pos;
	if (ptr_b -> target_pos > nbr)
		ptr_b -> cost_a = ((lenght - ptr_b -> target_pos) + 1) * -1;
}

void ft_final_cost_calculate(t_node *ptr_b)
{
	// cost_a + cost_b
	// cost_a peut etre negatif ou cots_b ou les 2
	if (ptr_b -> cost_b < 0 && ptr_b -> cost_a < 0)
	{
		ptr_b -> total_cost = ((ptr_b -> cost_b) * -1) + ((ptr_b -> cost_a) * -1);
		return ;
	}
	if (ptr_b -> cost_b < 0 || ptr_b -> cost_a < 0)
	{
		if (ptr_b -> cost_b < 0)
		{
			ptr_b -> total_cost = ((ptr_b -> cost_b) * -1) + ((ptr_b -> cost_a));
			return ;
		}
		else
		{
			ptr_b -> total_cost = ((ptr_b -> cost_b)) + ((ptr_b -> cost_a) * -1);
			return ;
		}
	}
	ptr_b -> total_cost = ((ptr_b -> cost_b)) + ((ptr_b -> cost_a));
}