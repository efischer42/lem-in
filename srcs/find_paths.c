/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:55:54 by efischer          #+#    #+#             */
/*   Updated: 2020/06/10 18:55:03 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int			find_paths(t_machine *machine, t_room *room, t_room *last_room)
{
	t_list	*next_rooms;
	int		ret;

	ret = FALSE;
	next_rooms = room->next_rooms;
	if (room == machine->end)
		return (TRUE);
	if (room == machine->start)
		return (FALSE);
	while (next_rooms != NULL)
	{
		if (next_rooms->content != last_room
			&& next_rooms->content != machine->start)
		{
			if (find_paths(machine, next_rooms->content, room) == TRUE)
			{
				room->link++;
				ret = TRUE;
			}
		}
		next_rooms = next_rooms->next;
	}
	return (ret);
}
