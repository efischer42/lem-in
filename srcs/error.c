/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 18:58:12 by efischer          #+#    #+#             */
/*   Updated: 2020/06/19 16:55:25 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	error(t_machine *machine, char *error_msg)
{
	ft_putendl_fd(error_msg, 2);
	del_room_mx(machine);
	ft_strdel(&machine->input);
	ft_lstdel(&machine->token_lst, del_token_lst);
	ft_lstdel(&machine->path_lst, del_path_lst);
	ft_lstdel(&machine->room_lst, del_room_lst);
	exit(EXIT_FAILURE);
}
