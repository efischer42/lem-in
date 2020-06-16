/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pipes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 19:13:09 by efischer          #+#    #+#             */
/*   Updated: 2020/06/16 15:26:34 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	reverse_link(t_machine *machine, t_room *first_room,
				t_room *last_room)
{
	t_room		*tmp;
	t_list		*new_lst;

	tmp = first_room;
	first_room = find_room(machine->room_lst, last_room->name);
	last_room = tmp;
	new_lst = ft_lstnewnomalloc(last_room, sizeof(*last_room));
	if (new_lst == NULL)
		error(machine, "Cannot allocate memory");
	ft_lstadd(&first_room->next_rooms, new_lst);
}

static void	link_rooms(t_machine *machine, t_token *token)
{
	static t_room	*first_room = NULL;
	t_room			*last_room;
	t_list			*new_lst;

	if (token->type == ROOM_NAME && first_room == NULL)
	{
		first_room = find_room(machine->room_lst, token->value);
		if (first_room == NULL)
			error(machine, "Trying to link undefined room");
	}
	else if (token->type == ROOM_NAME && first_room != NULL)
	{
		last_room = find_room(machine->room_lst, token->value);
		if (last_room == NULL)
			error(machine, "Trying to link undefined room");
		if (find_room(first_room->next_rooms, last_room->name) == NULL)
		{
			new_lst = ft_lstnewnomalloc(last_room, sizeof(*last_room));
			if (new_lst == NULL)
				error(machine, "Cannot allocate memory");
			ft_lstadd(&first_room->next_rooms, new_lst);
			reverse_link(machine, first_room, last_room);
		}
		first_room = NULL;
	}
}

void	get_pipes(t_machine *machine)
{
	t_list	*token_lst;

	if (machine->token_lst == NULL)
		lexer_parser(machine);
	token_lst = machine->token_lst;
	while (((t_token*)(token_lst->content))->type != END)
	{
		link_rooms(machine, token_lst->content);
		token_lst = token_lst->next;
	}
}
