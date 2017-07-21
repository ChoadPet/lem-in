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
	int 	index;

	head = room;
	while (ft_strcmp(room->name, skrr->end_name))
		room = room->next;
	index = room->index;
	while (ft_strcmp(room->name, skrr->start_name))
	{
		room = next_neighb(index, head);
		while (room->neighbors)
		{
			if (room->metka - 1 == room->neighbors->neighb->metka)
			{
				if (!(push_path(&path, room->neighbors)))
					return (0);
				ft_printf("path: [%s] -> ", path->name);
				index = room->neighbors->neighb->index;
			}
			room->neighbors = room->neighbors->next;
		}
		room = room->next;
	}
	return (0);
}

int		bfs(t_skrr *skrr, t_room *room)
{
	int 	queue[skrr->vertex];
	t_room	*head;
	int 	i;
	int 	d;
	int 	n;

	head = room;
	if (!make_start(&room, skrr))
		return (0);
	d = 0;
	i = 1;
	while (d < skrr->vertex)
	{
		queue[d] = (i == 1) ? (room->index) : (get_index(head, queue[d]));
		room = get_room(head, d);
		n = room->metka;
		while (room->neighbors)
		{
			if (room->neighbors->neighb->metka == -1)
			{
				queue[i] = room->neighbors->neighb->index;
				room->neighbors->neighb->metka = n + 1;
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
