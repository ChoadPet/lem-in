

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