/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 10:13:08 by efischer          #+#    #+#             */
/*   Updated: 2020/07/07 10:13:47 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_STRUCT_H
# define LEMIN_STRUCT_H

typedef struct	s_token
{
	enum e_token	type;
	char			*value;
}				t_token;

typedef struct	s_room
{
	t_list			*next_rooms;
	char			*name;
	size_t			x;
	size_t			y;
	size_t			start_dist;
	enum e_link		link;
}				t_room;

typedef struct	s_path
{
	t_list	*lst;
	size_t	len;
	size_t	capacity;
	int		dead;
}				t_path;

typedef struct	s_paths_set
{
	t_list	*paths;
	size_t	nb_path;
	size_t	nb_turn;
	size_t	longest_len;
}				t_paths_set;

typedef struct	s_machine
{
	enum e_state	state;
	t_room			***room_mx;
	t_list			*token_lst;
	t_list			*last_token;
	t_list			*room_lst;
	t_list			*path_lst;
	t_paths_set		*path_set;
	t_room			*start;
	t_room			*end;
	size_t			ants;
	size_t			map_width;
	size_t			map_height;
	size_t			max_path_nb;
	size_t			nb_turn;
	char			*input;
}				t_machine;

typedef struct	s_ant
{
	t_list	*path;
	char	*id;
	int		done;
}				t_ant;

#endif
