/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 20:20:44 by efischer          #+#    #+#             */
/*   Updated: 2020/07/07 10:40:16 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		del_nomalloc_lst(void *content, size_t content_size)
{
	(void)content;
	(void)content_size;
}

static void	del_next_rooms_lst(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

void		del_room_lst(void *content, size_t content_size)
{
	(void)content_size;
	ft_strdel(&((t_room*)(content))->name);
	ft_lstdel(&((t_room*)(content))->next_rooms, &del_next_rooms_lst);
	free(content);
}

void		del_path_lst(void *content, size_t content_size)
{
	(void)content_size;
	ft_lstdel(&((t_path*)(content))->lst, del_nomalloc_lst);
	free(content);
}

void		del_token_lst(void *content, size_t content_size)
{
	(void)content_size;
	ft_strdel(&((t_token*)(content))->value);
	free(content);
}
