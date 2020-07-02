/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_a_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 15:54:10 by efischer          #+#    #+#             */
/*   Updated: 2020/07/02 22:16:43 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int			add_to_bfs(t_machine *machine, t_list **bfs, t_room *room,
				size_t start_dist)
{
	t_list	*new_lst;

	room = find_room_mx(machine->room_mx, room);
	if (room->start_dist == 0 || start_dist < room->start_dist)
		room->start_dist = start_dist;
	else
		return (FALSE);
	new_lst = ft_lstnewnomalloc(room, sizeof(*room));
	if (new_lst == NULL)
		error(machine, "Cannot allocate memory");
	ft_lstaddend(bfs, new_lst);
	return (TRUE);
}

static int	check_reverse_link(t_room *room1, t_room *room2)
{
	t_room	*room;

	room = find_room(room1->next_rooms, room2->name);
	if (room != NULL && (room->link == ON || room->link == DEAD))
		return (FALSE);
	return (TRUE);
}

static void	set_link(t_room *room1, t_room *room2)
{
	t_room	*room;

	room = find_room(room1->next_rooms, room2->name);
	if (room != NULL && (room->link == ON || room->link == DEAD))
	{
		room->link = DEAD;
	//	ft_printf("set to dead: %s %d\n", room->name, room->link);
	}
}

static void	new_path(t_machine *machine, t_list *bfs, t_path *path)
{
	t_list	*lst_new;
	t_room	*last_room;
	t_room	*cur_room;
	t_room	*room;

	cur_room = bfs->content;
	if (cur_room != machine->end)
	{
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
				ft_printf("set to dead: %s %d\n", room->name, room->link);
				set_link(machine->room_mx[last_room->y][last_room->x], cur_room);
			}
		}
	}
	lst_new = ft_lstnewnomalloc(cur_room, sizeof(*cur_room));
	if (lst_new == NULL)
		error(machine, "Cannot allocate memory");
	ft_lstadd(&path->lst, lst_new);
}

static int	check_path(t_list *bfs, t_list *lst)
{
	t_room	*last_room;
	t_room	*cur_room;

	last_room = lst->content;
	cur_room = bfs->content;
	if (find_room(cur_room->next_rooms, last_room->name) != NULL
		 && cur_room->start_dist < last_room->start_dist)
	{
		return (TRUE);
	}
	return (FALSE);
}

int			get_a_path(t_machine *machine, t_list **bfs, t_path *path)
{
	t_list	*next_rooms;
	t_room	*cur_room;
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
		cur_room = next_rooms->content;
		if (cur_room->link == OFF && ft_strequ(cur_room->name, machine->start->name) == FALSE)
		{
			add_to_bfs(machine, bfs, next_rooms->content,
				((t_room*)((*bfs)->content))->start_dist + 1);
		}
		next_rooms = next_rooms->next;
	}
	ret = get_a_path(machine, &(*bfs)->next, path);
	if (ret == TRUE && check_path(*bfs, path->lst) == TRUE)
		new_path(machine, *bfs, path);
	return (ret);
}
