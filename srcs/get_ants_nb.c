/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 18:58:22 by efischer          #+#    #+#             */
/*   Updated: 2020/06/01 20:37:17 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	get_ants_nb(t_machine *machine)
{
	ft_putendl_fd("Get ants", 2);
	lexer_parser(machine);
	ft_lstdel(&machine->token_lst, del_token_lst);
}
