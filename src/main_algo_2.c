/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 19:39:59 by vpoltave          #+#    #+#             */
/*   Updated: 2017/07/23 20:40:41 by vpoltave         ###   ########.fr       */
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

int		get_my_path(t_skrr *skrr, t_room *room, t_path **path)
{
	t_room *head;
	t_room *tmp;

	head = room;
	tmp = room;
	while (ft_strcmp(tmp->name, skrr->end_name))
		tmp = tmp->next;
	push_path(path, tmp->neighbors, tmp, skrr);
	skrr->index = tmp->index;
	while (ft_strcmp(tmp->name, skrr->start_name))
	{
		tmp = next_neighb(skrr->index, head);
		if (!(best_neighbors(path, skrr, tmp)))
			return (0);
	}
	print_lists(g_info);
	(skrr->ants > 0) ? ft_printf("\n") : 0;
	(skrr->ants > 0) ? ants(*path, skrr) : 0;
	return (1);
}

int		best_neighbors(t_path **path, t_skrr *skrr, t_room *tmp)
{
	t_neighbors *leaks;

	leaks = tmp->neighbors;
	while (leaks)
	{
		if (tmp->metka - 1 == leaks->neighb->metka)
		{
			if (!(push_path(path, leaks, NULL, skrr)))
				return (0);
			skrr->index = leaks->neighb->index;
			return (1);
		}
		leaks = leaks->next;
	}
	return (1);
}

int		push_path(t_path **path, t_neighbors *neighbors, t_room *tmp, \
				t_skrr *skrr)
{
	t_path *new_path;
	t_path *current;

	if (!(new_path = (t_path *)malloc(sizeof(t_path))))
		return (0);
	new_path->name = (tmp == NULL) ? (neighbors->neighb->name) : (tmp->name);
	new_path->ant_here = 0;
	new_path->ant_number = 0;
	new_path->all_ants = (int)skrr->ants;
	new_path->next = NULL;
	if (*path == NULL)
		*path = new_path;
	else
	{
		current = *path;
		while (current->next)
			current = current->next;
		current->next = new_path;
	}
	return (1);
}
