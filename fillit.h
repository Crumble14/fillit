/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:18:30 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/29 16:15:43 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define PIECE_SIZE		20
# define MAX_PIECES		26
# define PIECE_COUNT	4

# define PIECE			'#'
# define VOID			'.'

typedef unsigned short	t_piece;

typedef struct			s_list
{
	t_piece *content;
	s_list	*next;
}						t_list;

t_list					*ft_lstnew(t_piece *piece);
void					ft_lstadd(t_list **list);
void					ft_lstdel(t_list **list);

void					ft_putstr(const char *str);

void					print_usage();
void					error();

t_piece					*read_file(const char *file);
int						check(t_list *pieces);

void					prepare(t_piece *pieces);

char					*backtrack(const t_piece *pieces, const size_t size);

#endif
