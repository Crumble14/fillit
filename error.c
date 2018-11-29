/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:16:52 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/29 16:47:03 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_usage()
{
	ft_putstr("usage: fillit file");
	exit(0);
}

void	error()
{
	ft_putstr("error");
	exit(0);
}
