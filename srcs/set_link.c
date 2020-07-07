/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 11:57:42 by efischer          #+#    #+#             */
/*   Updated: 2020/07/07 11:58:19 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	check_reverse_link(t_room *room1, t_room *room2)
{
	t_room	*room;

	room = find_room(room1->next_rooms, room2->name);
	if (room != NULL && (room->link == ON || room->link == DEAD))
		return (FALSE);
	return (TRUE);
}

static void	set_dead(t_room *room1, t_room *room2)
{
	t_room	*room;

	room = find_room(room1->next_rooms, room2->name);
	if (room != NULL && (room->link == ON || room->link == DEAD))
		room->link = DEAD;
}

void		set_link(t_machine *machine, t_path *path, t_room *cur_room)
{
	t_room	*last_room;
	t_room	*room;

	last_room = path->lst->content;
	room = find_room(cur_room->next_rooms, last_room->name);
	if (room != NULL)
	{
		room->link = ON;
		if (check_reverse_link(machine->room_mx[last_room->y][last_room->x],
			cur_room) == FALSE)
		{
			path->dead = TRUE;
			room->link = DEAD;
			set_dead(machine->room_mx[last_room->y][last_room->x], cur_room);
		}
	}
}
