/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:17:12 by llenotre          #+#    #+#             */
/*   Updated: 2018/12/06 15:47:43 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		open_file(const char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error();
	return (fd);
}

static size_t	ceil_sqrt(const size_t n)
{
	size_t i;

	i = 2;
	while (i * i < n)
		++i;
	return (i);
}

int				main(int argc, char **argv)
{
	t_list	*pieces;
	size_t	size;
	char	**grid;

	pieces = NULL;
	if (argc != 2)
		print_usage();
	if (!read_file(open_file(argv[1]), &pieces))
		error();
	if (!check(pieces))
		error();
	prepare(pieces);
	size = ceil_sqrt(ft_lstsize(pieces) * 4);
	while (!(grid = solve(pieces, size)))
		++size;
	ft_putgrid(grid, size);
	free_grid(grid, size);
	ft_lstdel(&pieces);
	return (0);
}
