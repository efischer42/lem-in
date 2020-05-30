/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 13:36:24 by efischer          #+#    #+#             */
/*   Updated: 2020/05/30 14:44:48 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		main(void)
{
	t_machine	machine;
	char		*line;
	int			ret;
	static int	*(fct[NB_FCT](t_machine *machine)) = { get_ants_nb, get_rooms,
							get_pipes };

	line = NULL;
	ft_bzero(&machine, sizeof(machine));
	while ((ret = get_next_line(STDIN_FILENO, &line)) > 0)
	{
		machine.input = line;
		fct[&machine];
	}
	return (ret);
}
