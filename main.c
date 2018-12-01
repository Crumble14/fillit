/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:17:12 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/29 17:05:02 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_list	*pieces;
	size_t	size;
	char	*grid;

	if (argc != 2)
		print_usage();
	pieces = read_file(argv[1]);
	if (!check(pieces))
		error();
	prepare(pieces);
	size = 2;
	while (!(grid = backtrack(pieces, size)))
		++size;
	ft_putgrid(grid);
	return (0);
}
