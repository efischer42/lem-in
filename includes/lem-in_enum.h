/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in_enum.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 18:59:22 by efischer          #+#    #+#             */
/*   Updated: 2020/06/08 15:12:56 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_ENUM_H
# define LEM_IN_ENUM_H

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
