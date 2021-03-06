/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 20:18:21 by vpoltave          #+#    #+#             */
/*   Updated: 2017/07/23 20:33:47 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/src/libft/libft.h"
# include <stdio.h>

/*
** linked list for all neighbors in current room
*/

typedef struct			s_neighbors
{
	struct s_room		*neighb;
	struct s_neighbors	*next;
}						t_neighbors;

/*
** linked list for rooms info
*/

typedef struct			s_room
{
	char				*name;
	long int			x_coord;
	long int			y_coord;
	int					metka;
	int					index;
	t_neighbors			*neighbors;
	struct s_room		*next;
}						t_room;

/*
** linked list for linking the rooms
*/

typedef struct			s_link
{
	char				*name1;
	char				*name2;
	struct s_link		*next;
}						t_link;

/*
** linked list for my shortest path
*/

typedef struct			s_path
{
	char				*name;
	int					ant_here;
	int					ant_number;
	int					all_ants;
	struct s_path		*next;
}						t_path;

/*
** linked list for each line (for output)
*/

typedef struct			s_info
{
	char				*info;
	struct s_info		*next;
}						t_info;

/*
** basic struct for additional info
*/

typedef struct			s_skrr
{
	long int			ants;
	int					counts_ants;
	int					flag_an;
	int					start;
	int					end;
	int					for_start;
	int					for_end;
	int					found_rooms;
	int					found_links;
	int					name_1;
	int					name_2;
	char				*start_name;
	char				*end_name;
	int					vertex;
	int					i;
	int					n;
	int					index;
	int					flag;
	int					spaces;
	int					wr_name;
	t_room				*current;
	t_room				*tmp;
	t_neighbors			*neighb;
	t_room				*room;
	t_link				*link;
	t_path				*path;
}						t_skrr;

t_info					*g_info;

/*
** functions for lem_in
*/

int						fck_ants(t_skrr *skrr, char **line);
int						second_main(char **line, t_skrr *skrr);
int						oops_error(void);
void					ex_error(void);
int						room_info(t_skrr *skrr, t_room **room, char **line);
int						link_info(t_skrr *skrr, t_room **room, char **line, \
							t_link **link);
int						push_room(t_room **room, char **line, char c, \
								t_skrr *skrr);
int						rooms_comp(t_room *room, char *line);
int						push_link(t_link **link, char **line, char c);
int						push_to_end(char **line);
void					init_func(t_skrr *skrr);
char					*get_name(char *line, char c);
char					*get_link(char *line);
long int				x_y_coord(char *line, int is_x);
int						two_spaces_start(t_skrr *skrr, char *line);
int						what_is_next(t_skrr *skrr, char **line, int start);
int						need_it(char **line);
int						should_i(t_skrr *skrr, t_room *room, char *line);
int						found_room(t_skrr *skrr, char *line);
int						found_links(t_skrr *skrr, char *line);
int						get_neighbor(t_skrr *skrr, t_room *room, t_link *link);
int						push_neighbor(t_neighbors **neighbor, t_room *current);
int						second_neighbor(t_neighbors *neighbors, \
										t_room *current);
t_room					*make_start(t_room *tmp, t_skrr *skrr);
int						bfs(t_skrr *skrr, t_room *room);
t_room					*get_room(t_room *head, int d);
int						get_my_path(t_skrr *skrr, t_room *room, t_path **path);
int						push_path(t_path **path, t_neighbors *neighbors, \
							t_room *tmp, t_skrr *skrr);
t_room					*next_neighb(int index, t_room *head);
int						fck_neighbors(t_neighbors *neighbors, t_skrr *skrr, \
								int *queue);
int						best_neighbors(t_path **path, t_skrr *skrr, \
									t_room *tmp);
void					ants(t_path *path, t_skrr *skrr);
void					end_way(t_path *tmp, t_path *path, t_skrr *skrr);
void					print_last_ants(t_path *tmp, t_skrr *skrr);
void					start_end(t_neighbors *neighbors, t_skrr *skrr);
void					print_lists(t_info *head);

#endif
