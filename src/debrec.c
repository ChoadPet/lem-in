

//int 	push_to_end(t_room *head, char **line)
//{
//	t_room *new_room;
//	t_room *current;
//
//	if (!(new_room = (t_room *)malloc(sizeof(t_room))))
//		return (-2);
//	new_room->name = get_name(*line);
//	new_room->x_coord = x_y_coord(*line, 1);
//	new_room->y_coord = x_y_coord(*line, 0);
//	new_room->next = NULL;
//	if (head->next == NULL)
//		head->next = new_room;
//	else
//	{
//		current = head;
//		while (current->next != NULL)
//			current = current->next;
//		current->next = new_room;
//	}
//	return (1);
//}

//void	print_s_e(t_skrr *skrr)
//{
//	ft_printf("----------------------------------\n");
//	ft_printf("%s", skrr->start_room->name);
//	ft_printf(" %d", skrr->start_room->x_coord);
//	ft_printf(" %d\n", skrr->start_room->y_coord);
//	ft_printf("----------------------------------\n");
//	ft_printf("%s", skrr->end_room->name);
//	ft_printf(" %d", skrr->end_room->x_coord);
//	ft_printf(" %d\n", skrr->end_room->y_coord);
//}

//		ft_printf("queue[%d] = %d\n", d, queue[d]);
//		ft_printf("room name -> %s\n", room->name);
//			ft_printf("INSIDE -> queue[%d] = %d\n", i, queue[i]);
//				ft_printf("room exit name -> %s\n", room->neighbors->neighb->name);
//				ft_printf("found exit!\n");