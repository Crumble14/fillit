#include "fillit.h"

static inline int	has_x_void(const t_piece piece)
{
	return ((piece & 34952) == 0);
}

static inline int	has_y_void(const t_piece piece)
{
	return ((piece >> ((PIECE_LENGTH - 1) * PIECE_LENGTH)) == 0);
}

static inline void	move_left(const t_piece *piece)
{
	*piece =<< 1;
}

static inline void	move_up(const t_piece *piece)
{
	*piece =<< 4;
}

void				prepare(t_list *pieces)
{
	t_list *l;

	l = pieces;
	while(l)
	{
		while (has_x_void(*(l->content)))
			move_left(*(l->content));
		while (has_y_void(*(l->content)))
			move_up(*(l->content));
		l = l->next;
	}
}
