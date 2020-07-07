/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_enum.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 10:12:33 by efischer          #+#    #+#             */
/*   Updated: 2020/07/07 10:12:42 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_ENUM_H
# define LEMIN_ENUM_H

enum	e_state
{
	ST_GET_ANTS,
	ST_GET_ROOMS,
	ST_GET_PIPES
};

enum	e_token
{
	ROOM_START,
	ROOM_END,
	HYPHEN,
	START,
	END,
	NB,
	COORD_X,
	COORD_Y,
	ROOM_NAME,
	COMMENT
};

enum	e_link
{
	OFF,
	ON,
	DEAD
};

#endif
