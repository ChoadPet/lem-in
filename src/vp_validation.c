/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 19:46:55 by vpoltave          #+#    #+#             */
/*   Updated: 2017/07/23 20:34:49 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		oops_error(void)
{
	ft_putstr("ERROR\n");
	return (0);
}

void	ex_error(void)
{
	ft_putstr("ERROR\n");
	exit(0);
}

int		two_spaces_start(t_skrr *skrr, char *line)
{
	skrr->wr_name = 0;
	skrr->spaces = 0;
	if (skrr->start > 1 || skrr->end > 1 || *line == ' ')
		return (0);
	if (*line == '#')
		return (1);
	while (*line)
	{
		(line[0] == 'L' || line[0] == '#' || line[0] == '-') ?
		skrr->wr_name++ : 0;
		if (*line == ' ')
		{
			(*line == ' ' && (*(line + 1) == ' ')) ? skrr->wr_name++ : 0;
			while (*line)
			{
				(*line == ' ' && (line)++) ? skrr->spaces++ : 0;
				(!ft_isdigit(*line) && *line != '-') ? skrr->wr_name++ : 0;
				(*line) ? (line)++ : 0;
			}
		}
		(*line) ? line++ : 0;
	}
	return ((skrr->spaces == 2) && (skrr->wr_name == 0) ? 1 : 0);
}

int		what_is_next(t_skrr *skrr, char **line, int start)
{
	ft_strdel(line);
	(start) ? skrr->start++ : skrr->end++;
	if (get_next_line(0, line) > 0)
	{
		if (!(ft_strcmp("##end", *line)) || !(ft_strcmp("##start", *line)))
			return (0);
	}
	else
		ex_error();
	if (!need_it(line))
		return (0);
	return (1);
}

int		rooms_comp(t_room *room, char *line)
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
