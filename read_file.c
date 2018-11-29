/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:27:43 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/29 15:38:05 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_piece *parse_piece(const int fd, const char *buffer, const size_t size)
{
	t_piece	*piece;
	size_t	i;

	piece = malloc(sizeof(piece));
	ft_bzero(piece, sizeof(piece));
	i = 0;
	while (i < size)
	{
		if (buffer[i] != PIECE && buffer[i] != VOID)
		{
			free(piece);
			error();
		}
		piece <<= 1;
		piece |= (buffer[i] == PIECE ? 1 : 0);
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

	fd = open(file);
	if (fd < 0)
		error();
	lst = 0;
	while ((len = read(fd, buffer, PIECE_SIZE)))
	{
		if (len != PIECE_SIZE)
		{
			ft_lstdel(lst);
			error();
		}
		ft_lstadd(ft_lstnew(parse_piece(buffer, size), sizeof(t_piece)));
		if (!read(fd, buffer, 1))
			break;
		if (*buff != '\n')
		{
			ft_lstdel(lst);
			error();
		}
	}
	return (lst);
}

void			prepare(const t_list *pieces)
{
	// TODO
}

int				check(const t_list* pieces)
{
	// TODO
}
