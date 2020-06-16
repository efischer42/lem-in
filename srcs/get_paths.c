/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:23:04 by efischer          #+#    #+#             */
/*   Updated: 2020/06/16 16:37:45 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	add_path_to_lst(t_machine *machine, t_path *path)
{
	t_list	*lst_new;
	
	path->len = ft_lstlen(path->lst);
	lst_new = ft_lstnew(path, sizeof(*path));
	if (lst_new == NULL)
		error(machine, "Cannot allocate memory");
	ft_lstaddend(&machine->path_lst, lst_new);
}

void		get_paths(t_machine *machine)
{
	t_list	*bfs;
	t_path	path;

	bfs = NULL;
	add_to_bfs(machine, &bfs, machine->start, 1);
//	while (1)
//	{
		ft_bzero(&path, sizeof(path));
		get_a_path(machine, &bfs, &path);
//		if (path.lst == NULL)
//			break ;
		if (path.lst != NULL)
			add_path_to_lst(machine, &path);
		ft_lstdel(&bfs, del_bfs);
//	}
	ft_lstdel(&bfs, del_bfs);
}
