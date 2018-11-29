/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelondr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:29:10 by sbelondr          #+#    #+#             */
/*   Updated: 2018/11/29 16:53:36 by sbelondr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_init(size_t size)
{
	size_t	i;
	int		j;
	char	**init;

	if (!(init = (char**)malloc(sizeof(char*) * size + 1)))
		return (NULL);
	i = -1;
	while (++i < size)
		init[i] = (char*)malloc(sizeof(char) * size + 1);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (init[i][++j])
			init[i][j] = '.';
	}
	init[i] = 0;
	return (init);
}


int			ft_cnt_line(long piece)
{
	int		i;

	i = -1;
	while ((piece % 10))
		piece /= 10;
	return (ft_numlen((int)piece));
}

int			ft_line_empty(char *line, long piece)
{
	int		i;
	int		j;
	int		size;

	i = -1;
	size = ft_cnt_line(piece);
	while (line[++i])
	{
		j = 0;
		while (line[i + j] && line[i + j] == '.')
			j++;
		if (j >= size)
			break ;
		i += j;
	}
	if (j >= size)
		return (i);
	return (-1);
}

int		ft_place(long piece, long **result, size_t size_line)
{
	int		line;
	int		index;

	line = 0;
	index = -1;
	while (result[line] && (index = ft_line_empty(result[line], piece)) < 0)
		line++;
	if (index >= 0)
		ft_insert(result, piece, line, index);
	else
		return (0);
	return (1);
}

char		*backtrack(const t_piece *pieces, const size_t size)
{
	size_t	num;
	char	**result;

	(void)pieces;
	(void)size;
	if ((result = ft_init(size)) == 0)
		return (NULL);
	num = 0;
	//ft_place(pieces[num], &result, size);	
	return (NULL);	
}
