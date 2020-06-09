/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:44:55 by efischer          #+#    #+#             */
/*   Updated: 2020/06/09 16:01:40 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	debug_paths(t_machine *machine)
{
	t_list	*path_lst;
	t_list	*path;
	char	*print;

	print = NULL;
	path_lst = machine->path_lst;
	ft_putendl("\nDebug paths\n");
	while (path_lst != NULL)
	{
		path = path_lst->content;
		while (path != NULL)
		{
			print = ft_join_free(print, ((t_room*)(path->content))->name, 1);
			path = path->next;
			if (path != NULL)
				print = ft_join_free(print, "-", 1);
		}
		print = ft_join_free(print, "\n", 1);
		path_lst = path_lst->next;
	}
	ft_putstr(print);
	ft_strdel(&print);
}
