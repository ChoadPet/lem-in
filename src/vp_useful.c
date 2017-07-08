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

void	clear_func(t_skrr *skrr)
{
	skrr->flag_an = -1;
	skrr->start_room = 0;
	skrr->end_room = 0;
	skrr->found_end = 0;
	skrr->found_start = 0;
}

int 	oops_error()
{
	ft_putstr("ERROR\n");
	return (-1);
}


char 	*get_name(char **line)
{
	char	*name;
	size_t 	i;

	i = 0;
	while (*(line) && *line[i] != ' ')
		i++;
	name = ft_strnew(i);
	ft_strncpy(name, *line, i);
	return (name);
}

int 	x_y_coord(char **line, int is_x)
{
	int	x;
	int y;

	if (is_x)
	{
		while ((*line) && **line != ' ')
			(*line)++;
		x = ft_atoi(*line);
		return (x);
	}
	else
	{
		while (*(line))
			(*line)++;
		y = ft_atoi(*line);
		return (y);
	}
}

int 	two_spaces(char *line)
{
	int spaces;
	int wrong_name;

	wrong_name = 0;
	spaces = 0;
	while (*line)
	{
		if (*line == 'L' || *line == '#')
			wrong_name++;
		if (*line == ' ')
			spaces++;
		(line)++;
	}
	if (spaces == 2 && wrong_name == 0)
		return (1);
	else
		return (0);
}
