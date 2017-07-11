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

void	init_func(t_skrr *skrr, t_room **head)
{
	skrr->flag_an = -1;
	skrr->start = 0;
	skrr->end = 0;
	skrr->for_start = 0;
	skrr->for_end = 0;
	skrr->comment_s = 0;
	skrr->comment_e = 0;
	skrr->start_room = NULL;
	skrr->end_room = NULL;
	*head = NULL;
	g_info = NULL;
}

char 	*get_name(char *line)
{
	char	*name;
	size_t 	i;

	i = 0;
	while ((*line) && (*line != ' '))
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
	int	x;
	int y;

	if (is_x)
	{
		while ((*line) && *line != ' ')
			(line)++;
		x = ft_atoi(line);
		return (x);
	}
	else
	{
		while (*line)
			(line)++;
		while (*line != ' ')
			line--;
		y = ft_atoi(line);
		return (y);
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
