/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 13:36:33 by efischer          #+#    #+#             */
/*   Updated: 2020/05/30 14:45:55 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define NB_FCT	3

# include "libft.h"
# include "lem-in_enum.h"
# include "lem-in_struct.h"

void	error(t_machine *machine, char *error_msg);
void	get_ants_nb(t_machine *machine);
void	get_rooms(t_machine *machine);
void	get_pipes(t_machine *machine);

#endif
