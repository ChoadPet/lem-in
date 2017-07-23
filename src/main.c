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

	line = NULL;
	init_func(&skrr);
	while (get_next_line(0, &line) > 0)
		if (!second_main(&line, &skrr))
			return (0);
	if ((!skrr.start || !skrr.end) || (!skrr.found_links) || skrr.start > 1 ||
		skrr.end > 1) // TODO maybe don't need it, next row too
		return (oops_error());
	if (bfs(&skrr, skrr.room))
		get_my_path(&skrr, skrr.room, &skrr.path);
	else
		return (oops_error());
	ft_strdel(&line);
	return (0);
}

