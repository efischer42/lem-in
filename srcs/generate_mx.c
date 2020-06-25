/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_mx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 15:22:55 by efischer          #+#    #+#             */
/*   Updated: 2020/06/25 15:04:12 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		fill_mx_data(t_room ***mx, t_list *room_lst)
{
	size_t	x;
	size_t	y;

	while (room_lst != NULL)
	{
		x = ((t_room*)(room_lst->content))->x;
		y = ((t_room*)(room_lst->content))->y;
		mx[y][x] = room_lst->content;
		room_lst = room_lst->next;
	}
}

static void	set_rooms_to_null(t_machine *machine, t_room **mx)
{
	size_t	i;

	i = 0;
	while (i < machine->map_width)
	{
		mx[i] = NULL;
		i++;
	}
}

static void	allocate_lines(t_machine *machine, t_room ****mx)
{
	size_t	i;

	i = 0;
	while (i < machine->map_height)
	{
		(*mx)[i] = (t_room**)malloc(sizeof(t_room*) * machine->map_width);
		if ((*mx)[i] == NULL)
			error(machine, "Cannot allocate memory");
		ft_bzero((*mx)[i], sizeof(*(*mx)[i]));
		set_rooms_to_null(machine, (*mx)[i]);
		i++;
	}
}

void		generate_mx(t_machine *machine, t_room ****mx)
{
	*mx = (t_room***)malloc(sizeof(t_room**) * machine->map_height);
	if (*mx == NULL)
		error(machine, "Cannot allocate memory");
	ft_bzero(*mx, sizeof(**mx));
	allocate_lines(machine, mx);
}
