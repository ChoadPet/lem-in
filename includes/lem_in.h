#ifndef LEM_IN_H
#define LEM_IN_H

#include "../libft/src/libft/libft.h"
#include <stdio.h>

typedef struct 		s_room
{
	char 			*name;
	int 			x_coord;
	int 			y_coord;
	struct s_room 	*next;
}					t_room;

typedef struct		s_skrr
{
	int				ants;
	int 			flag_an;
	int 			start_room;
	int 			end_room;
	int 			found_start;
	int 			found_end;

}					t_skrr;

void				fck_ants(t_skrr *skrr, char **line);
int					oops_error(void);
void				basic_info(t_skrr *skrr, char **line);
void				push_to_beg(t_room **room, char **line);
void				push_to_end(t_room **room, char **line);
void				clear_func(t_skrr *skrr);
char 				*get_name(char **line);
int 				x_y_coord(char **line, int is_x);
int 				two_spaces(char *line);

//tmp fucntions
void	print_lists(t_room *head);

#endif
