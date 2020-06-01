/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 18:58:30 by efischer          #+#    #+#             */
/*   Updated: 2020/06/01 20:47:54 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	get_nb(t_machine *machine, t_token *token, size_t *pos)
{
	size_t	i;

	i = 0;
	if (((t_token*)(machine->last_token->content))->type == ROOM_NAME)
		token->type = COORD_X;
	else if (((t_token*)(machine->last_token->content))->type == COORD_X)
		token->type = COORD_Y;
	else
		token->type = NB;
	while (ft_isdigit(machine->input[*pos + i]) == TRUE)
		i++;
	if (token->type == NB && (machine->input[*pos + i] == ' '
		|| machine->input[*pos + i] == '-'))
	{
		token->type = ROOM_NAME;
	}
	token->value = ft_strndup(machine->input + *pos, i);
	*pos += i;
}

static int	is_room_name(char c)
{
	if (c != '\0' && c != 'L' && c != '#' && ft_isblank(c) == FALSE)
		return (TRUE);
	return (FALSE);
}

void		get_word(t_machine *machine, t_token *token, size_t *pos)
{
	size_t		i;

	i = 0;
	if (ft_isdigit(machine->input[*pos]) == TRUE
		&& (((t_token*)(machine->last_token->content))->type == START
		|| ((t_token*)(machine->last_token->content))->type == ROOM_NAME
		|| ((t_token*)(machine->last_token->content))->type == COORD_X))
	{
		get_nb(machine, token, pos);
	}
	else if (is_room_name(machine->input[*pos]) == TRUE)
	{
		token->type = ROOM_NAME;
		while (is_room_name(machine->input[*pos + i]) == TRUE)
			i++;
		token->value = ft_strndup(machine->input + *pos, i);
		(*pos) += i;
	}
	else if (machine->input[*pos] == '#')
	{
		token->type = COMMENT;
		(*pos) += ft_strlen(machine->input + *pos);
	}
	else
		error(machine, "Parse error");
}
