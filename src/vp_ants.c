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
	skrr->ants = ft_atoi(*line);
	if (skrr->ants < 0)
		return (-1);
	skrr->flag_an = 0;
	ft_printf("%d\n", skrr->ants);
	return (1);
}


int 	basic_info(t_skrr *skrr, t_room **head, char **line)
{
	if (!(ft_strcmp("##start", *line)))
	{
		skrr->start++;
		return (1);
	}
	if (!(ft_strcmp("##end", *line)))
	{
		skrr->end++;
		return (1);
	}
	if (two_spaces(*line))
		return (-1);
	else if (two_start(skrr))
		return (-1);
	if ((skrr->start == 1 && !(skrr->for_start)) && (skrr->for_start = 1))
		push_to_beg(&skrr->start_room, line);
	else if ((skrr->end == 1 && !(skrr->for_end)) && (skrr->for_end = 1))
		push_to_beg(&skrr->end_room, line);
	else
		push_to_beg(head, line);
	return (1);
}

int		push_to_beg(t_room **head, char **line)
{
	t_room *new_room;

	if (!(new_room = (t_room *)malloc(sizeof(t_room))))
		return (-2);
	new_room->name = get_name(*line);
	new_room->x_coord = x_y_coord(*line, 1);
	new_room->y_coord = x_y_coord(*line, 0);
	new_room->next = *head;
	*head = new_room;
	return (1);
}

void	print_lists(t_room *head)
{
	t_room *current;

	current = head;
	while (current != NULL)
	{
		printf("%s ", current->name);
		printf("%d ", current->x_coord);
		printf("%d\n", current->y_coord);
		current = current->next;
	}
}

void	print_s_e(t_skrr *skrr)
{
	ft_printf("----------------------------------\n");
	ft_printf("%s", skrr->start_room->name);
	ft_printf(" %d", skrr->start_room->x_coord);
	ft_printf(" %d\n", skrr->start_room->y_coord);
	ft_printf("----------------------------------\n");
	ft_printf("%s", skrr->end_room->name);
	ft_printf(" %d", skrr->end_room->x_coord);
	ft_printf(" %d\n", skrr->end_room->y_coord);
}