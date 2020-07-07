/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_capacity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 19:08:37 by efischer          #+#    #+#             */
/*   Updated: 2020/07/07 10:15:24 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	set_capacity(t_machine *machine, t_list *paths)
{
	t_list	*path_lst;
	size_t	diff;
	size_t	nb_paths;

	if (paths == NULL)
		return ;
	set_capacity(machine, paths->next);
	diff = 0;
	nb_paths = 1;
	path_lst = machine->path_set->paths;
	while (path_lst != NULL && path_lst != paths)
	{
		diff += ((t_path*)(paths->content))->len
			- ((t_path*)(path_lst->content))->len;
		path_lst = path_lst->next;
		nb_paths++;
	}
	if (diff < machine->ants)
	{
		if (machine->path_set->longest_len == 0)
			machine->path_set->longest_len = ((t_path*)(paths->content))->len;
		((t_path*)(paths->content))->capacity = (machine->ants - diff) / nb_paths
			+ machine->path_set->longest_len - ((t_path*)(paths->content))->len;
	}
//	ft_printf("ants: %d ", machine->ants);
//	ft_printf("longest len: %d ", machine->path_set->longest_len);
//	ft_printf("diff: %d\n", diff);
	machine->ants -= ((t_path*)(paths->content))->capacity;
//	ft_printf("capacity: %d\n", ((t_path*)(paths->content))->capacity);
}
