/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:23:04 by efischer          #+#    #+#             */
/*   Updated: 2020/06/09 16:28:03 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int	get_a_path(t_machine *machine, t_list **lst, t_room *room)
{
	t_list	*next_rooms;
	t_list	*lst_new;

	if (room == machine->end)
	{
		lst_new = ft_lstnewnomalloc(room, sizeof(*room));
		ft_lstadd(lst, lst_new);
		return (TRUE);
	}
	next_rooms = room->next_rooms;
	while (next_rooms != NULL)
	{
		if (((t_next_room*)(next_rooms->content))->link == ON)
		{
			get_a_path(machine, lst, ((t_next_room*)(next_rooms->content))->room);
			break ;
		}
		next_rooms = next_rooms->next;
	}
	if (next_rooms == NULL)
		return (FALSE);
	lst_new = ft_lstnewnomalloc(room, sizeof(*room));
	ft_lstadd(lst, lst_new);
	return (TRUE);
}

void		get_paths(t_machine *machine)
{
	t_list	*next_rooms;
	t_list	*lst_new;
	t_list	*lst;

	next_rooms = machine->start->next_rooms;
	while (next_rooms != NULL)
	{
		lst = NULL;
		if (((t_next_room*)(next_rooms->content))->link == ON)
		{
			if (get_a_path(machine, &lst, ((t_next_room*)(next_rooms->content))->room) == TRUE)
			{
				lst_new = ft_lstnewnomalloc(machine->start, sizeof(*machine->start));
				ft_lstadd(&lst, lst_new);
				lst_new = ft_lstnew(lst, sizeof(*lst));
				if (lst_new == NULL)
					error(machine, "Cannot allocate memory");
				ft_lstaddend(&machine->path_lst, lst_new);
			}
		}
		next_rooms = next_rooms->next;
	}
}
