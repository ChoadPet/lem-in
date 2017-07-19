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
	if ((!(ft_strcmp("##start", *line))) || !(ft_strcmp("##end", *line)) ||
			(ft_strchr(*line, '-') || (**line == '\0')))
		return (0);
	if (**line == '#')
		return (1);
	skrr->ants = ft_atoi(*line);
	if ((skrr->ants < 0) || (skrr->ants > 2147483647))
		return (0);
	skrr->flag_an = 0;
	return (1);
}

int 	room_info(t_skrr *skrr, t_room **room, char **line)
{
	if (skrr->found_links && **line != '#')
		return (0);
	if (!(ft_strcmp("##start", *line)))
		if (!what_is_next(skrr, line, 1))
			return (0);
	if (!(ft_strcmp("##end", *line)))
		if (!what_is_next(skrr, line, 0))
			return (0);
	if (**line == '#' || *(*line + 1) == '#')
		return (1);
	if (!two_spaces_start(skrr, *line))
		return (0);
	if ((skrr->start == 1 && !(skrr->for_start)) && (skrr->for_start = 1))
		skrr->start_name = get_name(*line, ' ');
	if ((skrr->end == 1 && !(skrr->for_end)) && (skrr->for_end = 1))
		skrr->end_name = get_name(*line, ' ');
	if (**line != '#')
		if (!push_room(room, line, ' '))
			return (0);
	return (1);
}

int 	link_info(t_skrr *skrr, t_room **room, char **line, t_link **link)
{
	if ((**line == '#' && *(*line + 1) == '#') || (**line == '#'))
		return (1);
	if ((!skrr->for_start || !skrr->for_end))
		return (0);
	if (skrr->found_rooms)
		return (0);
	if (!should_i(skrr, *room, *line))
		return (0);
	if (**line != '#')
		if (!push_link(link, line, '-'))
			return (0);
	if (!get_neighbor(skrr, *room, *link)) // TODO this func have to create pointer in current room to his neighbors
		return (0);
	return (1);
}

int		push_room(t_room **head, char **line, char c)
{
	t_room *new_room;

	if (!(new_room = (t_room *)malloc(sizeof(t_room))))
		return (0);
	if (!rooms_comp(*head, *line))
		return (0);
	new_room->name = get_name(*line, c);
	new_room->x_coord = x_y_coord(*line, 1);
	new_room->y_coord = x_y_coord(*line, 0);
	new_room->neighbors = NULL;
	new_room->next = *head;
	*head = new_room;
	return (1);
}

int		push_link(t_link **link, char **line, char c)
{
	t_link *new_link;

	if (!(new_link = (t_link *)malloc(sizeof(t_link))))
		return (0);
	new_link->name1 = get_name(*line, c);
	new_link->name2 = get_link(*line);
	new_link->next = *link;
	*link = new_link;
	return (1);
}
