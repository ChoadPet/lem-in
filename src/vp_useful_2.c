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

int 	need_it(char **line, t_skrr *skrr)
{
	if (**line == '#' && *(*line + 1) != '#')
		return (1);
	if ((ft_strcmp("##end", *line)) && (ft_strcmp("##start", *line)) &&
		(**line == '#' && *(*line + 1) == '#'))
		return (0);
	push_to_end(line);
	return (1);
}