/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 18:58:49 by efischer          #+#    #+#             */
/*   Updated: 2020/06/03 21:15:01 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	lexer_parser(t_machine *machine)
{
	lexer(machine);
	parser(machine);
	ft_strdel(&machine->input);
}
