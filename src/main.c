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

#include "../includes/lem_in.h"

int main()
{
	char 	*line;
	t_skrr	skrr;
	int		fd;

	clear_func(&skrr);
	fd = open("test_1", O_RDONLY);
	if (fd < 0)
		perror("fd error");
	while (get_next_line(fd, &line) > 0)
	{
		(skrr.flag_an == 0) ? basic_info(&skrr, &line) : 0;
		(skrr.flag_an == -1) ? fck_ants(&skrr, &line) : 0;
	}
	close (fd);
	return 0;
}

