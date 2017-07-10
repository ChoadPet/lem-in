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
	return (-1);
}

int 	two_spaces(char *line)
{
	int spaces;
	int wrong_name;

	wrong_name = 0;
	spaces = 0;
	while (*line)
	{
		if (line[0] == 'L' || line[0] == '#')
			wrong_name++;
		if (*line == ' ')
			spaces++;
		line++;
	}
	if (spaces == 2 && wrong_name == 0)
		return (0);
	else
		return (1);
}

int 	two_start(t_skrr *skrr)
{
	if (skrr->start > 1 || skrr->end > 1)
		return (1);
	else
		return (0);
}