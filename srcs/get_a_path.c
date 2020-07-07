/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_a_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 15:54:10 by efischer          #+#    #+#             */
/*   Updated: 2020/07/07 11:58:58 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	new_path(t_machine *machine, t_list *bfs, t_path *path)
{
	t_list	*lst_new;
	t_room	*cur_room;

	cur_room = bfs->content;
	if (cur_room != machine->end)
		set_link(machine, path, cur_room);
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

static void	bfs_next(t_machine *machine, t_list **bfs)
{
	t_list	*next_rooms;
	t_room	*cur_room;

	next_rooms = ((t_room*)((*bfs)->content))->next_rooms;
	while (next_rooms != NULL)
	{
		cur_room = next_rooms->content;
		if (cur_room->link == OFF
			&& ft_strequ(cur_room->name, machine->start->name) == FALSE)
		{
			add_to_bfs(machine, bfs, next_rooms->content,
				((t_room*)((*bfs)->content))->start_dist + 1);
		}
		next_rooms = next_rooms->next;
	}
}

int			get_a_path(t_machine *machine, t_list **bfs, t_path *path)
{
	int		ret;

	if (*bfs == NULL)
		return (FALSE);
	if ((*bfs)->content == machine->end)
	{
		new_path(machine, *bfs, path);
		return (TRUE);
	}
	bfs_next(machine, bfs);
	ret = get_a_path(machine, &(*bfs)->next, path);
	if (ret == TRUE && check_path(*bfs, path->lst) == TRUE)
		new_path(machine, *bfs, path);
	return (ret);
}
