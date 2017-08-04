/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_ants.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 17:05:35 by vpoltave          #+#    #+#             */
/*   Updated: 2017/07/23 19:38:51 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ants(t_path *path, t_skrr *skrr)
{
	t_path *head;
	t_path *tmp;

	head = path;
	skrr->i = 0;
	while (ft_strcmp(head->name, skrr->start_name))
		head = head->next;
	head->ant_here = 1;
	while (++skrr->counts_ants < skrr->ants)
	{
		tmp = path;
		while (tmp->next)
		{
			if (tmp->next->ant_here && (tmp->ant_here = 1))
			{
				tmp->ant_number = (int)skrr->ants - tmp->all_ants + 1;
				skrr->i = tmp->ant_number;
				ft_printf("L%d-%s ", tmp->ant_number, tmp->name);
				tmp->all_ants--;
			}
			tmp = tmp->next;
		}
		ft_printf("\n");
	}
	end_way(tmp, path, skrr);
}

void	end_way(t_path *tmp, t_path *path, t_skrr *skrr)
{
	t_path *kos;
	t_room *curr;

	tmp = path;
	while (ft_strcmp(tmp->name, skrr->start_name))
		tmp = tmp->next;
	tmp->ant_here = 0;
	curr = skrr->room;
	while (ft_strcmp(curr->name, skrr->end_name))
		curr = curr->next;
	start_end(curr->neighbors, skrr);
	if (skrr->flag == 1)
		return ;
	while (skrr->i)
	{
		tmp = path;
		(skrr->ants == 1) ? kos = tmp : 0;
		print_last_ants(tmp, skrr);
		skrr->i - skrr->ants >= 0 ? ft_printf("\n") : 0;
		(skrr->ants == 1) ? ft_printf("L1-%s ", kos->name) : 0;
		skrr->i--;
	}
	ft_printf("\n");
}

void	start_end(t_neighbors *neighbors, t_skrr *skrr)
{
	t_neighbors *tmp;

	tmp = neighbors;
	while (tmp)
	{
		if (!(ft_strcmp(tmp->neighb->name, skrr->start_name)))
			skrr->flag = 1;
		tmp = tmp->next;
	}
}

void	print_last_ants(t_path *tmp, t_skrr *skrr)
{
	while (tmp->next)
	{
		if (tmp->next->ant_here)
		{
			tmp->ant_number = (int)skrr->ants - tmp->all_ants + 1;
			ft_printf("L%d-%s ", tmp->ant_number, tmp->name);
			tmp->all_ants--;
		}
		else
			tmp->ant_here = 0;
		tmp = tmp->next;
	}
}
