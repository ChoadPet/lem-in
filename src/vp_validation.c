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

int 	oops_error()
{
	ft_putstr("ERROR\n");
	return (0);
}

void 	exit_error()
{
	ft_putstr("ERROR\n");
	exit(0);
}

int 	two_spaces_start(t_skrr *skrr, char *line)
{
	int spaces;
	int wr_name;

	wr_name = 0;
	spaces = 0;
	if (skrr->start > 1 || skrr->end > 1)
		return (0);
	if (*line == '#')
		return (1);
	while (*line)
	{
		(line[0] == 'L' || line[0] == '#' || line[0] == '-') ? wr_name++ : 0;
		if (*line == ' ')
		{
			(*line == ' ' && (*(line + 1) == ' ')) ? wr_name++ : 0;
			while (*line)
			{
				(*line == ' ' && (line)++) ? spaces++ : 0;
				(!ft_isdigit(*line) && *line != '-') ? wr_name++ : 0;
				(*line) ? (line)++ : 0;
			}
		}
		(*line) ? line++ : 0;
	}
	return ((spaces == 2) && (wr_name == 0) ? 1 : 0);
}

int		what_is_next(t_skrr *skrr, char **line, int start)
{
	ft_strdel(line);
	(start) ? skrr->start++ : skrr->end++;
	if (get_next_line(g_fd, line) > 0)
	{
		if (!(ft_strcmp("##end", *line)) || !(ft_strcmp("##start", *line)))
			return (0);
	}
	else
		exit_error();
	if (!need_it(line))
		return (0);
	return (1);
}

int 	rooms_comp(t_room *room, char *line)
{
	char *tmp;

	tmp = get_name(line, ' ');
	while (room != NULL)
	{
		if (!ft_strcmp(room->name, tmp))
		{
			ft_strdel(&tmp);
			return (0);
		}
		if ((room->x_coord == x_y_coord(line, 1)) &&
				(room->y_coord == x_y_coord(line, 0)))
			return (0);
		room = room->next;
	}
	ft_strdel(&tmp);
	return (1);
}

int		second_main(char **line, t_skrr *skrr)
{
	if (!need_it(line))
		return (oops_error());
	if (skrr->flag_an == 0 && (found_room(skrr, *line)))
		if (!(room_info(skrr, &skrr->room, line)))
			return (oops_error());
	if (found_links(skrr, *line))
		if (!(link_info(skrr, &skrr->room, line, &skrr->link)))
			return (oops_error());
	if (skrr->flag_an == -1) // TODO need to find place, where to put main algo
		if (!(fck_ants(skrr, line)))
			return (oops_error());
	ft_strdel(line);
	return (1);
}