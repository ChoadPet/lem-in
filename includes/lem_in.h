#ifndef LEM_IN_H
#define LEM_IN_H

#include "../libft/src/libft/libft.h"
#include <stdio.h>

int 				g_fd; // TODO delete this before final the project!

/*
** linked list for rooms info
*/

typedef struct 		s_room
{
	char 			*name;
	int 			x_coord;
	int 			y_coord;
	struct s_room 	*next;
}					t_room;

/*
** linked list for linking the rooms
*/

typedef struct 		s_link
{
	char 			*name1;
	char 			*name2;
	struct s_link	*next;
}					t_link;

/*
** linked list for each fucking line
*/

typedef struct 		s_info
{
	char 			*info;
	struct s_info	*next;
}					t_info;

/*
** basic struct for additional info
*/

typedef struct		s_skrr
{
	int				ants;
	int 			flag_an;
	int 			start;
	int 			end;
	int 			for_start;
	int 			for_end;
	int 			found_rooms;
	int 			found_links;
	int 			name_1;
	int				name_2;
	char			*start_name;
	char			*end_name;
}					t_skrr;

/*
** function for lem_in
*/
t_info				*g_info;

int					fck_ants(t_skrr *skrr, char **line);
int					oops_error(void);
int					room_info(t_skrr *skrr, t_room **room, char **line);
int 				link_info(t_skrr *skrr, t_room **room, char **line, t_link **link);
int					push_room(t_room **room, char **line, char c);
int 				rooms_comp(t_room *room, char *line);
int					push_link(t_link **link, char **line, char c);
//int					link_cmp_rooms(t_link *link, char *line); // TODO function which should do more validations
int 				push_to_end(char **line);
void				init_func(t_skrr *skrr, t_room **room, t_link **link);
char 				*get_name(char *line, char c);
char 				*get_link(char *line);
int 				x_y_coord(char *line, int is_x);
int 				two_spaces_start(t_skrr *skrr, char *line);
int					what_is_next(t_skrr *skrr, char **line, int start);
int 				need_it(char **line, t_skrr *skrr);
int 				should_i(t_skrr *skrr, t_room *room, char *line);
int 				found_room(t_skrr *skrr, char *line);
int 				found_links(t_skrr *skrr, char *line);

//tmp fucntions
void				print_lists(t_info *head);

#endif
