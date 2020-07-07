/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 18:58:49 by efischer          #+#    #+#             */
/*   Updated: 2020/07/07 10:15:05 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	lexer_parser(t_machine *machine)
{
	lexer(machine);
	parser(machine);
	ft_strdel(&machine->input);
}
