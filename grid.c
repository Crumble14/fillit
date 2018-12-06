/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:23:12 by llenotre          #+#    #+#             */
/*   Updated: 2018/12/06 14:23:49 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_grid(char **grid, const size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
		free((void*)grid[i++]);
	free((void*)grid);
}

char	**alloc_grid(const size_t size)
{
	char	**grid;
	size_t	i;
	size_t	j;

	if (!(grid = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(grid[i] = (char*)malloc(sizeof(char) * size)))
		{
			free_grid(grid, i);
			return (NULL);
		}
		j = 0;
		while (j < size)
			grid[i][j++] = VOID;
		++i;
	}
	return (grid);
}
