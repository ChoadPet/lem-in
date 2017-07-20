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

int 	make_start(t_room **room, t_skrr *skrr)
{
	while (*room)
	{
		if (!(ft_strcmp(skrr->start_name, (*room)->name)))
			return (((*room)->metka = 0) ? 0 : 1);
		*room = (*room)->next;
	}
	return (0);
}

int 	get_my_path(t_skrr *skrr, t_room *room)
{
	t_room *head;

	head = room;
	while (ft_strcmp(room->name, skrr->end_name))
		room = room->next;
	while ((ft_strcmp(head->name, skrr->start_name)))
	{
		// TODO inside this while i should create path list. Check wiki for more info
		head = head->next;
	}
	return (0);
}

int		bfs(t_skrr *skrr, t_room *room)
{
	int 	queue[skrr->vertex];
	t_room	*head;
	int 	i;
	int 	d;

	head = room;
	if (!make_start(&room, skrr))
		return (0);
	d = 0;
	i = 1;
	while (d < skrr->vertex)
	{
		queue[d] = (i == 1) ? (room->index) : (get_index(head, queue[d]));
		room = get_room(head, d);
		while (room->neighbors)
		{
			if (room->neighbors->neighb->metka == -1)
			{
				queue[i] = room->neighbors->neighb->index;
				room->neighbors->neighb->metka = d + 1;
				i++;
			}
			if (!(ft_strcmp(room->neighbors->neighb->name, skrr->end_name)) &&
					room->neighbors->neighb->metka != -1)
				return (1);
			room->neighbors = room->neighbors->next;
		}
		d++;
	}
	return (0);
}

t_room	*get_room(t_room *head, int d)
{
	while (head)
	{
		if (head->index == d)
			return (head);
		head = head->next;
	}
	return (NULL);
}

int 	get_index(t_room *room, int d)
{
	while (room)
	{
		if (room->index == d)
		{
			d = room->index;
			return (d);
		}
		room = room->next;
	}
	return (0);
}
