/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 19:44:01 by efischer          #+#    #+#             */
/*   Updated: 2020/06/22 17:09:05 by efischer         ###   ########.fr       */
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

void	add_to_bfs(t_machine *machine, t_list **bfs, t_room *room,
			size_t start_dist);
void	del_ant_lst(void *content, size_t content_size);
void	del_bfs(void *content, size_t content_size);
void	del_nomalloc_lst(void *content, size_t content_size);
void	del_path_lst(void *content, size_t content_size);
void	del_room_lst(void *content, size_t content_size);
void	del_room_mx(t_machine *machine);
void	del_token_lst(void *content, size_t content_size);
void	error(t_machine *machine, char *error_msg);
void	fill_mx_data(t_room ***mx, t_list *room_lst);
t_room	*find_room(t_list *room_lst, char *name);
t_room	*find_room_mx(t_room ***mx, t_room *room);
void	generate_mx(t_machine *machine, t_room ****mx);
int		get_a_path(t_machine *machine, t_list **bfs, t_path *path);
void	get_ants_nb(t_machine *machine);
void	get_rooms(t_machine *machine);
void	get_paths(t_machine *machine);
void	get_pipes(t_machine *machine);
void	get_word(t_machine *machine, t_token *token, size_t *pos);
void	lexer_parser(t_machine *machine);
void	lexer(t_machine *machine);
void	parser(t_machine *machine);
void	send_ants(t_machine *machine);
void	solve(t_machine *machine);
void	sort_ants(t_list **lst1, t_list **lst2, t_list **head);

void	debug(t_list *lst);
void	debug_ants(t_list *ant_lst);
void	debug_mx(t_machine *machine, t_room ***mx);
void	debug_paths(t_list *path_lst);
void	debug_rooms(t_machine *machine);

#endif
