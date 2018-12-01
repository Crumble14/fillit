/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:18:30 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/29 17:12:07 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define BUFF_SIZE		20
# define PIECE_LENGTH	4
# define PIECE_SIZE		16
# define MAX_PIECES		26
# define PIECE_BLOCKS	4

# define BLOCK			'#'
# define VOID			'.'

typedef unsigned short	t_piece;

typedef struct			s_list
{
	t_piece			*content;
	struct s_list	*next;
}						t_list;

t_list					*ft_lstnew(t_piece *piece);
void					ft_lstadd(t_list **list, t_list *new);
void					ft_lstdel(t_list **list);

void					ft_putstr(const char *str);
void					ft_putgrid(const char *grid);

void					print_usage(void);
void					error(void *ptr);

t_list					*read_file(const char *file);
int						check(t_list *pieces);

void					prepare(t_list *pieces);

char					*backtrack(const t_list *pieces, const size_t size);

#endif
