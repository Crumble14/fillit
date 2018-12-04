/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelondr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:29:10 by sbelondr          #+#    #+#             */
/*   Updated: 2018/12/04 14:12:06 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*alloc_grid(const size_t size)
{
	char	*grid;
	size_t	i;

	if (!(grid = (char*)malloc(sizeof(char) * (size * size))))
		return (NULL);
	i = 0;
	while (i < (size * size))
		grid[i++] = '.';
	return (grid);
}

/*int			ft_cnt_line(long piece)
{
	int		i;

	i = -1;
	while ((piece % 10))
		piece /= 10;
	return (ft_numlen((int)piece));
}

int			ft_line_empty(char *line, long piece)
{
	int		i;
	int		j;
	int		size;

	i = -1;
	size = ft_cnt_line(piece);
	while (line[++i])
	{
		j = 0;
		while (line[i + j] && line[i + j] == '.')
			j++;
		if (j >= size)
			break ;
		i += j;
	}
	if (j >= size)
		return (i);
	return (-1);
}

int			ft_place(long piece, long **result, size_t size_line)
{
	int		line;
	int		index;

	line = 0;
	index = -1;
	while (result[line] && (index = ft_line_empty(result[line], piece)) < 0)
		line++;
	if (index >= 0)
		ft_insert(result, piece, line, index);
	else
		return (0);
	return (1);
}*/

static int	get_location(const t_piece piece, const char *grid,
	size_t *x, size_t *y)
{
	(void)piece;
	(void)grid;
	(void)x;
	(void)y;
	// TODO
	return (0);
}

static int	place(const t_piece piece, char *grid,
	const size_t x, const size_t y)
{
	(void)piece;
	(void)grid;
	(void)x;
	(void)y;
	// TODO
	return (0);
}

static void	remove(const t_piece piece, char *grid,
	const size_t x, const size_t y)
{
	(void)piece;
	(void)grid;
	(void)x;
	(void)y;
	// TODO
}

static int	backtrack(char *grid, const size_t size, const t_list *pieces)
{
	size_t x;
	size_t y;

	if (!pieces)
		return (1);
	if (!get_location(*pieces->content, grid, &x, &y))
		return (0);
	while (pieces)
	{
		place(*pieces->content, grid, x, y);
		if (!backtrack(grid, size, pieces->next))
			remove(*pieces->content, grid, x, y);
		pieces = pieces->next;
	}
	return (1);
}

char		*solve(const t_list *pieces, const size_t size)
{
	char	*grid;

	if (!(grid = alloc_grid(size)))
		error(NULL);
	if (backtrack(grid, size, pieces))
		return (grid);
	else
	{
		free((void*)grid);
		return (NULL);
	}
}
