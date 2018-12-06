/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelondr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:29:10 by sbelondr          #+#    #+#             */
/*   Updated: 2018/12/06 13:40:19 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static void		free_grid(char **grid, const size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
		free((void*)grid[i++]);
	free((void*)grid);
}

static char		**alloc_grid(const size_t size)
{
	char	**grid;
	size_t	i;
	size_t	j;

	if (!(grid = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(grid[i] = (char*)malloc(sizeof(char) * size)))
		{
			free_grid(grid, i);
			return (NULL);
		}
		j = 0;
		while (j < size)
			grid[i][j++] = VOID;
		++i;
	}
	return (grid);
}

static int		can_place(t_piece piece, char **grid, const size_t size,
	const t_pos pos)
{
	t_pos p;

	p.x = 0;
	p.y = 0;
	while (piece)
	{
		if ((piece & 32768)
			&& (grid[pos.x + p.x][pos.y + p.y] != VOID
				|| pos.x + p.x >= size || pos.y + p.y >= size))
			return (0);
		piece <<= 1;
		++p.x;
		if (p.x >= PIECE_LENGTH)
		{
			p.x = 0;
			++p.y;
		}
	}
	return (1);
}

static int		find_hole(const t_piece piece, char **grid, const size_t size,
	t_pos *pos)
{
	pos->x = 0;
	while (pos->x < size)
	{
		pos->y = 0;
		while (pos->y < size)
		{
			if (can_place(piece, grid, size, *pos))
				return (1);
			++pos->y;
		}
		++pos->x;
	}
	return (0);
}

static void		place(char **grid, const t_pos pos, t_piece piece,
	const char c)
{
	t_pos p;

	p.x = 0;
	p.y = 0;
	while (piece)
	{
		if (piece & 32768)
			grid[pos.x + p.x][pos.y + p.y] = c;
		piece <<= 1;
		++p.x;
		if (p.x >= PIECE_LENGTH)
		{
			p.x = 0;
			++p.y;
		}
	}
}

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
			ft_putgrid(grid, size);
			printf("\n");
			if (backtrack(grid, size, p))
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
