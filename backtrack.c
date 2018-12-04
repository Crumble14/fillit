/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelondr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:29:10 by sbelondr          #+#    #+#             */
/*   Updated: 2018/12/04 17:48:55 by sbelondr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_init(size_t size_f)
{
	char	**init;
	char	*str;
	int		i;

	init = (char**)malloc(sizeof(char*) * size_f + 1);
	str = (char*)malloc(sizeof(char) * size_f + 1);
	if (init == NULL || str == NULL)
		exit(0);
	i = -1;
	while (++i < (int)size_f)
		str[i] = '.';
	str[i] = '\0';
	i = -1;
	while (++i < (int)size_f)
		init[i] = ft_strdup(str);
	init[++i] = 0;
	return (init);
}

int			ft_cnt_line(long piece, int line)
{
	int		max_line;
	int		cpt;
	char	*base;

	cpt = 0;
	max_line = line + 4;
	base = ft_convert_base((int)piece, 2);
	if (ft_strlen(base) < 16)
		base = ft_chrjoin_start('0', base);
	while (line < max_line)
		if (base[line++] == '1')
			cpt++;
	return (cpt);
}

int		ft_insert(char **result, long piece, int index, int index_line)
{
	int		i;
	int		j;
	int		line;
	char	*str;
	static int	letter;

	letter = (letter == 0) ? 'A': letter + 1;
	line = 0;
	j = -1;
	str = ft_convert_base(piece, 2);
	while (ft_strlen(str) < 16)
		str = ft_chrjoin_start('0', str);
	while (line < 16)
	{
		i = -1;
		while (++i < 4)
			if (str[++j] && str[j] != '0')
				result[index_line][index + i] = letter;
		index_line++;
		line += 4;
	}
	return (0);
}

int		ft_place(long piece, char **result)
{
	int		line;
	int		index;

	line = 0;
	index = -1;

	int		i = -1;
	while (result[++i])
		printf("%s\n", result[i]);
	printf("____________\n\n");
	if (result[line])
		ft_line_empty(result, piece);
	else
		exit(0);
	return (1);
}

char		**backtrack(const long *pieces, const size_t size)
{
	size_t	num;
	char	**result;
	int		i;

	i = -1;
	result = ft_init(size);
	num = -1;
	while (pieces[++num])// < size)
		ft_place(pieces[num], result);
	return (result);
}
