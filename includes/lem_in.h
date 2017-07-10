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
	t_room			*start_room;
	t_room			*end_room;
}					t_skrr;

/*
** function for lem_in
*/

t_info				*g_info;

int					fck_ants(t_skrr *skrr, char **line);
int					oops_error(void);
int					basic_info(t_skrr *skrr, t_room **head, char **line);
int					push_to_beg(t_room **head, char **line);
void				init_func(t_skrr *skrr, t_room **head);
char 				*get_name(char *line);
int 				x_y_coord(char *line, int is_x);
int 				two_spaces(char *line);
int 				two_start(t_skrr *skrr);

//tmp fucntions
void	print_lists(t_room *head);
void	print_s_e(t_skrr *skrr);

#endif
