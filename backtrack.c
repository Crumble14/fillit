/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelondr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:29:10 by sbelondr          #+#    #+#             */
/*   Updated: 2018/12/06 14:33:24 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		backtrack(char **grid, const size_t size, t_list *pieces)
{
	t_list	*p;
	t_pos	pos;

	p = pieces;
	while (p)
	{
		if (!p->placed)
		{
			if (!find_hole(p->content, grid, size, &pos))
				return (0);
			place(grid, pos, p->content, p->c);
			p->placed = 1;
			if (backtrack(grid, size, pieces))
				return (1);
			else
			{
				place(grid, pos, p->content, VOID);
				p->placed = 0;
			}
		}
		p = p->next;
	}
	p = pieces;
	while (p)
	{
		if (!p->placed)
			return (0);
		p = p->next;
	}
	return (1);
}

char			**solve(t_list *pieces, const size_t size)
{
	char	**grid;
	t_list	*p;

	if (!(grid = alloc_grid(size)))
		error();
	p = pieces;
	while (p)
	{
		p->placed = 0;
		p = p->next;
	}
	if (backtrack(grid, size, pieces))
		return (grid);
	else
	{
		free_grid(grid, size);
		return (NULL);
	}
}
