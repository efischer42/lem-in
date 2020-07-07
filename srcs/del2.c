/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 10:39:37 by efischer          #+#    #+#             */
/*   Updated: 2020/07/07 10:40:16 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		del_ant_lst(void *content, size_t content_size)
{
	(void)content_size;
	ft_strdel(&((t_ant*)(content))->id);
	free(content);
}

void		del_bfs(void *content, size_t content_size)
{
	(void)content_size;
	((t_room*)(content))->start_dist = 0;
}

void		del_room_mx(t_machine *machine)
{
	size_t	y;

	if (machine->room_mx != NULL)
	{
		y = 0;
		while (y < machine->map_height)
		{
			free(machine->room_mx[y]);
			y++;
		}
		free(machine->room_mx);
	}
}

void		del_path_set(t_paths_set *path_set)
{
	if (path_set != NULL)
	{
		ft_lstdel(&path_set->paths, del_path_lst);
		free(path_set);
	}
}
