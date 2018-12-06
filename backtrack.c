/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelondr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:29:10 by sbelondr          #+#    #+#             */
/*   Updated: 2018/12/06 14:54:19 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		backtrack(char **grid, const size_t size, t_list *pieces)
{
	t_list	*p;
	t_pos	pos;

	p = pieces;
	if (p == NULL)
		return (1);
	pos.y = 0;
	while (pos.y < size)
	{
		pos.x = 0;
		while (pos.x < size)
		{
			if (can_place(p->content, grid, size, pos))
			{
				place(grid, pos, p->content, p->c);
				if (backtrack(grid, size, p->next))
					return (1);
				else
					place(grid, pos, p->content, VOID);
			}
			++pos.x;
		}
		++pos.y;
	}
	return (0);
}

char			**solve(t_list *pieces, const size_t size)
{
	char	**grid;

	if (!(grid = alloc_grid(size)))
		error();
	if (backtrack(grid, size, pieces))
		return (grid);
	else
	{
		free_grid(grid, size);
		return (NULL);
	}
}
