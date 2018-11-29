/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:19:52 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/29 16:56:41 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while(str[i])
		++i;
	return (i);
}

void			ft_putstr(const char *str)
{
	write(1, str, ft_strlen(str));
}
