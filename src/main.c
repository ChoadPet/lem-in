/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 17:05:52 by vpoltave          #+#    #+#             */
/*   Updated: 2017/07/07 17:05:53 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // TODO delete this before finish the project
#include "../includes/lem_in.h"

int main()
{
	char 	*line;
	t_skrr	skrr;

	g_fd = open("test_1", O_RDONLY);
	(g_fd < 0) ? perror("fd error") : 0;
	init_func(&skrr);
	while (get_next_line(g_fd, &line) > 0)
	{
		if (!need_it(&line))
			return (oops_error());
		if (skrr.flag_an == 0 && (found_room(&skrr, line)))
			if (!(room_info(&skrr, &skrr.room, &line)))
				return (oops_error());
		if (found_links(&skrr, line))
			if (!(link_info(&skrr, &skrr.room, &line, &skrr.link)))
				return (oops_error());
		if (skrr.flag_an == -1) // TODO need to find place, where to put main algo
			if (!(fck_ants(&skrr, &line)))
				return (oops_error());
	}
	if ((!skrr.start || !skrr.end) || (!skrr.found_links) || skrr.start > 1 ||
		skrr.end > 1) // TODO maybe don't need it, next row too
		return (oops_error());
	print_lists(g_info);
//	print_nei(skrr.room);
	if (bfs(&skrr, skrr.room))
		get_my_path(&skrr, skrr.room, skrr.path);
	ft_strdel(&line);
	close (g_fd); // TODO delete this before finish the project
	return (0);
}

