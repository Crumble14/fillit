/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:01:02 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/29 16:46:48 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static inline int	is_piece(const t_piece piece, const int x, const int y)
{
	return ((x >= 0 && y >= 0) && (piece >> (x + (y * PIECE_COUNT))) & 1);
}

static int			check_count(t_piece piece)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while (i < sizeof(piece) * 8)
	{
		if (piece & 1)
			++count;
		if (count > PIECE_COUNT)
			return (0);
		piece >>= 1;
	}
	return (count == PIECE_COUNT);
}

static int			check_piece(const t_piece piece)
{
	(void)piece;
	is_piece(piece, 0, 0);
	// TODO

	return (0);
}

int					check(t_list *pieces)
{
	size_t count;

	count = 0;
	while (pieces)
	{
		++count;
		if (count > MAX_PIECES)
			return (0);
		if (!check_count(*pieces->content) || !check_piece(*pieces->content))
			return (0);
		pieces = pieces->next;
	}
	return (1);
}
