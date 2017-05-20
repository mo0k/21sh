/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 10:28:44 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/18 16:16:10 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <history.h>

int 	save_history(t_list *history)
{
	int 	fd;

	if (!history)
		return (0);
	if ((fd = open("/Users/jmoucade/.21sh_history", O_WRONLY | O_TRUNC | O_CREAT, 0600)) == -1)
	{
		ft_error("to save history");
		return (0);
	}
	while (history)
	{
		ft_putendl_fd(((t_history_elem*)(history->content))->save, fd);
		history = history->next;
	}
	close(fd);
	return (1);
}

