/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 20:02:48 by efischer          #+#    #+#             */
/*   Updated: 2020/06/01 20:16:09 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void init_token_tab(char **token_tab)
{
	token_tab[ROOM_START] = "ROOM_START";
	token_tab[ROOM_END] = "ROOM_END";
	token_tab[HYPHEN] = "HYPHEN";
	token_tab[START] = "START";
	token_tab[END] = "END";
	token_tab[NB] = "NB";
	token_tab[COORD_X] = "COORD_X";
	token_tab[COORD_Y] = "COORD_Y";
	token_tab[ROOM_NAME] = "ROOM_NAME";
}

void		debug(t_list *lst)
{
	enum e_token	type;
	char			*token_tab[NB_TOKEN];
	char			*print;
	char			*value;

	init_token_tab(token_tab);
	while (lst != NULL)
	{
		print = NULL;
		value = NULL;
		type = ((t_token*)(lst->content))->type;
		if (type == NB || type == COORD_X || type == COORD_Y || type == ROOM_NAME)
			value = ((t_token*)(lst->content))->value;
		print = ft_asprintf("%s = [%s]\n", token_tab[type], value);
		ft_putstr_fd(print, 2);
		ft_strdel(&print);
		lst = lst->next;
	}
	ft_strdel(&print);
}
