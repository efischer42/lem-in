/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 20:20:44 by efischer          #+#    #+#             */
/*   Updated: 2020/06/08 14:50:06 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	del_next_rooms_lst(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

void	del_room_lst(void *content, size_t content_size)
{
	(void)content_size;
	ft_strdel(&((t_room*)(content))->name);
	ft_lstdel(&((t_room*)(content))->next_rooms, del_next_rooms_lst);
	free(content);
}

void	del_token_lst(void *content, size_t content_size)
{
	(void)content_size;
	ft_strdel(&((t_token*)(content))->value);
	free(content);
}

void	del_mx(t_machine *machine)
{
	size_t	i;

	i = 0;
	while (i < machine->map_height)
	{
		free(machine->mx[i]);
		i++;
	}
	free(machine->mx);
}
