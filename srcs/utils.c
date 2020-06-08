/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 20:34:53 by efischer          #+#    #+#             */
/*   Updated: 2020/06/06 15:37:57 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_room	*find_room(t_machine *machine, char *name)
{
	t_list	*room_lst;

	room_lst = machine->room_lst;
	while (room_lst != NULL)
	{
		if (ft_strequ(((t_room*)(room_lst->content))->name, name) == TRUE)
			return (room_lst->content);
		room_lst = room_lst->next;
	}
	return (NULL);
}
