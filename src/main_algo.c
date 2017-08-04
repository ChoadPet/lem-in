/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 19:44:09 by vpoltave          #+#    #+#             */
/*   Updated: 2017/07/23 19:44:40 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room	*make_start(t_room *room, t_skrr *skrr)
{
	t_room *tmp;

	tmp = room;
	while (tmp)
	{
		if (!(ft_strcmp(skrr->start_name, tmp->name)))
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}

int		bfs(t_skrr *skrr, t_room *room)
{
	int		queue[skrr->vertex];
	t_room	*head;
	t_room	*tmp;
	int		d;

	head = room;
	tmp = make_start(room, skrr);
	d = -1;
	skrr->i = 1;
	while (++d < skrr->vertex)
	{
		(skrr->i == 1) ? tmp->metka = 0 : 0;
		(skrr->i != 1) ? tmp = get_room(head, queue[d]) : 0;
		if (tmp == NULL)
			return (0);
		queue[d] = (skrr->i == 1) ? (tmp->index) : 0;
		skrr->n = tmp->metka;
		if (fck_neighbors(tmp->neighbors, skrr, queue))
			return (1);
	}
	return (0);
}

int		fck_neighbors(t_neighbors *neighbors, t_skrr *skrr, int *queue)
{
	t_neighbors *tmp;

	tmp = neighbors;
	while (tmp)
	{
		if (tmp->neighb->metka == -1)
		{
			queue[skrr->i++] = tmp->neighb->index;
			tmp->neighb->metka = skrr->n + 1;
		}
		if (!(ft_strcmp(tmp->neighb->name, skrr->end_name)) &&
				tmp->neighb->metka != -1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_room	*get_room(t_room *head, int d)
{
	t_room *tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->index == d)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
