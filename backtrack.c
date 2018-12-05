/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelondr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:29:10 by sbelondr          #+#    #+#             */
/*   Updated: 2018/12/05 18:55:16 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static char		*alloc_grid(const size_t size)
{
	char	*grid;
	size_t	i;

	if (!(grid = (char*)malloc(sizeof(char) * (size * size))))
		return (NULL);
	i = 0;
	while (i < (size * size))
		grid[i++] = VOID;
	return (grid);
}

static int		can_place(t_piece piece, char *grid, const size_t size,
	const size_t pos)
{
	size_t offset;
	size_t i;
	size_t j;

	offset = size - PIECE_LENGTH;
	i = 0;
	j = 0;
	while (piece)
	{
		if (pos + i + j >= size * size)
			return (0);
		if ((piece & (1 << 15))
			&& ((pos + (i % PIECE_SIZE) > (pos / size + 1) * size)
			|| grid[pos + i + j] != VOID))
			return (0);
		piece <<= 1;
		if ((i + 1) % PIECE_LENGTH == 0)
			j += offset;
		++i;
	}
	return (1);
}

static int		find_hole(const t_piece piece, char *grid, const size_t size,
	size_t *pos)
{
	size_t i;

	i = 0;
	while (i < (size * size))
	{
		if (can_place(piece, grid, size, i))
		{
			*pos = i;
			return (1);
		}
		++i;
	}
	return (0);
}

static void		place(char *grid, const size_t size, const size_t pos,
	t_piece piece, const char c)
{
	size_t offset;
	size_t i;
	size_t j;

	offset = size - PIECE_LENGTH;
	i = 0;
	j = 0;
	while (piece)
	{
		if (piece & (1 << 15))
			grid[pos + i + j] = c;
		piece <<= 1;
		if ((i + 1) % PIECE_LENGTH == 0)
			j += offset;
		++i;
	}
}

static int		backtrack(t_list *pieces, char *grid, const size_t size)
{
	t_list	*p;
	size_t	pos;

	p = pieces;
	while (p)
	{
		if (!p->placed)
		{
			if (!find_hole(p->content, grid, size, &pos))
				return (0);
			place(grid, size, pos, p->content, p->c);
			p->placed = 1;
			ft_putgrid(grid, size);
			printf("\n");
			if (backtrack(p, grid, size))
				return (1);
			else
			{
				place(grid, size, pos, p->content, VOID);
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

char			*solve(t_list *pieces, const size_t size)
{
	char	*grid;
	t_list	*p;

	if (!(grid = alloc_grid(size)))
		error();
	p = pieces;
	while (p)
	{
		p->placed = 0;
		p = p->next;
	}
	if (backtrack(pieces, grid, size))
		return (grid);
	else
	{
		free((void*)grid);
		return (NULL);
	}
}
