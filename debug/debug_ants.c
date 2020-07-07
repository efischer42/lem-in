/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:57:23 by efischer          #+#    #+#             */
/*   Updated: 2020/07/07 10:16:59 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	debug_ants(t_list *ant_lst)
{
	t_room	*path;
	char	*print;

	print = NULL;
	while (ant_lst != NULL)
	{
		path = ((t_ant*)(ant_lst->content))->path->content;
		print = ft_join_free(print, path->name, 1);
		print = ft_join_free(print, " ", 1);
		ant_lst = ant_lst->next;
	}
	ft_putendl(print);
	ft_strdel(&print);
}
