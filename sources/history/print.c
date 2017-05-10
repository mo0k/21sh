/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 10:28:44 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/06 23:20:38 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <history.h>

void	print_history_elem(t_list *elem)
{
	printf("%p\t%p\t%s\t%d\t%d\n", &((t_history_elem*)(elem->content))->value, ((t_history_elem*)(elem->content))->value, ((t_history_elem*)(elem->content))->value, ((t_history_elem*)(elem->content))->flag_new, ((t_history_elem*)(elem->content))->flag_modif);
}
