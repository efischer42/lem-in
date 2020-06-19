/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_a_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 15:54:10 by efischer          #+#    #+#             */
/*   Updated: 2020/06/17 21:09:02 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		add_to_bfs(t_machine *machine, t_list **bfs, t_room *room,
				size_t start_dist)
{
	t_list	*new_lst;

	room = find_room(machine->room_lst, room->name);
	if (room->start_dist == 0 || start_dist < room->start_dist)
		room->start_dist = start_dist;
	else
		return ;
	new_lst = ft_lstnewnomalloc(room, sizeof(*room));
	if (new_lst == NULL)
		error(machine, "Cannot allocate memory");
	ft_lstaddend(bfs, new_lst);
}

static int	check_reverse_link(t_machine *machine, t_room *room1, t_room *room2)
{
	t_list	*next_rooms;

	room1 = find_room(machine->room_lst, room1->name);
	next_rooms = room1->next_rooms;
	while (next_rooms != NULL)
	{
		if (ft_strequ(((t_next_room*)(next_rooms->content))->room->name,
			room2->name) == TRUE && ((t_next_room*)(next_rooms->content))->link == ON)
		{
			return (FALSE);
		}
		next_rooms = next_rooms->next;
	}
	return (TRUE);
}

static void	set_link(t_machine *machine, t_room *room1, t_room *room2)
{
	t_list	*next_rooms;

	room1 = find_room(machine->room_lst, room1->name);
	next_rooms = room1->next_rooms;
	while (next_rooms != NULL)
	{
		if (ft_strequ(((t_next_room*)(next_rooms->content))->room->name,
			room2->name) == TRUE && ((t_next_room*)(next_rooms->content))->link == ON)
		{
			((t_next_room*)(next_rooms->content))->link = DEAD;
		}
		next_rooms = next_rooms->next;
	}
}

static void	new_path(t_machine *machine, t_list *bfs, t_path *path)
{
	t_list	*lst_new;
	t_room	*room;
	t_list	*next_rooms;

	room = bfs->content;
	if (room != machine->end)
	{
		next_rooms = room->next_rooms;
		while (next_rooms != NULL)
		{
			if (ft_strequ(((t_next_room*)(next_rooms->content))->room->name,
				((t_room*)(path->lst->content))->name) == TRUE)
			{
				((t_next_room*)(next_rooms->content))->link = ON;
				if (check_reverse_link(machine, ((t_next_room*)(next_rooms->content))->room,
					room) == FALSE)
				{
					((t_next_room*)(next_rooms->content))->link = DEAD;
					set_link(machine, ((t_next_room*)(next_rooms->content))->room, room);
				}
			}
			next_rooms = next_rooms->next;
		}
	}
	lst_new = ft_lstnewnomalloc(room, sizeof(*room));
	if (lst_new == NULL)
		error(machine, "Cannot allocate memory");
	ft_lstadd(&path->lst, lst_new);
}

static int	check_path(t_list *bfs, t_list *lst)
{
	t_room	*last_room;
	t_room	*cur_room;
	t_list	*next_rooms;

	last_room = lst->content;
	cur_room = bfs->content;
	next_rooms = cur_room->next_rooms;
	if (cur_room->start_dist < last_room->start_dist)
	{
		while (next_rooms != NULL)
		{
			if (ft_strequ(((t_next_room*)(next_rooms->content))->room->name,
				 last_room->name) == TRUE)
			{
				return (TRUE);
			}
			next_rooms = next_rooms->next;
		}
	}
	return (FALSE);
}

int			get_a_path(t_machine *machine, t_list **bfs, t_path *path)
{
	t_list	*next_rooms;
	int		ret;

	next_rooms = NULL;
	if (*bfs == NULL)
		return (FALSE);
	if ((*bfs)->content == machine->end)
	{
		new_path(machine, *bfs, path);
		return (TRUE);
	}
	next_rooms = ((t_room*)((*bfs)->content))->next_rooms;
	while (next_rooms != NULL)
	{
		if (((t_next_room*)(next_rooms->content))->link == OFF)
		{
			if (check_reverse_link(machine, ((t_next_room*)(next_rooms->content))->room,
				(*bfs)->content) == FALSE)
			{
				path->dead = TRUE;
			}
			add_to_bfs(machine, bfs, ((t_next_room*)(next_rooms->content))->room,
				((t_room*)((*bfs)->content))->start_dist + 1);
		}
		next_rooms = next_rooms->next;
	}
	ret = get_a_path(machine, &(*bfs)->next, path);
	if (ret == TRUE && check_path(*bfs, path->lst) == TRUE)
		new_path(machine, *bfs, path);
	return (ret);
}
