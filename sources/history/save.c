/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 10:28:44 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/06 23:20:39 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <history.h>

int 	save_history(t_list *history)
{
	int 	fd;

	if (!history)
		return (0);
	if ((fd = open("/Users/mo0ky/.21sh_history", O_WRONLY | O_TRUNC | O_CREAT, 0600)) == -1)
		return (0);
	while (history)
	{
		ft_putendl_fd(((t_history_elem*)(history->content))->save, fd);
		history = history->next;
	}
	close(fd);
	return (1);
}

