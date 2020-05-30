/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 13:36:24 by efischer          #+#    #+#             */
/*   Updated: 2020/05/30 13:50:23 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		main(void)
{
	char	*line;
	int		ret;

	line = NULL;
	while ((ret = get_next_line(STDIN_FILENO, &line)) > 0)
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
	return (ret);
}
