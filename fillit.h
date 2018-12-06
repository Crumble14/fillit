/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:18:30 by llenotre          #+#    #+#             */
/*   Updated: 2018/12/06 14:28:57 by llenotre         ###   ########.fr       */
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
	t_piece			content;
	char			c;
	int				placed;
	struct s_list	*next;
}						t_list;

typedef struct			s_pos
{
	size_t x;
	size_t y;
}						t_pos;

t_list					*ft_lstnew(const t_piece piece, const char c);
void					ft_lstpush(t_list **list, t_list *new);
void					ft_lstdel(t_list **list);
size_t					ft_lstsize(const t_list *list);

void					ft_putstr(const char *str);
void					ft_putgrid(char **grid, const size_t size);

void					print_usage(void);
void					error(void);

t_list					*read_file(const char *file);
int						check(t_list *pieces);

void					prepare(t_list *pieces);

void					free_grid(char **grid, const size_t size);
char					**alloc_grid(const size_t size);


int						can_place(t_piece piece, char **grid,
	const size_t size, const t_pos pos);
int						find_hole(const t_piece piece, char **grid,
	const size_t size, t_pos *pos);
void					place(char **grid, const t_pos pos, t_piece piece,
	const char c);

char					**solve(t_list *pieces, const size_t size);

#endif
