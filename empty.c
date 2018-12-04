/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelondr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:18:09 by sbelondr          #+#    #+#             */
/*   Updated: 2018/12/04 17:48:56 by sbelondr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_column_empty(char *line, int cnt_line)
{
	int	i;
	int	index;

	i = 0;
	while (line[i])
	{
		while (line[i] && line[i] != '.')
			i++;
		index = 0;
		while (line[i + index] && line[i + index] == '.')
			index++;
		if (index >= cnt_line)
			return (i);
		i += index;
	}
	return (-1);
}

void	ft_line_empty(char **result, long piece)
{
	int	i;
	int	line;
	int	cnt_line;
	int	index;
	int	index_line;

	i = -1;
	line = 0;
	index = -1;
	while (result[++i])
	{
		if ((cnt_line = ft_cnt_line(piece, line)) == 0)
			break ;
		if (index < 0)
		{
			index = ft_column_empty(result[i], cnt_line);
			index_line = i;
		}
		if (ft_column_empty(result[i], cnt_line) < cnt_line)
			line += 4;
	}
	ft_insert(result, piece, index, index_line);
	if (cnt_line == 0)
		return ;
	exit(0);
}
