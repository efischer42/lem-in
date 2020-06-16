/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 20:20:44 by efischer          #+#    #+#             */
/*   Updated: 2020/06/16 16:24:09 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	del_nomalloc_lst(void *content, size_t content_size)
{
	(void)content;
	(void)content_size;
}

void	del_room_lst(void *content, size_t content_size)
{
	(void)content_size;
	ft_strdel(&((t_room*)(content))->name);
	ft_lstdel(&((t_room*)(content))->next_rooms, del_nomalloc_lst);
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
