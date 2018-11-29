/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:18:30 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/29 14:25:41 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef uint16_t	t_piece;

t_piece	*read_file(const char *file);
int		check(const t_piece *pieces);

char	*backtrack(const t_piece *pieces, const size_t size);

#endif
