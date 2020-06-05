/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 18:58:49 by efischer          #+#    #+#             */
/*   Updated: 2020/06/05 14:52:23 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	lexer_parser(t_machine *machine)
{
	lexer(machine);
	debug(machine->token_lst);
	parser(machine);
	ft_strdel(&machine->input);
}
