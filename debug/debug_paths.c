/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:44:55 by efischer          #+#    #+#             */
/*   Updated: 2020/07/07 10:17:13 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	debug_paths(t_list *path_lst)
{
	t_list	*path;
	char	*print;

	print = NULL;
	ft_putendl("\nDebug paths\n");
	while (path_lst != NULL)
	{
		path = ((t_path*)(path_lst->content))->lst;
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
	print = ft_join_free(print, "\n", 1);
	ft_putstr(print);
	ft_strdel(&print);
}
