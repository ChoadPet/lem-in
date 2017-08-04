/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 19:48:49 by vpoltave          #+#    #+#             */
/*   Updated: 2017/07/23 20:34:32 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		main(void)
{
	char	*line;
	t_skrr	skrr;

	line = NULL;
	init_func(&skrr);
	while (get_next_line(0, &line) > 0)
		if (!second_main(&line, &skrr))
			return (0);
	if ((!skrr.start || !skrr.end) || (!skrr.found_links) || skrr.start > 1 ||
		skrr.end > 1)
		return (oops_error());
	if (bfs(&skrr, skrr.room))
		get_my_path(&skrr, skrr.room, &skrr.path);
	else
		return (oops_error());
	ft_strdel(&line);
	return (0);
}

int		second_main(char **line, t_skrr *skrr)
{
	if (!need_it(line))
		return (oops_error());
	if (skrr->flag_an == 0 && (found_room(skrr, *line)))
		if (!(room_info(skrr, &skrr->room, line)))
			return (oops_error());
	if (found_links(skrr, *line))
		if (!(link_info(skrr, &skrr->room, line, &skrr->link)))
			return (oops_error());
	if (skrr->flag_an == -1)
		if (!(fck_ants(skrr, line)))
			return (oops_error());
	ft_strdel(line);
	return (1);
}
