/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 18:58:12 by efischer          #+#    #+#             */
/*   Updated: 2020/06/25 15:18:09 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	error(t_machine *machine, char *error_msg)
{
	ft_putendl_fd(error_msg, 2);
	ft_strdel(&machine->input);
	ft_lstdel(&machine->token_lst, del_token_lst);
	del_room_mx(machine);
	ft_lstdel(&machine->path_lst, del_path_lst);
	ft_lstdel(&machine->room_lst, del_room_lst);
	del_path_set(machine->path_set);
	exit(EXIT_FAILURE);
}
