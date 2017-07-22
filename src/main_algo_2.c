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


t_room	*next_neighb(int index, t_room *head)
{
	while (head)
	{
		if (head->index == index)
			return (head);
		head = head->next;
	}
	return (NULL);
}

int 	get_my_path(t_skrr *skrr, t_room *room, t_path *path)
{
	t_room 	*head;
	t_room 	*tmp;

	head = room;
	while (ft_strcmp(room->name, skrr->end_name))
		room = room->next;
	skrr->index = room->index;
	ft_printf("[%s]", room->name);
	while (ft_strcmp(room->name, skrr->start_name))
	{
		skrr->break_flag = 0;
		room = next_neighb(skrr->index, head);
		while (room->neighbors)
		{
			if (room->metka - 1 == room->neighbors->neighb->metka)
			{
				if (!(push_path(&path, room->neighbors)))
					return (0);
				ft_printf(" -> [%s] ", path->name);
				skrr->index = room->neighbors->neighb->index;
				skrr->break_flag = 1;
			}
			if (skrr->break_flag == 1)
				break ;
			room->neighbors = room->neighbors->next;
		}
	}
	return (0);
}

int 	push_path(t_path **path, t_neighbors *neighbors)
{
	t_path *new_path;

	if (!(new_path = (t_path *)malloc(sizeof(t_path))))
		return (0);
	new_path->name = neighbors->neighb->name;
	new_path->next = *path;
	*path = new_path;
	return (1);
}


