/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 19:11:57 by efischer          #+#    #+#             */
/*   Updated: 2020/06/02 15:02:45 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	check_new_room(t_machine *machine, t_room *new_room)
{
	t_list	*room_lst;

	room_lst = machine->room_lst;
	while (room_lst != NULL)
	{
		if (ft_strequ(new_room->name, ((t_room*)(room_lst->content))->name))
			error(machine, "Room name already exists");
		else if (new_room->x == ((t_room*)(room_lst->content))->x
			&& new_room->y == ((t_room*)(room_lst->content))->y)
		{
			error(machine, "Room redefined");
		}
		room_lst = room_lst->next;
	}
}

static void	room_data(t_room *new_room, t_token *token)
{
	if (token->type == ROOM_NAME)
		new_room->name = ft_strdup(token->value);
	else if (token->type == COORD_X)
		new_room->x = ft_atoi(token->value);
	else if (token->type == COORD_Y)
		new_room->y = ft_atoi(token->value);
}

void		get_rooms(t_machine *machine)
{
	t_list	*token_lst;
	t_list	*lst_new;
	t_room	new_room;

	ft_putendl_fd("Get rooms", 2);
	ft_bzero(&new_room, sizeof(new_room));
	lexer_parser(machine);
	token_lst = machine->token_lst;
	while (((t_token*)(token_lst->content))->type != END)
	{
		if (((t_token*)(token_lst->content))->type == HYPHEN)
		{
			ft_strdel(&new_room.name);
			machine->state++;
			get_pipes(machine);
			break ;
		}
		room_data(&new_room, token_lst->content);
		token_lst = token_lst->next;
	}
	if (new_room.name != NULL && ((t_token*)(token_lst->content))->type == END)
	{
		check_new_room(machine, &new_room);
		lst_new = ft_lstnew(&new_room, sizeof(new_room));
		if (lst_new == NULL)
			error(machine, "Cannot allocate memory");
		ft_lstadd(&machine->room_lst, lst_new);
	}
}
