/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:27:43 by llenotre          #+#    #+#             */
/*   Updated: 2018/12/04 18:22:29 by llenotre         ###   ########.fr       */
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

static t_piece	parse_piece(const char *buffer)
{
	t_piece	piece;
	size_t	i;

	piece = 0;
	i = 0;
	while (i < BUFF_SIZE)
	{
		if ((i + 1) % 5 != 0)
		{
			if (buffer[i] != BLOCK && buffer[i] != VOID)
				error();
			piece = piece << 1;
			piece |= (buffer[i] == BLOCK ? 1 : 0);
		}
		else if (buffer[i] != '\n')
			error();
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
	while ((len = read(fd, buffer, BUFF_SIZE)))
	{
		if (len != BUFF_SIZE)
		{
			ft_lstdel(&lst);
			error();
		}
		ft_lstpush(&lst, ft_lstnew(parse_piece(buffer)));
		if (!read(fd, buffer, 1))
			break ;
		if (*buffer != '\n')
		{
			ft_lstdel(&lst);
			error();
		}
	}
	close(fd);
	return (lst);
}
