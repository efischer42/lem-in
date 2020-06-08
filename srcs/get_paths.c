/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:23:04 by efischer          #+#    #+#             */
/*   Updated: 2020/06/08 18:05:07 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	get_a_path(t_machine *machine, t_room *room, char **print)
{
	t_list	*next_rooms;

	if (room == machine->end)
	{
		*print = ft_join_free(*print, room->name, 1);
		*print = ft_join_free(*print, "\n", 1);
		return ;
	}
	*print = ft_join_free(*print, room->name, 1);
	*print = ft_join_free(*print, "-", 1);
	next_rooms = room->next_rooms;
	while (next_rooms != NULL)
	{
		if (((t_next_room*)(next_rooms->content))->link == ON)
		{
			get_a_path(machine, ((t_next_room*)(next_rooms->content))->room, print);
			break ;
		}
		next_rooms = next_rooms->next;
	}
}

void		get_paths(t_machine *machine)
{
	t_list	*next_rooms;
	char	*print;

	print = NULL;
	next_rooms = machine->start->next_rooms;
	while (next_rooms != NULL)
	{
		if (((t_next_room*)(next_rooms->content))->link == ON)
		{
			print = ft_join_free(print, machine->start->name, 1);
			print = ft_join_free(print, "-", 1);
			get_a_path(machine, ((t_next_room*)(next_rooms->content))->room, &print);
		}
		next_rooms = next_rooms->next;
	}
	ft_putstr(print);
	ft_strdel(&print);
}
