/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 18:58:22 by efischer          #+#    #+#             */
/*   Updated: 2020/06/02 12:55:43 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	get_ants_nb(t_machine *machine)
{
	t_list	*token_lst;

	ft_putendl_fd("Get ants", 2);
	lexer_parser(machine);
	token_lst = machine->token_lst;
	while (((t_token*)(token_lst->content))->type != END)
	{
		if (((t_token*)(token_lst->content))->type == NB)
		{
			if (machine->ants == 0)
				machine->ants = ft_atoi(((t_token*)(token_lst->content))->value);
			else
				error(machine, "Ants number redefined");
		}
		token_lst = token_lst->next;
	}
	if (machine->ants == 0)
		error(machine, "Ants number undefined or null");
	machine->state++;
}
