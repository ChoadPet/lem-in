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

void	fck_ants(t_skrr *skrr, char **line)
{
	skrr->ants = ft_atoi(*line);
	if (skrr->ants <= 0)
		oops_error();
	ft_printf("ants: %d\n", skrr->ants);
	skrr->flag_an = 0;
}


void	basic_info(t_skrr * skrr, char **line)
{
	t_room *room;

	if (!(room = malloc(sizeof(t_room))))
		perror("malloc error");
	(skrr->start_room) ? push_to_beg(&room, line) : 0;
	(skrr->end_room) ? push_to_end(&room, line) : 0;
	(!(ft_strcmp("##start", *line))) ? skrr->start_room = 1 : 0;
	(!(ft_strcmp("##end", *line))) ? skrr->end_room = 1 : 0;
}

void	push_to_beg(t_room **room, char **line)
{
	t_room	*new_room;

	if (!(two_spaces(*line)))
	{
		oops_error();
		return ;
	}
	if (!(new_room = malloc(sizeof(t_room))))
		perror("new_room malloc error");
	new_room->name = get_name(line);
	new_room->x_coord = x_y_coord(line, 1);
	new_room->y_coord = x_y_coord(line, 0);
	new_room->next = *room;
	*room = new_room;
	print_lists(new_room);
}

void	push_to_end(t_room **room, char **line)
{

}

void	print_lists(t_room *head)
{
	t_room *current;

	current = head;
	while (current != NULL)
	{
		ft_printf("name: %s\n", current->name);
		ft_printf("x_coord: %d\n", current->x_coord);
		ft_printf("y_coord: %d\n", current->y_coord);
		current = current->next;
	}
}