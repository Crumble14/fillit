/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelondr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:29:10 by sbelondr          #+#    #+#             */
/*   Updated: 2018/11/29 17:38:39 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	free_grid(char **grid, const size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		free((void*)grid[i]);
		++i;
	}
	free((void*)grid);
}

static char	**alloc_grid(const size_t size)
{
	size_t	i;
	size_t	j;
	char	**grid;

	if (!(grid = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(grid[i] = (char*)malloc(sizeof(char) * (size + 1))))
		{
			free_grid(grid, i);
			return (NULL);
		}
		j = 0;
		while (j < size)
		{
			grid[i][j] = '.';
			++j;
		}
	}
	return (grid);
}


int			ft_cnt_line(long piece)
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
}

char		*backtrack(const t_list *pieces, const size_t size)
{
	size_t	num;
	char	**grid;

	if (!(grid = alloc_grid(size)))
		error();
	num = 0;
	//ft_place(pieces[num], &result, size);	
	return (NULL);	
}
