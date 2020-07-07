/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 18:57:59 by efischer          #+#    #+#             */
/*   Updated: 2020/07/07 10:15:10 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
		ft_putendl(line);
		machine.input = line;
		fct[machine.state](&machine);
		ft_lstdel(&machine.token_lst, del_token_lst);
	}
	if (machine.state != ST_GET_PIPES)
		error(&machine, "Too few informations");
	solve(&machine);
	del_room_mx(&machine);
	ft_lstdel(&machine.path_lst, del_path_lst);
	ft_lstdel(&machine.room_lst, del_room_lst);
	del_path_set(machine.path_set);
	return (ret);
}
