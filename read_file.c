/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:27:43 by llenotre          #+#    #+#             */
/*   Updated: 2018/12/06 15:47:46 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static inline void	err(t_list **lst)
{
	ft_lstdel(lst);
	error();
}

static t_piece		parse_piece(const char *buffer)
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

int					read_file(const int fd, t_list **lst)
{
	char	buffer[BUFF_SIZE];
	int		len;
	char	c;
	int		end;

	c = 'A';
	end = 0;
	while ((len = read(fd, buffer, BUFF_SIZE)))
	{
		if (len != BUFF_SIZE)
			err(lst);
		ft_lstpush(lst, ft_lstnew(parse_piece(buffer), c++));
		if (!read(fd, buffer, 1))
		{
			end = 1;
			break ;
		}
		if (*buffer != '\n')
			err(lst);
	}
	if (!end)
		err(lst);
	close(fd);
	return (lst != NULL);
}
