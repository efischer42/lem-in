/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:23:04 by efischer          #+#    #+#             */
/*   Updated: 2020/07/07 11:50:34 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	find_best_paths_set(t_machine *machine, t_list *path_lst)
{
	t_paths_set	*paths_set;

	paths_set = (t_paths_set*)malloc(sizeof(*paths_set));
	ft_bzero(paths_set, sizeof(*paths_set));
	paths_set->paths = path_lst;
	paths_set->nb_path = ft_lstlen(path_lst);
	paths_set->nb_turn = machine->nb_turn;
	if (machine->path_set == NULL
		|| paths_set->nb_turn < machine->path_set->nb_turn)
	{
		del_path_set(machine->path_set);
		machine->path_set = paths_set;
		return (TRUE);
	}
	del_path_set(paths_set);
	return (FALSE);
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
			if (((t_room*)(next_rooms->content))->link == ON)
				((t_room*)(next_rooms->content))->link = OFF;
			next_rooms = next_rooms->next;
		}
		room_lst = room_lst->next;
	}
}

void		get_paths(t_machine *machine)
{
	t_list		*lst;
	int			dead;

	while (1)
	{
		lst = NULL;
		dead = get_paths_set(machine, &lst);
		if (lst == NULL)
			error(machine, "No valid path");
		reset_room_links(machine);
		if (find_best_paths_set(machine, lst) == FALSE || dead == FALSE)
			break ;
	}
}
