/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_useful.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 20:15:44 by vpoltave          #+#    #+#             */
/*   Updated: 2017/07/23 20:17:21 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		init_func(t_skrr *skrr)
{
	skrr->flag_an = -1;
	skrr->counts_ants = -1;
	skrr->start = 0;
	skrr->end = 0;
	skrr->for_start = 0;
	skrr->for_end = 0;
	skrr->found_rooms = 0;
	skrr->found_links = 0;
	skrr->name_1 = 0;
	skrr->name_2 = 0;
	skrr->flag = 0;
	skrr->wr_name = 0;
	skrr->spaces = 0;
	skrr->start_name = NULL;
	skrr->end_name = NULL;
	skrr->neighb = NULL;
	skrr->current = NULL;
	skrr->tmp = NULL;
	skrr->link = NULL;
	skrr->room = NULL;
	skrr->path = NULL;
	g_info = NULL;
	skrr->vertex = 0;
}

char		*get_link(char *line)
{
	char	*name;
	int		i;

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

char		*get_name(char *line, char c)
{
	char	*name;
	size_t	i;

	i = 0;
	while (line && (*line != c))
	{
		line++;
		i++;
	}
	name = ft_strnew(i);
	ft_strncpy(name, line - i, i);
	return (name);
}

long int	x_y_coord(char *line, int is_x)
{
	long int x;
	long int y;

	if (is_x)
	{
		while ((*line) && *line != ' ')
			(line)++;
		(!ft_isdigit(*(line + 1)) && ((*(line + 1) != '-'))) ? ex_error() : 0;
		((*(line + 1) == '0' && (*(line + 2) != ' '))) ? ex_error() : 0;
		x = ft_atoi(line);
		return (x);
	}
	else
	{
		while (*line)
			(line)++;
		while (*line != ' ')
			line--;
		(!ft_isdigit(*(line - 1)) && ((*(line - 1) != '-'))) ? ex_error() : 0;
		y = ft_atoi(line);
		return (y);
	}
}

void		print_lists(t_info *head)
{
	t_info *current;

	current = head;
	while (current != NULL)
	{
		ft_printf("%s\n", current->info);
		current = current->next;
	}
}
