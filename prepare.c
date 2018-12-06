/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:49:36 by llenotre          #+#    #+#             */
/*   Updated: 2018/12/06 15:47:45 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static inline int	has_x_void(const t_piece piece)
{
	return ((piece & 34952) == 0);
}

static inline int	has_y_void(const t_piece piece)
{
	return ((piece >> ((PIECE_LENGTH - 1) * PIECE_LENGTH)) == 0);
}

static inline void	move_left(t_piece *piece)
{
	*piece <<= 1;
}

static inline void	move_up(t_piece *piece)
{
	*piece <<= 4;
}

void				prepare(t_list *pieces)
{
	t_list *l;

	l = pieces;
	while (l)
	{
		while (has_x_void(l->content))
			move_left(&l->content);
		while (has_y_void(l->content))
			move_up(&l->content);
		l = l->next;
	}
}
