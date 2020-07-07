/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 11:48:45 by efischer          #+#    #+#             */
/*   Updated: 2020/07/07 11:50:33 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	add_path_to_lst(t_machine *machine, t_list **lst, t_path *path)
{
	t_list	*lst_new;
	size_t	shortest_len;
	size_t	res;

	path->len = ft_lstlen(path->lst);
	lst_new = ft_lstnew(path, sizeof(*path));
	if (lst_new == NULL)
		error(machine, "Cannot allocate memory");
	if ((*lst) == NULL)
		shortest_len = path->len;
	else
		shortest_len = ((t_path*)((*lst)->content))->len;
	res = (float)machine->ants / (float)(ft_lstlen(*lst) + 1) + shortest_len
		- 2 + path->len - shortest_len;
	if (machine->nb_turn == 0 || res < machine->nb_turn)
		machine->nb_turn = res;
	ft_lstaddend(lst, lst_new);
}

static int	check_new_path(t_path *path, int *dead)
{
	if (path->dead == TRUE)
	{
		*dead = TRUE;
		ft_lstdel(&path->lst, del_nomalloc_lst);
		path->lst = NULL;
	}
	if (path->lst == NULL)
	{
		ft_lstdel(&path->lst, del_nomalloc_lst);
		return (FALSE);
	}
	return (TRUE);
}

int			get_paths_set(t_machine *machine, t_list **lst)
{
	t_list		*bfs;
	t_path		path;
	int			dead;
	size_t		i;

	i = 0;
	bfs = NULL;
	dead = FALSE;
	while (i < machine->max_path_nb)
	{
		add_to_bfs(machine, &bfs, machine->start, 1);
		ft_bzero(&path, sizeof(path));
		get_a_path(machine, &bfs, &path);
		if (check_new_path(&path, &dead) == FALSE)
			break ;
		add_path_to_lst(machine, lst, &path);
		ft_lstdel(&bfs, del_bfs);
		i++;
	}
	ft_lstdel(&bfs, del_bfs);
	return (dead);
}
