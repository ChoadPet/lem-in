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

int 	push_to_end(char **line)
{
	t_info *new_room;
	t_info *current;

	if (**line == '#' && *(*line + 1) != '#')
		return (1);
	if (!(new_room = (t_info *)malloc(sizeof(t_info))))
		return (0);
	new_room->info = ft_strdup(*line);
	new_room->next = NULL;
	if (g_info == NULL)
		g_info = new_room;
	else
	{
		current = g_info;
		while (current->next)
			current = current->next;
		current->next = new_room;
	}
	return (1);
}

int 	should_i(t_skrr *skrr, t_room *room, char *line)
{
	char *n1;
	char *n2;

	if ((ft_strchr(line, ' ')) || (*line == 'L'))
		return (0);
	n1 = get_name(line, '-');
	while (*line != '-')
		(line)++;
	n2 = get_name((line + 1), 0);
	skrr->name_1 = 0;
	skrr->name_2 = 0;
	while (room)
	{
		(!(ft_strcmp(room->name, n1))) ? (skrr->name_1 = 1) : 0;
		(!(ft_strcmp(room->name, n2))) ? (skrr->name_2 = 1) : 0;
		room = room->next;
	}
	return ((skrr->name_1 && skrr->name_2) ? 1 : 0);
}

int 	found_links(t_skrr *skrr, char *line)
{
	if (!skrr->for_start || !skrr->for_end)
		return (0);
	skrr->found_links = 0;
	while (*line && *line != ' ')
	{
		(*line == '-') ? (skrr->found_links = 1) : 0;
		(line)++;
	}
	return (skrr->found_links ? 1 : 0);
}

int 	found_room(t_skrr *skrr, char *line)
{
	skrr->found_rooms = 0;
	if ((!ft_strcmp("##start", line) ||
			(!ft_strcmp("##end", line))) && (skrr->found_rooms = 1))
		return (1);
	while (*line && *line != '-')
	{
		(*line == ' ') ? (skrr->found_rooms = 1) : 0;
		(line)++;
	}
	return (skrr->found_rooms ? 1 : 0);
}
