/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 11:49:52 by efischer          #+#    #+#             */
/*   Updated: 2020/06/16 16:01:40 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	solve(t_machine *machine)
{
	find_paths(machine, machine->start, NULL);
	get_paths(machine);
	debug_paths(machine);
	send_ants(machine);
}
