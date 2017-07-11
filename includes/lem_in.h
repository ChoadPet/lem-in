#ifndef LEM_IN_H
#define LEM_IN_H

#include "../libft/src/libft/libft.h"
#include <stdio.h>

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
	char 			*name_1;
	char 			*name_2;
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
	int 			comment_s;
	int 			comment_e;
	int 			first_time;
	t_room			*start_room;
	t_room			*end_room;
}					t_skrr;

/*
** function for lem_in
*/

t_info				*g_info;
int 				g_fd;

int					fck_ants(t_skrr *skrr, char **line);
int					oops_error(void);
int					basic_info(t_skrr *skrr, t_room **head, char **line);
int					push_to_beg(t_room **head, char **line);
int 				push_to_end(char **line);
void				init_func(t_skrr *skrr, t_room **head);
char 				*get_name(char *line);
int 				x_y_coord(char *line, int is_x);
int 				two_spaces(char *line);
int 				two_start(t_skrr *skrr);
int					what_is_next(t_skrr *skrr, char **line, int start);
int 				need_it(char **line, t_skrr *skrr);

//tmp fucntions
void	print_lists(t_info *head);

#endif
