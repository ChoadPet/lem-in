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

void	init_func(t_skrr *skrr, t_room **room, t_link **link)
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
	*link = NULL;
	*room = NULL;
	g_info = NULL;
}

int 	need_it(char **line, t_skrr *skrr)
{
	if (**line == '#' && *(*line + 1) != '#')
		return (1);
	if ((ft_strcmp("##end", *line)) && (ft_strcmp("##start", *line)) &&
		(!(ft_strncmp("##", *line, 2))))
		return (1);
	push_to_end(line);
	return (1);
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
		return (ft_atoi(line));
	}
	else
	{
		while (*line)
			(line)++;
		while (*line != ' ')
			line--;
		return (ft_atoi(line));
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
