/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_mx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:00:18 by efischer          #+#    #+#             */
/*   Updated: 2020/06/08 14:26:02 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	allocate_lines(t_machine *machine)
{
	size_t	i;

	i = 0;
	while (i < machine->map_height)
	{
		machine->mx[i] = (t_room**)malloc(sizeof(t_room*) * machine->map_width);
		if (machine->mx[i] == NULL)
			error(machine, "Cannot allocate memory");
		ft_bzero(machine->mx[i], sizeof(*machine->mx[i]));
		i++;
	}
}

static void	fill_mx_data(t_machine *machine)
{
	t_list	*room_lst;
	size_t	x;
	size_t	y;

	room_lst = machine->room_lst;
	while (room_lst != NULL)
	{
		x = ((t_room*)(room_lst->content))->x;
		y = ((t_room*)(room_lst->content))->y;
		machine->mx[y][x] = room_lst->content;
		room_lst = room_lst->next;
	}
}

void		generate_mx(t_machine *machine)
{
	machine->mx = (t_room***)malloc(sizeof(t_room**) * machine->map_height);
	if (machine->mx == NULL)
		error(machine, "Cannot allocate memory");
	ft_bzero(machine->mx, sizeof(*machine->mx));
	allocate_lines(machine);
	fill_mx_data(machine);
}
