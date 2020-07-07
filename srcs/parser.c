/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 18:57:48 by efischer          #+#    #+#             */
/*   Updated: 2020/07/07 10:38:10 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	init_enum_tab2(enum e_token **enum_tab)
{
	static enum e_token	token_coord_x[] = {COORD_Y, TAB_END};
	static enum e_token	token_coord_y[] = {END, TAB_END};
	static enum e_token	token_name[] = {COORD_X, HYPHEN, END, TAB_END};

	enum_tab[COORD_X] = token_coord_x;
	enum_tab[COORD_Y] = token_coord_y;
	enum_tab[ROOM_NAME] = token_name;
}

static void	init_enum_tab1(enum e_token **enum_tab)
{
	static enum e_token	token_command[] = {END, TAB_END};
	static enum e_token	token_hyphen[] = {ROOM_NAME, TAB_END};
	static enum e_token	token_start[] = {NB, ROOM_NAME, ROOM_START, ROOM_END,
											END, TAB_END};
	static enum e_token	token_nb[] = {END, TAB_END};

	enum_tab[ROOM_START] = token_command;
	enum_tab[ROOM_END] = token_command;
	enum_tab[HYPHEN] = token_hyphen;
	enum_tab[START] = token_start;
	enum_tab[END] = NULL;
	enum_tab[NB] = token_nb;
}

static int	check_tokens(enum e_token *enum_tab, enum e_token type)
{
	size_t	i;
	int		ret;

	i = 0;
	ret = FALSE;
	while (enum_tab[i] != (enum e_token)TAB_END)
	{
		if (enum_tab[i] == type)
		{
			ret = TRUE;
			break ;
		}
		i++;
	}
	return (ret);
}

void		parser(t_machine *machine)
{
	static enum e_token	*enum_tab[NB_TOKEN] = {NULL};
	enum e_token		last_type;
	t_list				*token_lst;

	token_lst = machine->token_lst;
	if (enum_tab[0] == NULL)
	{
		init_enum_tab1(enum_tab);
		init_enum_tab2(enum_tab);
	}
	while (((t_token*)(token_lst->content))->type != END)
	{
		last_type = ((t_token*)(token_lst->content))->type;
		token_lst = token_lst->next;
		if (check_tokens(enum_tab[last_type],
			((t_token*)(token_lst->content))->type) == FALSE)
		{
			error(machine, "Parse error");
		}
	}
}
