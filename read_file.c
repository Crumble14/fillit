/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:27:43 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/29 16:56:27 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	 	open_file(const char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error();
	return (fd);
}

static t_piece *parse_piece(const char *buffer)
{
	t_piece	*piece;
	size_t	i;

	if (!(piece = malloc(sizeof(piece))))
		error();
	*piece = 0;
	i = 0;
	while (i < PIECE_SIZE)
	{
		if (i % 4 != 0)
		{
			if (buffer[i] != PIECE && buffer[i] != VOID)
			{
				free(piece);
				error();
			}
			*piece <<= 1;
			*piece |= (buffer[i] == PIECE ? 1 : 0);
		}
		else if (buffer[i] != '\n')
		{
			free(piece);
			error();
		}
		++i;
	}
	return (piece);
}

t_list			*read_file(const char *file)
{
	int		fd;
	char	buffer[PIECE_SIZE];
	int		len;
	t_list	*lst;

	fd = open_file(file);
	lst = NULL;
	while ((len = read(fd, buffer, PIECE_SIZE)))
	{
		if (len != PIECE_SIZE)
		{
			ft_lstdel(&lst);
			error();
		}
		ft_lstadd(&lst, ft_lstnew(parse_piece(buffer)));
		if (!read(fd, buffer, 1))
			break;
		if (*buffer != '\n')
		{
			ft_lstdel(&lst);
			error();
		}
	}
	close(fd);
	return (lst);
}
