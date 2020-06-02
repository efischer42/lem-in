/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 18:57:59 by efischer          #+#    #+#             */
/*   Updated: 2020/06/02 16:21:36 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		main(void)
{
	t_machine	machine;
	char		*line;
	int			ret;
	static void	(*fct[NB_FCT])(t_machine *) = {get_ants_nb, get_rooms,
							get_pipes};

	line = NULL;
	ft_bzero(&machine, sizeof(machine));
	while ((ret = get_next_line(STDIN_FILENO, &line)) > 0)
	{
		machine.input = line;
		fct[machine.state](&machine);
		ft_lstdel(&machine.token_lst, del_token_lst);
	}
	ft_lstdel(&machine.room_lst, del_room_lst);
	return (ret);
}
