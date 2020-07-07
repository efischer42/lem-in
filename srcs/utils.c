/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 20:34:53 by efischer          #+#    #+#             */
/*   Updated: 2020/07/07 10:15:33 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	*find_room_mx(t_room ***mx, t_room *room)
{
	return (mx[room->y][room->x]);
}

t_room	*find_room(t_list *room_lst, char *name)
{
	while (room_lst != NULL)
	{
		if (ft_strequ(((t_room*)(room_lst->content))->name, name) == TRUE)
			return (room_lst->content);
		room_lst = room_lst->next;
	}
	return (NULL);
}

void	sort_ants(t_list **lst1, t_list **lst2, t_list **head)
{
	if (((t_ant*)((*lst1)->content))->done == TRUE
		&& ((t_ant*)((*lst2)->content))->done == FALSE)
	{
		*head = *lst2;
		*lst2 = (*lst2)->next;
	}
	else
	{
		*head = *lst1;
		*lst1 = (*lst1)->next;
	}
}
