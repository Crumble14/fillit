/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:01:02 by llenotre          #+#    #+#             */
/*   Updated: 2018/12/04 17:44:40 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_count(t_piece piece)
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

static int	count_blocks(t_piece piece, const size_t pos)
{
	size_t count;
	size_t i;

	if (!((piece >> pos) & 1))
		return (0);
	count = 1;
	piece &= ~(1 << pos);
	if (pos < (PIECE_SIZE - 1)
		&& (i = count_blocks(piece, pos + 1)))
		count += i;
	if (pos > 0
		&& (i = count_blocks(piece, pos - 1)))
		count += i;
	if (pos < (PIECE_SIZE - PIECE_LENGTH)
		&& (i = count_blocks(piece, pos + PIECE_LENGTH)))
		count += i;
	if (pos > PIECE_LENGTH
		&& (i = count_blocks(piece, pos - PIECE_LENGTH)))
		count += i;
	return (count);
}

static int	check_piece(const t_piece piece)
{
	size_t i;

	i = 0;
	while (i < sizeof(piece) * 8 && !((piece >> i) & 1))
		++i;
	return (count_blocks(piece, i) == PIECE_BLOCKS);
}

int			check(t_list *pieces)
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
