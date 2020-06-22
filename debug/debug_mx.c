/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_mx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:03:35 by efischer          #+#    #+#             */
/*   Updated: 2020/06/22 17:21:22 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	debug_mx(t_machine *machine, t_room ***mx)
{
	char	*print;
	size_t	y;
	size_t	x;

	y = 0;
	print = NULL;
	ft_putendl("\nDebug mx\n");
	while (y < machine->map_height)
	{
		x = 0;
		while (x < machine->map_width)
		{
			print = ft_join_free(print, ft_asprintf("%-*s", 5, mx[y][x]->name), 3);
			x++;
			if (x < machine->map_width)
				print = ft_join_free(print, " ", 1);
		}
		print = ft_join_free(print, "\n", 1);
		y++;
	}
	ft_putstr(print);
	ft_strdel(&print);
}
