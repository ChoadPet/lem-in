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

void	init_func(t_skrr *skrr)
{
	skrr->flag_an = -1;
	skrr->start = 0;
	skrr->end = 0;
	skrr->for_start = 0;
	skrr->for_end = 0;
	skrr->found_rooms = 0;
	skrr->found_links = 0;
	skrr->name_1 = 0;
	skrr->name_2 = 0;
	skrr->start_name = NULL;
	skrr->end_name = NULL;
	skrr->neighb = NULL;
	skrr->current = NULL; // TODO can delete it later
	skrr->tmp = NULL; // TODO can delete it later
	skrr->link = NULL;
	skrr->room = NULL;
	g_info = NULL;
}

char 	*get_link(char *line)
{
	char 	*name;
	int 	i;

	i = -1;
	while ((*line) && (*line) != '-')
		line++;
	while (*line)
	{
		i++;
		line++;
	}
	name = ft_strnew((size_t)i);
	ft_strncpy(name, line - i, (size_t)i);
	return (name);
}

char 	*get_name(char *line, char c)
{
	char	*name;
	size_t 	i;

	i = 0;
	while ((*line) && (*line != c))
	{
		line++;
		i++;
	}
	name = ft_strnew(i);
	ft_strncpy(name, line - i, i);
	return (name);
}

int 	x_y_coord(char *line, int is_x)
{
	if (is_x)
	{
		while ((*line) && *line != ' ')
			(line)++;
		return ((int)ft_atoi(line));
	}
	else
	{
		while (*line)
			(line)++;
		while (*line != ' ')
			line--;
		return ((int)ft_atoi(line));
	}
}

void	print_lists(t_info *head)
{
	t_info *current;

	current = head;
	while (current != NULL)
	{
		ft_printf("%s\n", current->info);
		current = current->next;
	}
}

