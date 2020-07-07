/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 11:51:18 by efischer          #+#    #+#             */
/*   Updated: 2020/07/07 10:17:18 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	debug_rooms(t_machine *machine)
{
	t_list	*room_lst;
	t_list	*next_rooms;
	char	*print;

	print = NULL;
	room_lst = machine->room_lst;
	ft_putendl("\nDebug rooms\n");
	while (room_lst != NULL)
	{
		print = ft_join_free(print, ((t_room*)(room_lst->content))->name, 1);
		next_rooms = ((t_room*)(room_lst->content))->next_rooms;
		while (next_rooms != NULL)
		{
			print = ft_join_free(print, " - ", 1);
			print = ft_join_free(print, ((t_room*)(next_rooms->content))->name, 1);
			print = ft_join_free(print, ".", 1);
			print = ft_join_free(print, ft_itoa(((t_room*)(next_rooms->content))->link), 3);
			next_rooms = next_rooms->next;
		}
		room_lst = room_lst->next;
		print = ft_join_free(print, "\n", 1);
	}
	ft_putstr(print);
	ft_strdel(&print);
}
