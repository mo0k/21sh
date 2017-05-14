/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:44:06 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/04 23:42:40 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

void		ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list	*prev;
	t_list	*cur;

	prev = NULL;
	cur = *alst;
	if (!new)
		return ;
	//printf("IN ft_lstadd_end : new:%p, new->content:%p, new->size:%zu\n", new, new->content, new->content_size);
	if (!*alst)
	{
		ft_lstadd_start(alst, new);
		return ;
	}
	while (cur)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = new;
	new->prev = prev;
	new->next = NULL;
}
