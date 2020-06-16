/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_a_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 15:54:10 by efischer          #+#    #+#             */
/*   Updated: 2020/06/16 16:20:04 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		add_to_bfs(t_machine *machine, t_list **bfs, t_room *room,
				size_t start_dist)
{
	t_list	*new_lst;

	if (room->start_dist == 0 || start_dist < room->start_dist)
		room->start_dist = start_dist;
	else
		return ;
	new_lst = ft_lstnewnomalloc(room, sizeof(*room));
	if (new_lst == NULL)
		error(machine, "Cannot allocate memory");
	ft_lstaddend(bfs, new_lst);
}

static void	new_path(t_machine *machine, t_list *bfs, t_list **lst)
{
	t_list	*lst_new;
	t_room	*room;

	room = bfs->content;
	lst_new = ft_lstnewnomalloc(room, sizeof(*room));
	if (lst_new == NULL)
		error(machine, "Cannot allocate memory");
	ft_printf("lst_new: %s\n", ((t_room*)(lst_new->content))->name);
	ft_lstadd(lst, lst_new);
}

static int	check_path(t_list *bfs, t_list *lst)
{
	t_room	*last_room;
	t_room	*cur_room;

	last_room = lst->content;
	cur_room = bfs->content;
	if (cur_room->start_dist < last_room->start_dist)
	{
		if (find_room(last_room->next_rooms, cur_room->name) != NULL)
			return (TRUE);
	}
	return (FALSE);
}

int			get_a_path(t_machine *machine, t_list **bfs, t_path *path)
{
	t_list	*next_rooms;
	int		ret;

	if (*bfs == NULL)
		return (FALSE);
	if ((*bfs)->content == machine->end)
	{
		new_path(machine, *bfs, &path->lst);
		return (TRUE);
	}
	next_rooms = ((t_room*)((*bfs)->content))->next_rooms;
	while (next_rooms != NULL)
	{
		add_to_bfs(machine, bfs, next_rooms->content,
			((t_room*)((*bfs)->content))->start_dist + 1);
		next_rooms = next_rooms->next;
	}
	ret = get_a_path(machine, &(*bfs)->next, path);
	if (ret == TRUE && check_path(*bfs, path->lst) == TRUE)
		new_path(machine, *bfs, &path->lst);
	return (ret);
}
