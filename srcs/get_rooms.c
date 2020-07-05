/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 19:11:57 by efischer          #+#    #+#             */
/*   Updated: 2020/07/05 21:20:41 by efischer         ###   ########.fr       */
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

static void	room_data(t_machine *machine, t_room *new_room, t_token *token)
{
	if (token->type == ROOM_NAME)
		new_room->name = ft_strdup(token->value);
	else if (token->type == COORD_X)
	{
		new_room->x = ft_atoi(token->value);
		if (new_room->x + 1 > machine->map_width)
			machine->map_width = new_room->x + 1;
	}
	else if (token->type == COORD_Y)
	{
		new_room->y = ft_atoi(token->value);
		if (new_room->y + 1 > machine->map_height)
			machine->map_height = new_room->y + 1;
	}
	
}

static int	check_hyphen_token(t_machine *machine, t_room *new_room, t_token *token)
{
	if (token->type == HYPHEN)
	{
		if (machine->start == NULL)
			error(machine, "No room defined as start");
		if (machine->end == NULL)
			error(machine, "No room defined as end");
		ft_strdel(&new_room->name);
		machine->state++;
		generate_mx(machine, &machine->room_mx);
		fill_mx_data(machine->room_mx, machine->room_lst);
		get_pipes(machine);
		return (TRUE);
	}
	return (FALSE);
}

static void	add_new_room(t_machine *machine, t_room *new_room, int *start, int *end)
{
	t_list		*lst_new;

	check_new_room(machine, new_room);
	lst_new = ft_lstnew(new_room, sizeof(*new_room));
	if (lst_new == NULL)
		error(machine, "Cannot allocate memory");
	ft_lstaddend(&machine->room_lst, lst_new);
	if (*start == TRUE)
		machine->start = lst_new->content;
	else if (*end == TRUE)
		machine->end = lst_new->content;
	*start = FALSE;
	*end = FALSE;
}

void		get_rooms(t_machine *machine)
{
	static int	start = FALSE;
	static int	end = FALSE;
	t_list		*token_lst;
	t_room		new_room;

	ft_putendl(machine->input);
	ft_bzero(&new_room, sizeof(new_room));
	lexer_parser(machine);
	token_lst = machine->token_lst;
	while (((t_token*)(token_lst->content))->type != END)
	{
		if (check_hyphen_token(machine, &new_room, token_lst->content) == TRUE)
			break ;
		else if (((t_token*)(token_lst->content))->type == ROOM_START)
			start = TRUE;
		else if (((t_token*)(token_lst->content))->type == ROOM_END)
			end = TRUE;
		room_data(machine, &new_room, token_lst->content);
		token_lst = token_lst->next;
	}
	if (new_room.name != NULL && ((t_token*)(token_lst->content))->type == END)
		add_new_room(machine, &new_room, &start, &end);
}
