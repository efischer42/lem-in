/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:23:04 by efischer          #+#    #+#             */
/*   Updated: 2020/06/18 15:11:48 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	add_path_to_lst(t_machine *machine, t_list **lst, t_path *path)
{
	t_list	*lst_new;
	
	if (path->dead == TRUE)
		ft_lstdel(&path->lst, del_nomalloc_lst);
	else
	{
		path->len = ft_lstlen(path->lst);
		lst_new = ft_lstnew(path, sizeof(*path));
		if (lst_new == NULL)
			error(machine, "Cannot allocate memory");
		ft_lstaddend(lst, lst_new);
	}
}

static void	add_lst_to_lst(t_machine *machine, t_list *lst)
{
	t_list	*lst_new;
	
	lst_new = ft_lstnew(lst, sizeof(*lst));
	if (lst_new == NULL)
		error(machine, "Cannot allocate memory");
	ft_lstaddend(&machine->path_lst, lst_new);
}

static void	reset_room_links(t_machine *machine)
{
	t_list	*room_lst;
	t_list	*next_rooms;

	room_lst = machine->room_lst;
	while (room_lst != NULL)
	{
		next_rooms = ((t_room*)(room_lst->content))->next_rooms;
		while (next_rooms != NULL)
		{
			if (((t_next_room*)(next_rooms->content))->link == ON)
				((t_next_room*)(next_rooms->content))->link = OFF;
			next_rooms = next_rooms->next;
		}
		room_lst = room_lst->next;
	}
}

void		get_paths(t_machine *machine)
{
	t_list	*bfs;
	t_path	path;
	t_list	*lst;
	size_t	i;
	int		dead;

	bfs = NULL;
	while (1)
	{
		i = 0;
		lst = NULL;
		dead = FALSE;
		while (i < machine->max_path_nb)
		{
			debug_rooms(machine);
			add_to_bfs(machine, &bfs, machine->start, 1);
			ft_bzero(&path, sizeof(path));
			get_a_path(machine, &bfs, &path);
			if (path.dead == TRUE)
				dead = TRUE;
			if (path.lst == NULL)
				break ;
			add_path_to_lst(machine, &lst, &path);
			ft_lstdel(&bfs, del_bfs);
			i++;
		}
		ft_lstdel(&bfs, del_bfs);
		reset_room_links(machine);
		add_lst_to_lst(machine, lst);
		if (dead == FALSE)
			break ;
	}
}
