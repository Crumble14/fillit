/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:42:19 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/29 15:52:03 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*ft_lstnew(t_piece *piece)
{
	t_list *list;

	if (!(list = malloc(sizeof(t_list))))
		return (NULL);
	list->piece = piece;
	list->next = NULL;
	return (list);
}

void	ft_lstadd(t_list **list, t_list *new)
{
	t_list *l;

	if (list == NULL || *new == NULL)
		return ;
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	l = *list;
	*list = new;
	(*list)->next = l;
}

void	ft_lstdel(t_list **list)
{
	t_list *l;
	t_list *next;

	l = *list;
	while (l)
	{
		free((void*)l->content);
		next = l->next;
		free((void*)l);
		l = next;
	}
	*list = NULL;
}
