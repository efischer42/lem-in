/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 18:58:41 by efischer          #+#    #+#             */
/*   Updated: 2020/07/07 10:15:00 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	get_last_token(t_machine *machine)
{
	if (machine->last_token->next != NULL)
		machine->last_token = machine->last_token->next;
}

static void	init_grammar(char **grammar)
{
	grammar[ROOM_START] = "##start";
	grammar[ROOM_END] = "##end";
	grammar[HYPHEN] = "-";
	grammar[START] = NULL;
	grammar[END] = NULL;
	grammar[NB] = NULL;
	grammar[COORD_X] = NULL;
	grammar[COORD_Y] = NULL;
	grammar[ROOM_NAME] = NULL;
}

static void	init_token_lst(t_machine *machine, enum e_token type)
{
	t_token	token;
	t_list	*lst_new;

	ft_bzero(&token, sizeof(token));
	token.type = type;
	lst_new = ft_lstnew(&token, sizeof(token));
	if (lst_new == NULL)
		error(machine, "Malloc error");
	ft_lstaddend(&machine->token_lst, lst_new);
}

static void	get_next_token(t_machine *machine, t_token *token, size_t *pos)
{
	static char	*grammar[NB_TOKEN];
	size_t		len;
	size_t		i;

	i = 0;
	if (grammar[0] == NULL)
		init_grammar(grammar);
	while (i < NB_TOKEN)
	{
		len = ft_strlen(grammar[i]);
		if (ft_strnequ(machine->input + *pos, grammar[i], len) == TRUE)
		{
			token->type = i;
			(*pos) += len;
			break ;
		}
		i++;
	}
	if (i == NB_TOKEN)
		get_word(machine, token, pos);
}

void		lexer(t_machine *machine)
{
	t_token	token;
	t_list	*lst_new;
	size_t	pos;

	pos = 0;
	machine->token_lst = NULL;
	init_token_lst(machine, START);
	machine->last_token = machine->token_lst;
	while (machine->input[pos] != '\0')
	{
		get_last_token(machine);
		while (machine->input[pos] == ' ' || machine->input[pos] == '\t')
			pos++;
		ft_bzero(&token, sizeof(token));
		get_next_token(machine, &token, &pos);
		if (token.type != COMMENT)
		{
			lst_new = ft_lstnew(&token, sizeof(token));
			if (lst_new == NULL)
				error(machine, "Malloc error");
			ft_lstaddend(&machine->token_lst, lst_new);
		}
	}
	init_token_lst(machine, END);
}
