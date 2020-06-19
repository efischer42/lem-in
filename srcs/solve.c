/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 11:49:52 by efischer          #+#    #+#             */
/*   Updated: 2020/06/18 15:03:45 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	get_max_path_nb(t_machine *machine)
{
	size_t	len;

	len = ft_lstlen(machine->start->next_rooms);
	machine->max_path_nb = len;
	len = ft_lstlen(machine->end->next_rooms);
	if (len < machine->max_path_nb)
		machine->max_path_nb = len;
	ft_printf("max path nb: %d\n", machine->max_path_nb);
}

void		solve(t_machine *machine)
{
	t_list	*path_lst;

	get_max_path_nb(machine);
	get_paths(machine);
	path_lst = machine->path_lst;
	while (path_lst != NULL)
	{
		debug_paths(path_lst->content);
		path_lst = path_lst->next;
	}
//	send_ants(machine);
}
