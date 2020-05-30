/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 14:21:02 by efischer          #+#    #+#             */
/*   Updated: 2020/05/30 14:45:09 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_STRUCT_H
# define LEM_IN_STRUCT_H

struct	s_room
{
	t_list	*next_rooms;
	char	*name;
	size_t	x;
	size_t	y;
	int		ant;
}		t_room;

struct 	s_machine
{
	enum e_state	state;
	t_list			*rooms;
	t_list			*paths;
	t_room			*start;
	t_room			*end;
	size_t			ants;
	char			*input;
}		t_machine;

#endif
