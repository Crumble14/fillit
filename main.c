/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:17:12 by llenotre          #+#    #+#             */
/*   Updated: 2018/12/04 18:22:43 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*pieces;
	size_t	size;
	char	*grid;

	if (argc != 2)
		print_usage();
	if (!(pieces = read_file(argv[1])))
		error();
	if (!check(pieces))
		error();
	prepare(pieces);
	size = 2;
	while (!(grid = solve(pieces, size)))
		++size;
	ft_putgrid(grid, size);
	free((void*)grid);
	ft_lstdel(&pieces);
	return (0);
}
