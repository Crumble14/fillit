/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:19:52 by llenotre          #+#    #+#             */
/*   Updated: 2018/12/04 18:25:49 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

static inline void	ft_putchar(const char c)
{
	write(1, &c, sizeof(c));
}

void				ft_putstr(const char *str)
{
	write(1, str, ft_strlen(str));
}

void				ft_putgrid(const char *grid, const size_t size)
{
	size_t i;

	i = 0;
	while (i < (size * size))
	{
		write(1, grid + i, size);
		i += size;
		ft_putchar('\n');
	}
}
