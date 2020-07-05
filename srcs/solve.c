/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 11:49:52 by efischer          #+#    #+#             */
/*   Updated: 2020/07/05 21:26:52 by efischer         ###   ########.fr       */
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
}

void		solve(t_machine *machine)
{
	size_t	ants;

//	ft_printf("nb ants: %d\n", machine->ants);
//	ft_printf("Start: %s\n", machine->start->name);
	get_max_path_nb(machine);
	get_paths(machine);
//	ft_printf("nb turn: %d\n", machine->path_set->nb_turn);
	ants = machine->ants;
	set_capacity(machine, machine->path_set->paths);
	machine->ants = ants;
	send_ants(machine);
}
