/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:25:57 by llenotre          #+#    #+#             */
/*   Updated: 2018/12/06 15:47:44 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		can_place(t_piece piece, char **grid, const size_t size,
	const t_pos pos)
{
	t_pos p;

	p.x = 0;
	p.y = 0;
	while (piece)
	{
		if ((piece & 32768)
			&& (pos.y + p.y >= size || pos.x + p.x >= size
				|| grid[pos.y + p.y][pos.x + p.x] != VOID))
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

int		find_hole(const t_piece piece, char **grid, const size_t size,
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

void	place(char **grid, const t_pos pos, t_piece piece,
	const char c)
{
	t_pos p;

	p.x = 0;
	p.y = 0;
	while (piece)
	{
		if (piece & 32768)
			grid[pos.y + p.y][pos.x + p.x] = c;
		piece <<= 1;
		++p.x;
		if (p.x >= PIECE_LENGTH)
		{
			p.x = 0;
			++p.y;
		}
	}
}
