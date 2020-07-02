/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:23:04 by efischer          #+#    #+#             */
/*   Updated: 2020/07/03 00:13:06 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

#include <stdio.h>//

static int	add_path_to_lst(t_machine *machine, t_list **lst, t_path *path)
{
	t_list	*lst_new;
	float	res;
	
	path->len = ft_lstlen(path->lst);
	lst_new = ft_lstnew(path, sizeof(*path));
	if (lst_new == NULL)
		error(machine, "Cannot allocate memory");
	res = (float)((float)machine->ants / (float)(ft_lstlen(*lst) + 1)
		+ path->len - ft_lstlen((*lst)) - 1 + path->len -
		((*lst) == NULL ? 0 : ((t_path*)((*lst)->content))->len - 1));
	printf("res: %f\n", res);//
	if (machine->nb_turn == 0 || res < machine->nb_turn)
	{
		machine->nb_turn = res;
		ft_lstaddend(lst, lst_new);
		return (TRUE);
	}
	free(lst_new->content);
	free(lst_new);
	return (FALSE);
}

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
//	if (paths_set->nb_turn == machine->path_set->nb_turn)
//	{
//		del_path_set(paths_set);
//		return (TRUE);
//	}
	ft_putendl("FALSE");//
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
	t_list		*bfs;
	t_path		path;
	t_list		*lst;
	size_t		i;
	int			dead;

	bfs = NULL;
	while (1)
	{
		ft_putendl("\nget path set");
		lst = NULL;
		i = 0;
		dead = FALSE;
		while (i < machine->max_path_nb)
		{
	//		ft_putendl("\nget path");
			add_to_bfs(machine, &bfs, machine->start, 1);
			ft_bzero(&path, sizeof(path));
			get_a_path(machine, &bfs, &path);
			if (path.dead == TRUE)
			{
	//			ft_putendl("Dead");
				dead = TRUE;
				ft_lstdel(&path.lst, del_nomalloc_lst);
				path.lst = NULL;
			}
			if (path.lst == NULL || add_path_to_lst(machine, &lst, &path) == FALSE)
			{
	//			ft_putendl("Break");
				ft_lstdel(&path.lst, del_nomalloc_lst);
				break ;
			}
			ft_lstdel(&bfs, del_bfs);
			i++;
		}
		ft_lstdel(&bfs, del_bfs);
		reset_room_links(machine);
		if (find_best_paths_set(machine, lst) == FALSE || dead == FALSE)
			break ;
	}
	debug_paths(machine->path_set->paths);
}
