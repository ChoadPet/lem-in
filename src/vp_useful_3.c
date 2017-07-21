/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_ants.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 17:05:35 by vpoltave          #+#    #+#             */
/*   Updated: 2017/07/07 17:05:40 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int 	get_neighbor(t_skrr *skrr, t_room *room, t_link *link)
{
	skrr->tmp = room;
	while (room)
	{
		if (!ft_strcmp(room->name, link->name1) && (skrr->current = skrr->tmp))
		{
			while (skrr->current)
			{
				if (!(ft_strcmp(skrr->current->name, link->name2)))
				{
					if (second_neighbor(room->neighbors, skrr->current))
						return (1);
					if (!push_neighbor(&room->neighbors, skrr->current))
						return (0);
					if (!push_neighbor(&skrr->current->neighbors, room))
						return (0);
					return (1);
				}
				skrr->current = skrr->current->next;
			}
		}
		room = room->next;
	}
	return (1);
}

int 	push_neighbor(t_neighbors **neighbor, t_room *current)
{
	t_neighbors *new_elem;

	if (!(new_elem = (t_neighbors *)malloc(sizeof(t_neighbors))))
		return (0);
	new_elem->neighb = current;
	new_elem->next = *neighbor;
	*neighbor = new_elem;
	return (1);
}

int		second_neighbor(t_neighbors *neighbors, t_room *current)
{
	while (neighbors)
	{
		if (!(ft_strcmp(neighbors->neighb->name, current->name)))
			return (1);
		neighbors = neighbors->next;
	}
	return (0);
}

int 	print_nei(t_room *room)
{
	t_room 		*current;
	t_neighbors	*first;

	current = room;
	ft_printf("---------------------LINKS---------------------");
	while (current)
	{
		ft_printf("\n%s -> ", current->name);
		first = current->neighbors;
		while (first)
		{
			ft_printf("[%s]", first->neighb->name);
			first = first->next;
		}
		current = current->next;
	}
	return (1);
}