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

int 	ants(t_path *path, t_skrr *skrr)
{
	t_path *head;
	t_path *tmp;

	head = path;
	while (ft_strcmp(head->name, skrr->start_name))
		head = head->next;
	head->ant_here = 1;
	while (skrr->counts_ants < skrr->ants)
	{
		tmp = path;
		while (tmp->next)
		{
			if (tmp->next->ant_here && (tmp->ant_here = 1))
			{
				tmp->ant_number = (int)skrr->ants - tmp->all_ants + 1;
				ft_printf("L%d-%s ", tmp->ant_number, tmp->name);
				tmp->all_ants--;
			}
			tmp = tmp->next;
		}
		write(1, "\n", 1);
		skrr->counts_ants++;
	}
	tmp = path;
	while (tmp->next)
		tmp = tmp->next;
	tmp->ant_here = 0;
	while (skrr->ants)
	{
		tmp = path;

		skrr->ants--;
	}
	return (1);
}