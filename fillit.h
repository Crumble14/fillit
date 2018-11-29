/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:18:30 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/29 15:37:57 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define PIECE_SIZE		20
# define PIECE			'#'
# define VOID			'.'

typedef unsigned short	t_piece;

void					ft_putstr(const char *str);

void					print_usage();
void					error();

t_piece					*read_file(const char *file);
void					prepare(const t_piece *pieces);
int						check(const t_list *pieces);

char					*backtrack(const t_piece *pieces, const size_t size);

#endif
