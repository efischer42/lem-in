/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 11:49:52 by efischer          #+#    #+#             */
/*   Updated: 2020/06/25 11:52:16 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	get_max_path_nb(t_machine *machine)
{
	size_t	len;

	len = ft_lstlen(machine->start->next_rooms);
	machine->max_path_nb = len;
	len = ft_lstlen(machine->end->next_rooms);
	if (len < machine->max_path_nb)
		machine->max_path_nb = len;
}

static void	set_next_rooms_mx(t_machine *machine)
{
	t_list	*room_lst;
	t_room	*room;

	room_lst = machine->room_lst;
	while (room_lst != NULL)
	{
		room = find_room_mx(machine->room_mx, room_lst->content);
		generate_mx(machine, &room->mx);
		fill_mx_data(room->mx, ((t_room*)(room_lst->content))->next_rooms);
		room_lst = room_lst->next;
	}
}

void		solve(t_machine *machine)
{
	ft_printf("nb ants: %d\n", machine->ants);
	get_max_path_nb(machine);
	set_next_rooms_mx(machine);
	get_paths(machine);
	debug_paths(machine->path_set->paths);
	send_ants(machine);
}
