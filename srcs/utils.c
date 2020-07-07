/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 20:34:53 by efischer          #+#    #+#             */
/*   Updated: 2020/07/07 11:56:26 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	*find_room_mx(t_room ***mx, t_room *room)
{
	return (mx[room->y][room->x]);
}

t_room	*find_room(t_list *room_lst, char *name)
{
	while (room_lst != NULL)
	{
		if (ft_strequ(((t_room*)(room_lst->content))->name, name) == TRUE)
			return (room_lst->content);
		room_lst = room_lst->next;
	}
	return (NULL);
}

void	sort_ants(t_list **lst1, t_list **lst2, t_list **head)
{
	if (((t_ant*)((*lst1)->content))->done == TRUE
		&& ((t_ant*)((*lst2)->content))->done == FALSE)
	{
		*head = *lst2;
		*lst2 = (*lst2)->next;
	}
	else
	{
		*head = *lst1;
		*lst1 = (*lst1)->next;
	}
}

int		add_to_bfs(t_machine *machine, t_list **bfs, t_room *room,
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

t_list	*get_shortest_path(t_list *path_lst)
{
	t_list	*shortest_path;

	shortest_path = path_lst;
	while (path_lst != NULL)
	{
		if (((t_path*)(path_lst->content))->len
			< ((t_path*)(shortest_path->content))->len)
		{
			shortest_path = path_lst;
		}
		path_lst = path_lst->next;
	}
	return (shortest_path);
}
