/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 20:20:44 by efischer          #+#    #+#             */
/*   Updated: 2020/06/22 18:13:32 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	del_nomalloc_lst(void *content, size_t content_size)
{
	(void)content;
	(void)content_size;
}

static void	del_next_rooms_lst(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

void	del_room_lst(void *content, size_t content_size)
{
	(void)content_size;
	ft_strdel(&((t_room*)(content))->name);
	ft_lstdel(&((t_room*)(content))->next_rooms, &del_next_rooms_lst);
	free(content);
}

void	del_path_lst(void *content, size_t content_size)
{
	(void)content_size;
	ft_lstdel(&((t_path*)(content))->lst, del_nomalloc_lst);
}

void	del_token_lst(void *content, size_t content_size)
{
	(void)content_size;
	ft_strdel(&((t_token*)(content))->value);
	free(content);
}

void	del_ant_lst(void *content, size_t content_size)
{
	(void)content_size;
	ft_strdel(&((t_ant*)(content))->id);
	free(content);
}

void	del_bfs(void *content, size_t content_size)
{
	(void)content_size;
	((t_room*)(content))->start_dist = 0;
}

static void	del_mx(t_machine *machine, t_room ***mx)
{
	size_t	x;
	size_t	y;

	y = 0;
	if (mx != NULL)
	{
		while (y < machine->map_height)
		{
			x = 0;
			while (x < machine->map_width)
			{
				if (mx[y][x]->name == NULL)
					free(mx[y][x]);
				x++;
			}
			free(mx[y]);
			y++;
		}
		free(mx);
	}
}

void	del_room_mx(t_machine *machine)
{
	t_list	*room_lst;
	t_room	*room;

	if (machine->room_mx != NULL)
	{
		room_lst = machine->room_lst;
		while (room_lst != NULL)
		{
			room = find_room_mx(machine->room_mx, room_lst->content);
			del_mx(machine, room->mx);
			room_lst = room_lst->next;
		}
		del_mx(machine, machine->room_mx);
	}
}
