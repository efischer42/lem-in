/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 19:44:30 by efischer          #+#    #+#             */
/*   Updated: 2020/06/08 14:48:19 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_STRUCT_H
# define LEM_IN_STRUCT_H

typedef struct	s_token
{
	enum e_token	type;
	char			*value;
}				t_token;

typedef struct	s_room
{
	t_list	*next_rooms;
	char	*name;
	size_t	x;
	size_t	y;
	int		ant;
}				t_room;

typedef	struct	s_next_room
{
	t_room	*room;
	int		link;
}				t_next_room;

typedef struct 	s_machine
{
	enum e_state	state;
	t_list			*token_lst;
	t_list			*last_token;
	t_list			*room_lst;
	t_list			*path_lst;
	t_room			*start;
	t_room			*end;
	t_room			***mx;
	size_t			ants;
	size_t			map_width;
	size_t			map_height;
	char			*input;
}				t_machine;

#endif
