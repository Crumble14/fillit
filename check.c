/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:01:02 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/29 16:40:03 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static inline int	is_piece(const t_piece piece, const int x, const int y)
{
	return ((x >= 0 && y >= 0) && (piece >> (x + (y * PIECE_COUT))) & 1);
}

static int			check_count(const t_piece piece)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while (i < sizeof(t_piece) * 8)
	{
		if (i & 1)
			++count;
		if (count > PIECE_COUNT)
			return (0);
		i >>= 1;
	}
	return (count == PIECE_COUNT);
}

static int			check_piece(const t_piece piece)
{
	// TODO
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
