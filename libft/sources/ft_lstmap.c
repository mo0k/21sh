/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 00:40:50 by jmoucade          #+#    #+#             */
/*   Updated: 2017/01/24 11:01:12 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	begin = NULL;
	while (lst)
	{
		new = (*f)(lst);
		if (begin)
		{
			tmp->next = new;
			tmp = tmp->next;
		}
		else
		{
			begin = new;
			tmp = begin;
		}
		lst = lst->next;
	}
	return (begin);
}
