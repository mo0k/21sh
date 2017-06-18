/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 20:43:29 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/17 22:51:37 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <history.h>

void		del_history_elem(void *content, size_t size)
{
	if (!content)
		return;
	(void)size;
	free(((t_history_elem*)(content))->val);
	((t_history_elem*)(content))->val = NULL;
	free(((t_history_elem*)(content))->save);
	((t_history_elem*)(content))->save = NULL;
	free(((t_history_elem*)(content)));
	content = NULL;
}