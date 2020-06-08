/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 11:49:52 by efischer          #+#    #+#             */
/*   Updated: 2020/06/08 17:58:37 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	solve(t_machine *machine)
{
	debug_rooms(machine);
	ft_putendl(machine->start->name);
	find_paths(machine, machine->start, NULL);
	get_paths(machine);
}
