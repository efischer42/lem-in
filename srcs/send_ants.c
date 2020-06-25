/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 17:11:48 by efischer          #+#    #+#             */
/*   Updated: 2020/06/25 11:53:05 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static t_list	*get_shortest_path(t_list *path_lst)
{
	t_list	*shortest_path;

	shortest_path = path_lst;
	while (path_lst != NULL)
	{
		if (((t_path*)(path_lst->content))->len < ((t_path*)(shortest_path->content))->len)
			shortest_path = path_lst;
		path_lst = path_lst->next;
	}
	return (shortest_path);
}

static void	new_ants(t_machine *machine, t_list **ant_lst, size_t *i)
{
	static t_list	*shortest_path = NULL;
	t_list			*path_lst;
	t_list			*lst_new;
	t_ant			ant;
	size_t			nb_turn;

	path_lst = machine->path_set->paths;
	if (shortest_path == NULL)
		shortest_path = get_shortest_path(path_lst);
	nb_turn = ((t_path*)(shortest_path->content))->len + machine->ants - *i;
	while (path_lst != NULL && (*i) <= machine->ants)
	{
		ft_bzero(&ant, sizeof(ant));
		if (nb_turn >= ((t_path*)(path_lst->content))->len
			|| path_lst == shortest_path)
		{
			ant.id = ft_join_free("L", ft_itoa(*i), 2);
			ant.path = ((t_path*)(path_lst->content))->lst->next;
			lst_new = ft_lstnew(&ant, sizeof(ant));
			ft_lstaddend(ant_lst, lst_new);
			(*i)++;
		}
		path_lst = path_lst->next;
	}
	ft_merge_sort(ant_lst, sort_ants);
}

static char	*get_print(t_list *ant_lst)
{
	t_list	*path;
	char	*print;

	print = NULL;
	while (ant_lst != NULL && ((t_ant*)(ant_lst->content))->done == FALSE)
	{
		path = ((t_ant*)(ant_lst->content))->path;
		print = ft_join_free(print, ((t_ant*)(ant_lst->content))->id, 1);
		print = ft_join_free(print, "-", 1);
		print = ft_join_free(print, ((t_room*)(path->content))->name, 1);
		ant_lst = ant_lst->next;
		if (ant_lst != NULL && ((t_ant*)(ant_lst->content))->done == FALSE)
			print = ft_join_free(print, " ", 1);
	}
	print = ft_join_free(print, "\n", 1);
	return (print);
}

static void	moove_ants(t_machine *machine, t_list **ant_lst)
{
	t_list	*head;

	head = *ant_lst;
	while (*ant_lst != NULL && ((t_ant*)((*ant_lst)->content))->done == FALSE)
	{
		if (((t_ant*)((*ant_lst)->content))->path->content == machine->end)
			((t_ant*)((*ant_lst)->content))->done = TRUE;
		else
			((t_ant*)((*ant_lst)->content))->path = ((t_ant*)((*ant_lst)->content))->path->next;
		*ant_lst = (*ant_lst)->next;
	}
	*ant_lst = head;
	ft_merge_sort(ant_lst, sort_ants);
}

void		send_ants(t_machine *machine)
{
	t_list	*ant_lst;
	char	*print;
	size_t	i;

	i = 1;
	print = NULL;
	ant_lst = NULL;
	while (i <= machine->ants)
	{
		new_ants(machine, &ant_lst, &i);
		print = ft_join_free(print, get_print(ant_lst), 3);
		moove_ants(machine, &ant_lst);
	}
	while (((t_ant*)(ant_lst->content))->done == FALSE)
	{
		print = ft_join_free(print, get_print(ant_lst), 3);
		moove_ants(machine, &ant_lst);
	}
	ft_putstr(print);
	ft_strdel(&print);
	ft_lstdel(&ant_lst, del_ant_lst);
}
