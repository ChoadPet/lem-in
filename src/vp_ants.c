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

int 	fck_ants(t_skrr *skrr, char **line)
{
	if ((!(ft_strcmp("##start", *line))) || !(ft_strcmp("##end", *line)))
		return (0);
	if (**line == '#')
		return (1);
	skrr->ants = ft_atoi(*line);
	if (skrr->ants < 0)
		return (0);
	skrr->flag_an = 0;
	return (1);
}


int 	basic_info(t_skrr *skrr, t_room **head, char **line)
{
	if (**line == '#' && *(*line + 1) != '#')
		return (1);
	if (!(ft_strcmp("##start", *line)))
		if (!what_is_next(skrr, line, 1))
			return (0);
	if (!(ft_strcmp("##end", *line)))
		if (!what_is_next(skrr, line, 0))
			return (0);
	if (two_spaces(*line) && (!skrr->comment_s && !(skrr->comment_e)))
		return (0);
	else if (two_start(skrr) && (!skrr->comment_s && !(skrr->comment_e)))
		return (0);
	if ((skrr->start == 1 && !(skrr->for_start)) && (skrr->for_start = 1))
		push_to_beg(&skrr->start_room, line);
	else if ((skrr->end == 1 && !(skrr->for_end)) && (skrr->for_end = 1))
		push_to_beg(&skrr->end_room, line);
	else if (!skrr->comment_e || !(skrr->comment_s))
		push_to_beg(head, line);
	return (1);
}

int		push_to_beg(t_room **head, char **line)
{
	t_room *new_room;

	if (!(new_room = (t_room *)malloc(sizeof(t_room))))
		return (0);
	new_room->name = get_name(*line);
	new_room->x_coord = x_y_coord(*line, 1);
	new_room->y_coord = x_y_coord(*line, 0);
	new_room->next = *head;
	*head = new_room;
	return (1);
}


int 	push_to_end(char **line)
{
	t_info *new_room;
	t_info *current;

	if (!(new_room = (t_info *)malloc(sizeof(t_info))))
		return (0);
	new_room->info = ft_strdup(*line);
	new_room->next = NULL;
	if (g_info == NULL)
		g_info = new_room;
	else
	{
		current = g_info;
		while (current->next != NULL)
			current = current->next;
		current->next = new_room;
	}
	return (1);
}
