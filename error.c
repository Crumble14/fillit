/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:16:52 by llenotre          #+#    #+#             */
/*   Updated: 2018/12/06 15:58:01 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_usage(void)
{
	ft_putstr("usage: fillit file\n");
	exit(0);
}

void	error(void)
{
	ft_putstr("error\n");
	exit(0);
}
