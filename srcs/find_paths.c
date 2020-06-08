/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:55:54 by efischer          #+#    #+#             */
/*   Updated: 2020/06/08 17:59:41 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int	reverse_link_exists(t_room *room, t_room *linked_room)
{
	t_list	*next_rooms;

	next_rooms = room->next_rooms;
	while (next_rooms != NULL)
	{
		if (((t_next_room*)(next_rooms->content))->room == linked_room
			&& (((t_next_room*)(next_rooms->content))->link == ON
			|| ((t_next_room*)(next_rooms->content))->link == DEAD))
		{
			((t_next_room*)(next_rooms->content))->link = DEAD;
			return (TRUE);
		}
		next_rooms = next_rooms->next;
	}
	return (FALSE);
}

void		find_paths(t_machine *machine, t_room *room, t_room *last_room)
{
	t_list	*next_rooms;

	next_rooms = room->next_rooms;
	if (room == machine->end)
		return ;
	while (next_rooms != NULL)
	{
		if (((t_next_room*)(next_rooms->content))->room != last_room
			&& ((t_next_room*)(next_rooms->content))->room != machine->start
			&& ((t_next_room*)(next_rooms->content))->link == OFF)
		{
			if (reverse_link_exists(((t_next_room*)(next_rooms->content))->room,
				room) == TRUE)
			{
				((t_next_room*)(next_rooms->content))->link = DEAD;
			}
			else
			{
				((t_next_room*)(next_rooms->content))->link = ON;
				find_paths(machine, ((t_next_room*)(next_rooms->content))->room,
						room);
			}
		}
		next_rooms = next_rooms->next;
	}
}
