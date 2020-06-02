/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 19:44:01 by efischer          #+#    #+#             */
/*   Updated: 2020/06/02 16:24:04 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define TAB_END	-1
# define NB_FCT		3
# define NB_TOKEN	9

# include "libft.h"
# include "lem-in_enum.h"
# include "lem-in_struct.h"

void	del_room_lst(void *content, size_t content_size);
void	del_token_lst(void *content, size_t content_size);
void	error(t_machine *machine, char *error_msg);
void	get_ants_nb(t_machine *machine);
void	get_rooms(t_machine *machine);
void	get_pipes(t_machine *machine);
void	get_word(t_machine *machine, t_token *token, size_t *pos);
void	lexer_parser(t_machine *machine);
void	lexer(t_machine *machine);
void	parser(t_machine *machine);

void	debug(t_list *lst);

#endif
