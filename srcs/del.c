/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 20:20:44 by efischer          #+#    #+#             */
/*   Updated: 2020/06/09 16:46:47 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	del_next_rooms_lst(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

static void	del_nomalloc_lst(void *content, size_t content_size)
{
	(void)content;
	(void)content_size;
}

void		del_room_lst(void *content, size_t content_size)
{
	(void)content_size;
	ft_strdel(&((t_room*)(content))->name);
	ft_lstdel(&((t_room*)(content))->next_rooms, del_next_rooms_lst);
	free(content);
}

void		del_path_lst(void *content, size_t content_size)
{
	t_list	*lst;

	(void)content_size;
	lst = content;
	ft_lstdel(&lst, del_nomalloc_lst);
}

void		del_token_lst(void *content, size_t content_size)
{
	(void)content_size;
	ft_strdel(&((t_token*)(content))->value);
	free(content);
}
