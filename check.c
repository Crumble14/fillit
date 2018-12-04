/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:01:02 by llenotre          #+#    #+#             */
/*   Updated: 2018/12/04 15:16:04 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static inline int	is_block(const t_piece piece, const size_t pos)
{
	return ((piece >> pos) & 1);
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
		if (count > PIECE_BLOCKS)
			return (0);
		piece >>= 1;
		++i;
	}
	return (count == PIECE_BLOCKS);
}

static int			check_piece(const t_piece piece)
{
	size_t i;

	i = 0;
	while (i < sizeof(piece) * 8)
	{
		if ((piece >> i) & 1)
			if (!is_block(piece, i + 1) && !is_block(piece, i - 1)
				&& !is_block(piece, i + 4) && !is_block(piece, i - 4))
				return (0);
		++i;
	}
	return (1);
}

int					check(t_list *pieces)
{
	size_t count;

	count = 0;
	while (pieces)
	{
		++count;
		if (count > MAX_PIECES || !check_count(*pieces->content)
			|| !check_piece(*pieces->content))
			return (0);
		pieces = pieces->next;
	}
	return (1);
}
