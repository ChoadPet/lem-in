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
	int		fd;

	fd = open("test_2", O_RDONLY);
	(fd < 0) ? perror("fd error") : 0;
	init_func(&skrr, &head);
	while (get_next_line(fd, &line) > 0)
	{

		if (skrr.flag_an == 0)
			if (basic_info(&skrr, &head, &line) == -1)
				return (oops_error());
		if (skrr.flag_an == -1)
			if (fck_ants(&skrr, &line) == -1)
				return (oops_error());
	}
	print_lists(head);
	print_s_e(&skrr);
	close (fd);
	return 0;
}

