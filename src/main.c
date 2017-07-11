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

#include <stdio.h>
#include "../includes/lem_in.h"

int main()
{
	char 	*line;
	t_skrr	skrr;
	t_room	*head;

	g_fd = open("test_2", O_RDONLY);
	(g_fd < 0) ? perror("fd error") : 0;
	init_func(&skrr, &head);
	while (get_next_line(g_fd, &line) > 0)
	{
		if (!need_it(&line, &skrr))
			return (oops_error());
		if (skrr.flag_an == 0)
			if (!(basic_info(&skrr, &head, &line)))
				return (oops_error());
		if (skrr.flag_an == -1)
			if (!(fck_ants(&skrr, &line)))
				return (oops_error());
	}
	if (!skrr.start || !skrr.end)
		return (oops_error());
	print_lists(g_info);
	close (g_fd);
	return (0);
}

